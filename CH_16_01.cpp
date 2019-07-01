#include "mbed.h"
#include "mRotaryEncoder.h"

DigitalOut LED(LED1);			// 내장 LED
// 로터리 인코더 (A핀(CLK), B핀(DT), SW핀)
mRotaryEncoder encoder(D2, D3, D4);

void blink() {				// 버튼이 눌러진 경우 콜백 함수
	LED = !LED;				// LED 반전
}

void rotate() {				// 축이 회전한 경우 콜백 함수
	printf("%d\n", encoder.Get());
}

int main() {
	LED = 0;					// LED는 꺼진 상태로 시작
	encoder.attachSW(&blink);		// 버튼이 눌러진 경우의 콜백 함수 등록
	encoder.attachROT(&rotate);		// 축이 회전한 경우의 콜백 함수 등록
	
	while(1) {
	}
}