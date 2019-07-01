#include "mbed.h"
#include "rtos.h"

DigitalOut led(D2);

void led_thread() {			// LED 쓰레드 함수
	while (true) {
		// LED 쓰레드의 플래그 비트가 설정될 때까지 대기
		// 처리 후에는 플래그 비트가 자동으로 클리어 됨
		Thread::signal_wait(0x1);
		led = !led;				// LED 반전
	}
}

int main (void) {
	Thread thread;			// LED 쓰레드
	
	thread.start(led_thread);		// LED 쓰레드 시작

	while (true) {
		Thread::wait(500);			// 0.5초 대기
		// LED 쓰레드로 플래그를 설정하는 시그널 전송
		thread.signal_set(0x1);
	}
}