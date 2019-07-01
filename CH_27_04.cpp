#include "mbed.h"

DigitalOut led1(D2), led2(D3);

void led_thread() {			// LED 쓰레드 함수
	while (true) {
		// 2개의 시그널 중 하나라도 전달되기를 대기
		osEvent evt = Thread::signal_wait(0x03);

		if(evt.value.signals & 0x01){		// LED1 시그널인 경우
			led1 = !led1;
		}
		if(evt.value.signals & 0x02){		// LED2 시그널인 경우
			led2 = !led2;
		}
	}
}

int main (void) {
	Thread thread;
	
	led1 = true;				// LED1 초기 상태
	led2 = false;				// LED2 초기 상태
	
	thread.start(led_thread);		// LED 쓰레드 시작

	while (true) {
		Thread::wait(500);
		thread.signal_set(0x1);		// LED1 시그널
		thread.signal_set(0x2);		// LED2 시그널
	}
}