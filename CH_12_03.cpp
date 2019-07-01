#include "mbed.h"
#include "Adafruit_SSD1306.h"

SPI mySPI(D11, D12, D13);		// (MOSI, MISO, SCK)
// (SPI, data/command, reset, slave select, height, width)
Adafruit_SSD1306_Spi OLED(mySPI, D3, D2, D4, 64, 128);

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

	OLED.display(); 			// 버퍼 내용을 OLED로 출력
	
	while(1) {
	}
}