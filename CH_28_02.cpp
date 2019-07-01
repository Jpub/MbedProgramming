#include "mbed.h"

DigitalOut myled(LED1);			// LED 연결 핀을 출력으로 사용

int main() {
	while(1) {
		myled = 1;				// LED 연결 핀에 HIGH 출력
		wait(0.2); 				// 0.2초 대기
		myled = 0; 				// LED 연결 핀에 LOW 출력
		wait(1.0); 				// 1초 대기
	}
}