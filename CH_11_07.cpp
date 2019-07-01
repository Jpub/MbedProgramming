#include "mbed.h"

Timeout flipper;
DigitalOut LED_1(D2);
DigitalOut LED_2(D3);

void flip() {
	LED_2 = !LED_2;			// LED 2 반전. 한 번만 실행됨
}

int main() {
	LED_2 = 1;				// LED 2 켜기
	flipper.attach(flip, 2.0); 		// 2초 후 콜백 함수 호출

	while(1) {					// 0.5초 간격으로 LED 1 반전
		LED_1 = !LED_1;
		wait(0.5);
	}
}