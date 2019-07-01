#include "mbed.h"

Serial PC(USBTX, USBRX);
DigitalOut LED(LED1);

void blink_callback() {
	PC.putc(PC.getc());			// 데이터가 수신된 경우 되돌려 보냄
}

int main() {
	PC.attach(&blink_callback);		// 콜백 함수 등록
	
	while(1) {					// 1초 간격으로 LED 점멸
		LED = !LED;
		wait(1);
	}
}