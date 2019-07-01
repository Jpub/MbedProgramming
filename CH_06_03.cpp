#include "mbed.h"

DigitalOut LED_1(D2);
DigitalOut LED_2(D3);

DigitalIn button_1(D4, PullUp);     // 풀업 저항을 사용한 버튼
DigitalIn button_2(D5, PullDown);       // 풀다운 저항을 사용한 버튼

int main() {
    while(1) {
        LED_1 = button_1;           // LED 1에 버튼 1 상태 나타내기
        LED_2 = button_2;           // LED 2에 버튼 2 상태 나타내기
    }
}