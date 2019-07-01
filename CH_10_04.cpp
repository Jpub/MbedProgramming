#include "mbed.h"

InterruptIn btn(USER_BUTTON);		// 내장 버튼
DigitalOut LED(LED1);			// 내장 LED

void blink(void) {				// 하강 에지에서의 콜백 함수
	LED = !LED;
}

int main() {
	LED = false;				// LED는 꺼진 상태에서 시작
	
	btn.fall(&blink);			// 하강 에지에서의 콜백 함수 등록
	
	while(1) {
	}
}