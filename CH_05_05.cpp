#include "mbed.h"

int main() {
    gpio_t LED_pin;

    // GPIO 객체에 LED가 연결된 포트 A의 5번 핀을 할당
    gpio_init(&LED_pin, PA_5);
    // LED가 연결된 포트 A의 5번 핀을 출력으로 설정
    gpio_dir(&LED_pin, PIN_OUTPUT);

    while (true) {
        // 포트 A의 5번 핀으로 HIGH 값 출력
        gpio_write(&LED_pin, 1);
        wait(0.5);

        // 포트 A의 5번 핀으로 LOW 값 출력
        gpio_write(&LED_pin, 0);
        wait(0.5);
    }
}