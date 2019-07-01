#include "mbed.h"

int main() {
    // 포트 A의 5번 핀을 제어하기 위해 사용하는 마스크
    unsigned int mask_pin5 = 1 << 5;        // Set(ON), Reset(OFF) 제어
    unsigned int mask_pin5_1 = 0b11 << 20;  // MODE5 
    unsigned int mask_pin5_2 = ~(0b11 << 22);   // CNF5

    // 포트 A의 5번 핀을 출력으로 설정
    GPIOA->CRL |= mask_pin5_1;          // 최대 50MHz 속도의 출력 모드
    GPIOA->CRL &= mask_pin5_2;          // 범용 푸시풀 출력 모드
    
    while (true) {
        // 포트 A의 5번 핀으로 HIGH 값 출력, 하위 바이트
        GPIOA->BSRR |= mask_pin5;
        wait(0.5);

        // 포트 A의 5번 핀으로 LOW 값 출력, 상위 바이트
        GPIOA->BSRR |= (mask_pin5 << 16);
        wait(0.5);
    }
}