#include "mbed.h"

DigitalOut led1(D2), led2(D3);

void led_thread1() {			// LED1 쓰레드 함수
	while (true) {
		Thread::signal_wait(0x1);
		led1 = !led1;				// LED 반전
	}
}

void led_thread2() {			// LED2 쓰레드 함수
	while (true) {
		Thread::signal_wait(0x1);
		led2 = !led2;				// LED 반전
	}
}

int main (void) {
	Thread thread1, thread2;
	
	led1 = true;				// LED1 초기 상태
	led2 = false;				// LED2 초기 상태
	
	thread1.start(led_thread1);		// LED1 쓰레드 시작
	thread2.start(led_thread2);		// LED2 쓰레드 시작

	while (true) {				// 두 개의 쓰레드로 시그널 전송
		Thread::wait(500);
		thread1.signal_set(0x1);
		thread2.signal_set(0x1);
	}
}