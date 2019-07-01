#include "mbed.h"
#include "TextLCD.h"

I2C myI2C(D14, D15);			// (SDA, SCL)
TextLCD_I2C myLCD(&myI2C, 0x7E); 	// (I2C 객체 포인터, I2C Address)

int main() {
	myLCD.setBacklight(TextLCD::LightOn);
	myLCD.setCursor(TextLCD::CurOff_BlkOff);

	// 라이브러리에 미리 정의되어 있는 사용자 정의 문자 등록
	myLCD.setUDC(0, (char *)udc_Bat_Hi);	// Battery Full
	myLCD.setUDC(1, (char *)udc_Bat_Ha);	// Battery Half
	myLCD.setUDC(2, (char *)udc_Bat_Lo);	// Battery Low
	myLCD.setUDC(3, (char *)udc_AC); 	// AC Power
	
	myLCD.putc(0);			// 현재 위치에 사용자 정의 문자 출력
	myLCD.putc(1);
	myLCD.putc(2);
	myLCD.putc(3);
	
	while(1) {
	}
}