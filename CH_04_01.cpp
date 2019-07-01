#include "mbed.h"

DigitalOut myled(LED1);         // LED를 출력으로 사용

int main() {
    while(1) {
        myled = 1;              // LED 켜기
        wait(1.0);              // 1초 대기
        myled = 0;              // LED 끄기
        wait(1.0);              // 1초 대기
    }
}