#include "mbed.h"

PwmOut ENA(D2);
DigitalOut IN1(D3), IN2(D4);
DigitalIn btn(D5);

bool direction = true;			// 정회전으로 시작

void forward() {				// 정회전, 표 2 참조
    IN1 = false;
    IN2 = true;
}

void backward() {			// 역회전, 표 2 참조
    IN1 = true;
    IN2 = false; 
}

void stop() {					// 정지, 표 2 참조
    IN1 = false;
    IN2 = false;
}

int main() {
    ENA.write(1);				// 제어 가능 상태, 최대 속도
    forward();				// 초기 정회전 상태
    printf("Start...\n");

    while(1){
        if(btn == true){			// 버튼이 눌러진 경우
            direction = !direction;		// 회전 방향 변경
        
            if(direction){
                forward();		// 정회전
                printf("Forward...\n");
                wait(0.5);
            }
            else{
                backward();		// 역회전
                printf("Backward...\n");
                wait(0.5);
            }
        }
    }
}