#include "mbed.h"

DigitalOut LED(LED1);
Ticker t;

void blink(void) {				// 0.5초 간격 블링크를 위한 콜백 함수
	LED = !LED;
}

int main() {
	LED = false;				// LED는 꺼진 상태에서 시작
	
	t.attach(blink, 0.5);			// 콜백 함수 등록
	
	while(1) {
	}
}