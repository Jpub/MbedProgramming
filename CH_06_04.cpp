#include "mbed.h"

DigitalInOut LED_1(D2);
DigitalInOut LED_2(D3);

// 풀업 저항을 사용하는 입력 핀으로 설정
DigitalInOut button_1(D4, PIN_INPUT, PullUp, 1);
DigitalInOut button_2(D5);

int main() {
    LED_1.output();         // 출력으로 설정
    LED_2.output();

    button_2.input();           // 입력으로 설정
    button_2.mode(PullDown);        // 풀다운 저항 사용 설정
    
    while(1) {
        LED_1 = button_1;
        LED_2 = button_2;
    }
}