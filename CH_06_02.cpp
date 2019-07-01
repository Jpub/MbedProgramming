#include "mbed.h"

DigitalOut LED_1(D2);           // D2 핀에 연결된 LED를 출력으로 사용
DigitalOut LED_2(D3);           // D3 핀에 연결된 LED를 출력으로 사용

int main() {
    bool state = true;          // LED_1의 상태
    
    while(1) {
        // 연산자 재정의를 통한 디지털 데이터 출력
        LED_1 = state;          // LED_1에 상태 출력
        LED_2 = !LED_1;         // LED_2에 LED_1의 반전된 상태 출력

        // 멤버 함수를 통한 디지털 데이터 출력
        // LED_1.write(state);      // LED_1에 상태 출력
        // LED_2.write(!LED_1.read());  // LED_2에 LED_1의 반전된 상태 출력
        
        state = !state;         // LED_1의 상태 반전
        
        wait(0.5);
    }
}