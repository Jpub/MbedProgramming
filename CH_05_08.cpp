#include "mbed.h"

int main() {
    // 포트 1의 입출력을 설정하기 위한 FIO1DIR 레지스터 주소
    unsigned int *port1_dir = (unsigned int *)0x2009C020;

    // 18번 비트에 1을 출력하기 위해 사용하는 마스크
    unsigned int mask_pin18 = 1 << 18;

    // 포트 1의 18번 핀을 출력으로 설정
    *port1_dir |= mask_pin18;

    // 포트1의 핀으로 HIGH와 LOW 값을 출력하기 위해 사용되는 레지스터 주소
    // HIGH 값 출력에 사용되는 FIO1SET 레지스터 주소
    unsigned int *port1_set = (unsigned int *)0x2009C038;   
    // LOW 값 출력에 사용되는 FIO1CLR 레지스터 주소
    unsigned int *port1_clr = (unsigned int *)0x2009C03C;

    while (true) {
        // 포트 1의 18번 핀으로 HIGH 값 출력
        *port1_set |= mask_pin18;
        wait(0.5);

        // 포트 1의 18번 핀으로 LOW 값 출력
        *port1_clr |= mask_pin18;
        wait(0.5);
    }
}