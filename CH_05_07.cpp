#include "mbed.h"

int main() {
    DigitalOut LED_pin(PA_5);   // LED가 연결된 포트 A의 5번 핀을 출력으로 설정

    while (true) {
        LED_pin.write(1);       // 포트 A의 5번 핀으로 HIGH 값 출력 (함수)
        wait(0.5);

        LED_pin = 0;        // 포트 A의 5번 핀으로 LOW 값 출력 (연산자)
        wait(0.5);
    }
}