#include "mbed.h"

PwmOut ENA(D2);
DigitalOut IN1(D3), IN2(D4);

void forward() {				// 정회전, 표 2 참조
	IN1 = false;
	IN2 = true;
}

void backward() {			// 역회전, 표 2 참조
	IN1 = true;
	IN2 = false; 
}

void stop(){					// 정지, 표 2 참조
	IN1 = false;
	IN2 = false;
}

int main() {
	ENA.write(1); 				// 제어 가능한 상태로 둠

	forward();					// 정회전
	wait(2);
	backward();				// 역회전
	wait(2);
	stop();							// 정지

	while(1){
	}
}