#include "mbed.h"

PwmOut pwm1(D2), pwm2(D3);

int main() {
	pwm1.write(0);				// LED 끄기
	pwm2.write(1);				// LED 켜기
	
	while(1) {
		for(float i = 0; i < 1.0; i+= 0.05){	// 듀티 사이클 변화
			pwm1.write(i);
			pwm2.write(1 - i);
			
			wait(0.1);
		}
	}
}