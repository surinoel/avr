#include <avr/io.h>
#define F_CPU 16000000UL
#include <util/delay.h>
#include <avr/interrupt.h>

// commands
#define LCD_CLEARDISPLAY 0x01
#define LCD_RETURNHOME 0x02
#define LCD_ENTRYMODESET 0x04
#define LCD_DISPLAYCONTROL 0x08
#define LCD_CURSORSHIFT 0x10
#define LCD_FUNCTIONSET 0x20
#define LCD_SETCGRAMADDR 0x40
#define LCD_SETDDRAMADDR 0x80

// flags for display entry mode
#define LCD_ENTRYRIGHT 0x00
#define LCD_ENTRYLEFT 0x02
#define LCD_ENTRYSHIFTINCREMENT 0x01
#define LCD_ENTRYSHIFTDECREMENT 0x00

// flags for display on/off control
#define LCD_DISPLAYON 0x04
#define LCD_DISPLAYOFF 0x00
#define LCD_CURSORON 0x02
#define LCD_CURSOROFF 0x00
#define LCD_BLINKON 0x01
#define LCD_BLINKOFF 0x00

// flags for display/cursor shift
#define LCD_DISPLAYMOVE 0x08
#define LCD_CURSORMOVE 0x00
#define LCD_MOVERIGHT 0x04
#define LCD_MOVELEFT 0x00

// flags for function set
#define LCD_8BITMODE 0x10
#define LCD_4BITMODE 0x00
#define LCD_2LINE 0x08
#define LCD_1LINE 0x00
#define LCD_5x10DOTS 0x04
#define LCD_5x8DOTS 0x00

// flags for backlight control
#define LCD_BACKLIGHT 0x08
#define LCD_NOBACKLIGHT 0x00

#define En 0B00000100  // Enable bit
#define Rw 0B00000010  // Read/Write bit
#define Rs 0B00000001  // Register select bi

#define delay _delay_ms
#define delayMicroseconds _delay_us
int  _addr = 0x20;
int _cols, _rows, _charsize = 0;
int _backlightval = LCD_BACKLIGHT;
char _displayfunction, _displaycontrol, _displaymode;

void LCD_i2C_init(int addr, int col, int row)
{
    _addr = addr;
	_cols = col;
	_rows = row;
	_backlightval = LCD_BACKLIGHT;
}
void pulseEnable(uint8_t _data){
	expanderWrite(_data | En);	// En high
	delayMicroseconds(1);		// enable pulse must be >450ns
	
	expanderWrite(_data & ~En);	// En low
	delayMicroseconds(50);		// commands need > 37us to settle
}
// write either command or data
void send(uint8_t value, uint8_t mode) {
	uint8_t highnib=value&0xf0;
	uint8_t lownib=(value<<4)&0xf0;
	write4bits((highnib)|mode);
	write4bits((lownib)|mode); 
}

void write4bits(uint8_t value) {
	expanderWrite(value);
	pulseEnable(value);
}

void expanderWrite(uint8_t _data){                                        
	Wire_beginTransmission(_addr);
	Wire_write((int)(_data) | _backlightval);
	Wire_endTransmission();   
}

// Turn the display on/off (quickly)
void noDisplay() {
	_displaycontrol &= ~LCD_DISPLAYON;
	command(LCD_DISPLAYCONTROL | _displaycontrol);
}
void display() {
	_displaycontrol |= LCD_DISPLAYON;
	command(LCD_DISPLAYCONTROL | _displaycontrol);
}

// Turns the underline cursor on/off
void noCursor() {
	_displaycontrol &= ~LCD_CURSORON;
	command(LCD_DISPLAYCONTROL | _displaycontrol);
}
void cursor() {
	_displaycontrol |= LCD_CURSORON;
	command(LCD_DISPLAYCONTROL | _displaycontrol);
}
void clear(){
	command(LCD_CLEARDISPLAY);// clear display, set cursor position to zero
	delayMicroseconds(2000);  // this command takes a long time!
}
#define LiquidCrystal_I2C::

void home(){
	command(LCD_RETURNHOME);  // set cursor position to zero
	delayMicroseconds(2000);  // this command takes a long time!
}

void setCursor(uint8_t col, uint8_t row){
	int row_offsets[] = { 0x00, 0x40, 0x14, 0x54 };
	if (row > _rows) {
		row = _rows-1;    // we count rows starting w/0
	}
	command(LCD_SETDDRAMADDR | (col + row_offsets[row]));
}

void noBacklight(void) {
	_backlightval=LCD_NOBACKLIGHT;
	expanderWrite(0);
}

void backlight(void) {
	_backlightval=LCD_BACKLIGHT;
	expanderWrite(0);
}

void LiquidCrystal_I2C_begin() {
	Wire_begin();
	_displayfunction = LCD_4BITMODE | LCD_1LINE | LCD_5x8DOTS;

	if (_rows > 1) {
		_displayfunction |= LCD_2LINE;
	}

	// for some 1 line displays you can select a 10 pixel high font
	if ((_charsize != 0) && (_rows == 1)) {
		_displayfunction |= LCD_5x10DOTS;
	}

	// SEE PAGE 45/46 FOR INITIALIZATION SPECIFICATION!
	// according to datasheet, we need at least 40ms after power rises above 2.7V
	// before sending commands. Arduino can turn on way befer 4.5V so we'll wait 50
	delay(50); 

	// Now we pull both RS and R/W low to begin commands
	expanderWrite(_backlightval);	// reset expanderand turn backlight off (Bit 8 =1)
	delay(1000);

	// put the LCD into 4 bit mode
	// this is according to the hitachi HD44780 datasheet
	// figure 24, pg 46

	// we start in 8bit mode, try to set 4 bit mode
	write4bits(0x03 << 4);
	delayMicroseconds(4500); // wait min 4.1ms

	// second try
	write4bits(0x03 << 4);
	delayMicroseconds(4500); // wait min 4.1ms

	// third go!
	write4bits(0x03 << 4); 
	delayMicroseconds(150);

	// finally, set to 4-bit interface
	write4bits(0x02 << 4); 

	// set # lines, font size, etc.
	command(LCD_FUNCTIONSET | _displayfunction);  
	
	// turn the display on with no cursor or blinking default
	_displaycontrol = LCD_DISPLAYON | LCD_CURSOROFF | LCD_BLINKOFF;
	display();
	
	// clear it off
	clear();
	
	// Initialize to default text direction (for roman languages)
	_displaymode = LCD_ENTRYLEFT | LCD_ENTRYSHIFTDECREMENT;
	
	// set the entry mode
	command(LCD_ENTRYMODESET | _displaymode);
	
	home();
}
/*********** mid level commands, for sending data/cmds */

inline void command(uint8_t value) {
	send(value, 0);
}

inline int write(uint8_t value) {
	send(value, Rs);
}
void LCD_sendStr(char *p)
{
    while(*p) write(*p++);
}
main()
{
	char buf[40];
	char cnt = 0;
	DDRA = 0xff;
	PORTA = 1;
	sei();
	LCD_i2C_init(0x27, 16, 2);
	PORTA = 2;
    LiquidCrystal_I2C_begin();
	PORTA = 3;

	PORTA = 4;
	backlight();
	while(1)
	{

	setCursor(0,0);
	sprintf(buf,"Welcome to EHolic!");
	LCD_sendStr(buf);
	setCursor(0,1);
	sprintf(buf,"<<< %03d >>> !!", cnt ++);
	LCD_sendStr(buf);

	}
}
