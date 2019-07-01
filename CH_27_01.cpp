#include "mbed.h"

DigitalOut led1(D2), led2(D3);
Thread thread;				// 쓰레드 객체 생성

void led2_thread() {			// 1초 간격으로 LED2 점멸
	while (true) {				// LED2 쓰레드의 무한 루프
		led2 = !led2;
		wait(1);
	}
}

int main() {					// 0.5초 간격으로 LED1 점멸
	thread.start(led2_thread);		// LED2 쓰레드 시작
	
	while (true) {				// LED1을 위한 main 쓰레드의 무한 루프
		led1 = !led1;
		wait(0.5);
	}
}