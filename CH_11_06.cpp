#include "mbed.h"

DigitalOut LED_1(D2), LED_2(D3);
volatile bool state1, state2;		// LED 상태
Ticker t1, t2;

void blink1(void) {
	state1 = !state1;			// LED 1 상태 반전
}

void blink2(void) {
	state2 = !state2;			// LED 2 상태 반전
}

int main() {
	state1 = false;				// 꺼진 상태에서 시작
	state2 = false;
	
	LED_1 = state1;
	LED_2 = state2;
	
	t1.attach(blink1, 0.5);			// 콜백 함수 등록
	t2.attach(blink2, 1);
	
	while(1) {
		LED_1 = state1;			// LED 상태 출력
		LED_2 = state2;
	}
}