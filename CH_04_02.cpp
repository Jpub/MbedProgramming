#include "mbed.h"

DigitalOut myled(LED1);         // LED를 출력으로 사용
DigitalIn mybutton(USER_BUTTON);    // 버튼을 입력으로 사용

int main() {
    while(1) {
        myled = !mybutton;
    }
}