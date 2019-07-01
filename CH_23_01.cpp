#include "mbed.h"
#include "TextLCD.h"

// (RS, E, DB4, DB5, DB6, DB7)
TextLCD myLCD(D7, D6, D5, D4, D3, D2);

int main() {
	myLCD.setBacklight(TextLCD::LightOn);	// 백라이트 켜기
	// 커서를 표시하지 않으며 꺼서 깜빡임도 없앰
	myLCD.setCursor(TextLCD::CurOff_BlkOff);
	
	int index = 0;
	for(int i = 0; i < 16; i++){
		myLCD.putc(index + '0');
		myLCD.printf("%d", index);
		
		index = (index + 1) % 10;		// 0~9 반복
	}
	myLCD.printf("**");
	
	while(1) {
	}
}