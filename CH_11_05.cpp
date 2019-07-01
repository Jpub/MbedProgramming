#include "mbed.h"

DigitalOut LED_1(D2), LED_2(D3);
Ticker t1, t2;

void blink1(void) {			// 0.5초 간격 블링크를 위한 콜백 함수
	LED_1 = !LED_1;
}

void blink2(void) {			// 1초 간격 블링크를 위한 콜백 함수
	LED_2 = !LED_2;
}

int main() {
	LED_1 = false;				// LED는 꺼진 상태에서 시작
	LED_2 = false;
	
	t1.attach(blink1, 0.5);			// 콜백 함수 등록
	t2.attach(blink2, 1);
	
	while(1) {
	}
}