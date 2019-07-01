#include "mbed.h"
#include "TextLCD.h"

// (RS, E, DB4, DB5, DB6, DB7, TYPE)
TextLCD myLCD(D7, D6, D5, D4, D3, D2, TextLCD::LCD20x4);

int main() {
	myLCD.setBacklight(TextLCD::LightOn);	// 백라이트 켜기
	// 커서를 표시하지 않으며 꺼서 깜빡임도 없앰
	myLCD.setCursor(TextLCD::CurOff_BlkOff);

	for(int i = 0; i < 4; i++){
		myLCD.locate(i, i);
		for(int j = 0; j < 10; j++){
			myLCD.putc(j + '0');
		}
	}
	
	while(1){
	}
}