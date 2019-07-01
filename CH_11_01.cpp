#include "mbed.h"

DigitalOut myLED(LED1);


int main() {
	bool state = true; 			// LED 상태
	while(1) {
		myLED = state; 			// LED에 상태 표시
		state = !state; 			// LED 상태 반전

		wait(1);
	}
}