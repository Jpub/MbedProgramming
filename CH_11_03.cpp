#include "mbed.h"

DigitalOut LED_1(D2), LED_2(D3);
Timer t1, t2;

int main() {
	t1.start();					// 타이머 1 시작
	t2.start();					// 타이머 2 시작
	
	while(1) {
		if(t1.read() >= 0.5) {			// 0.5초 경과
			LED_1 = !LED_1;			// LED 1 반전
			t1.reset();				// 타이머 1 초기화
		}
		
		if(t2.read() >= 1) {			// 1초 경과
			LED_2 = !LED_2;			// LED 2 반전
			t2.reset();				// 타이머 2 초기화
		}
	}
}