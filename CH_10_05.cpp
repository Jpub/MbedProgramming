#include "mbed.h"

DigitalOut LED_1(D2);
DigitalOut LED_2(D3);
InterruptIn btn_1(D4);			// 풀업 저항을 사용한 버튼
InterruptIn btn_2(D5);			// 풀다운 저항을 사용한 버튼

void blink1(void) {			// 하강 에지에서의 콜백 함수
	LED_1 = !LED_1;
}

void blink2(void) {			// 하강 에지에서의 콜백 함수
	LED_2 = !LED_2;
}

int main() {
	LED_1 = 0;
	LED_2 = 0;

	btn_1.mode(PullUp);
	btn_2.mode(PullDown);
	
	btn_1.fall(blink1);
	btn_2.rise(blink2);
	
	while(1) {
	}
}