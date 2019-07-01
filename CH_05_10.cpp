#include "mbed.h"

int main() {
    // 포트의 18번 비트에 1을 출력하기 위해 사용하는 마스크
    unsigned int mask_pin18 = 1 << 18;

    // 포트 1의 18번 핀을 출력으로 설정
    LPC_GPIO1->FIODIR |= mask_pin18;

    while (true) {
        // 포트 1의 18번 핀으로 HIGH 값 출력
        LPC_GPIO1->FIOSET |= mask_pin18;
        wait(0.5);

        // 포트 1의 18번 핀으로 LOW 값 출력
        LPC_GPIO1->FIOCLR |= mask_pin18;
        wait(0.5);
    }
}