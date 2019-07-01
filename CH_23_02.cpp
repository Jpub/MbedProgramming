#include "mbed.h"
#include "TextLCD.h"

// (RS, E, DB4, DB5, DB6, DB7)
TextLCD myLCD(D7, D6, D5, D4, D3, D2);

int main() {
	myLCD.setBacklight(TextLCD::LightOn);	// 백라이트 켜기
	// 커서를 표시하지 않으며 꺼서 깜빡임도 없앰
	myLCD.setCursor(TextLCD::CurOff_BlkOff);

	myLCD.locate(0, 0);
	myLCD.putc('0');
	
	myLCD.locate(6, 0);
	myLCD.putc('1');
	
	myLCD.locate(1, 1);
	myLCD.putc('2');
	
	myLCD.locate(7, 1);
	myLCD.putc('3');
	
	while(1) {
	}
}