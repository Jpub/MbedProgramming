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
	ENA.write(0); 				// 정지 상태

	forward();					// 정방향 회전
	for(float f = 0.0; f <= 1.0; f += 0.01){	// 속도 증가
		ENA.write(f);
		wait(0.05);
	}
	
	wait(1);
	stop();							// 모터 정지
	
	backward();				// 역방향 회전
	for(float f = 0.0; f <= 1.0; f += 0.01){	// 속도 증가
		ENA.write(f);
		wait(0.05);
	}
	
	wait(1);
	stop();							// 모터 정지

	while(1){
	}
}