/*
* lcd_shield.c 
* NOTE: Please also check the comments in lcd_shield.h - they provide useful hints
* and background information.
*/
#define FONT_SIZE 8; // pixels

#include "lcd_shield.h"
#include "SmartFareData.h"



//Auxiliary variables
char string[16];
static unsigned int lcd_last_userID;
static int lcd_balance;
static unsigned int travel_fare;

void set_lcd_last_userID(unsigned int userID){
	lcd_last_userID = userID;
}

void set_lcd_balance(int balance){
	lcd_balance = balance;
}

void set_lcd_travel_fare(int fare){
	travel_fare = fare;
}

void board_lcd_init(){
	//set up the LCD screen
	Board_LCD_Init(); /* Pin Mux and Clock initialization */
	LCD_Init(); /* Initialize LCD Device and Turn it ON */
	LCD_SetFontColor(1);
	LCD_SetFontBgColor(0); /* Background is OFF */
	LCD_SetFont(&font_rom8x8); /* Use 8x8 Fonts */
}


/**
 * show a message for each situation
 */
void change_lcd_message(int message_code) {

	Board_LCD_Init();
	LCD_Init();
	int i, j;

	// clear LCD
	for (i = 0; i < LCD_X_RES; i++) {
		for (j = 0; j < LCD_Y_RES; j++) {
			LCD_SetPixel(i, j, 0); // 0 is color
		}
	}
	LCD_Refresh(0, 0, LCD_X_RES - 1, LCD_Y_RES - 1);

	switch (message_code) {

	case START_MESSAGE:
		write_lcd_text(1, "Bem Vindo!");
		write_lcd_text(3, "Passe o cartao");
		sprintf(string, "  ");
		write_lcd_text(4, string);
		break;

	case USTATUS_UNAUTHORIZED:
		write_lcd_text(2, "Cartao ja usado");
		write_lcd_text(3, "na entrada");
		sprintf(string, "  ");
		write_lcd_text(4, string);
		break;

	case USTATUS_INSUF_BALANCE:
		write_lcd_text(2, "Saldo insufic.");
		print_balance(3, lcd_balance);
		sprintf(string, "Saldo_min: %d", MIN_BALANCE);
		write_lcd_text(4, string);
		break;

	case USTATUS_AUTHORIZED:
		write_lcd_text(1, "Boa Viagem!");
		print_balance(3, lcd_balance);
		break;

	case USTATUS_TAP_OUT:
		print_travel_fare(2, travel_fare);
		print_balance(4, lcd_balance);
		sprintf(string, "  ");
		write_lcd_text(5, string);
		break;

	case USTATUS_TAP_OUT_LOW_BALANCE:
		sprintf(string, "Tarifa: %d", travel_fare);
		write_lcd_text(2, string);
		print_balance(3, lcd_balance);
		sprintf(string, "  ");
		write_lcd_text(4, string);
		break;
	}
}

void print_balance(uint8_t line, int balance) {
	if (balance < 0) {
		sprintf(string, "Saldo: -%d,%.2d", 0-balance/100, 0-balance%100);
	} else {
		sprintf(string, "Saldo: %d,%.2d", balance/100,balance%100);
	}

	write_lcd_text(line, string);
}

void print_travel_fare(uint8_t line, int fare){
		if (fare < 0) {
		sprintf(string, "Tarifa: -%d,%.2d", 0-fare/100, 0-fare%100);
	} else {
		sprintf(string, "Tarifa: %d,%.2d", fare/100,fare%100);
	}

	write_lcd_text(line, string);
}

void print_read_user_ID() {
	sprintf(string, "ID do usuario:");
	write_lcd_text(0, string);
	sprintf(string, "%u", lcd_last_userID);
	write_lcd_text(1, string);
}

// size (128x64)
void write_lcd_text(int line, char *text) {

	int line_size = FONT_SIZE;
	line_size += 2;
	int number_lines = LCD_Y_RES / line_size;
	if (line < number_lines) {
		LCD_PutStrXY(0, line * line_size, text);
	}
}
