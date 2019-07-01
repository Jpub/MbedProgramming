#include "mbed.h"
#include "TextLCD.h"

I2C myI2C(D14, D15);			// (SDA, SCL)
TextLCD_I2C myLCD(&myI2C, 0x7E);	// (I2C 객체 포인터, I2C Address)

int main() {
	myLCD.setBacklight(TextLCD::LightOn);	// 백라이크 켜기
	// 커서를 표시하지 않으며 꺼서 깜빡임도 없앰
	myLCD.setCursor(TextLCD::CurOff_BlkOff);
	
	myLCD.printf("Hello World!");		// 문자열 출력
	
	while(1) {
	}
}