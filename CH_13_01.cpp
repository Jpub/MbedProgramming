#include "mbed.h"
#include "Adafruit_SSD1306.h"

I2C myI2C(D14, D15);			// (SDA, SCL)
//(I2C, reset, I2C Address, height, width)
Adafruit_SSD1306_I2c OLED(myI2C, D2, 0x78, 64, 128);

void OLED_drawString(char *str) {	// 문자열 출력 함수
	for(int i = 0; str[i]; i++){
		OLED.writeChar(str[i]);
	}
}

int main() {
	OLED.clearDisplay();			// 화면 지우기

	OLED.setTextSize(1);			// 폰트 크기 설정
	OLED_drawString("Hello~");		// 문자열 출력
	
	OLED.setTextSize(2);
	OLED.setTextCursor(0, 10);		// 출력 위치 변경
	OLED_drawString("Hello~");
	
	OLED.setTextSize(3);
	OLED.setTextCursor(0, 30);
	OLED_drawString("Hello~");

	OLED.display();				// 버퍼 내용을 OLED로 출력
	
	while(1) {
	}
}