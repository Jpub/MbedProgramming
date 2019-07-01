#include "mbed.h"
#include "Adafruit_SSD1306.h"

I2C myI2C(D14, D15);			// (SDA, SCL)
//(I2C, reset, I2C Address, height, width)
Adafruit_SSD1306_I2c OLED(myI2C, D2, 0x78, 64, 128);

int main() {
	OLED.clearDisplay();			// 화면 지우기

	for (int i = 1; i < 8; i++) {
		OLED.drawCircle(32, 32, i * 3, WHITE);
		if (i % 2 == 0) {
			OLED.fillCircle(96, 32, 32 - i * 3, BLACK);
		}
		else {
			OLED.fillCircle(96, 32, 32 - i * 3, WHITE);
		}
	}

	OLED.display();				// 버퍼 내용을 디스플레이에 출력
	
	while(1) {
	}
}