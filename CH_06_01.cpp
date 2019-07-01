#include "mbed.h"

Serial pc(SERIAL_TX, SERIAL_RX);    // PC와 UART 연결

DigitalOut connectedPin(LED1);      // LED1 핀과 연결된 객체 생성
DigitalOut notConnectedPin(NC);         // GPIO 핀과 연결되지 않은 객체 생성

int main() {
    if(connectedPin.is_connected()) {
        pc.printf("Connected...\n");
    }   else {
        pc.printf("Not Connected...\n"); 
    }

    if(notConnectedPin.is_connected()) {
        pc.printf("Connected...\n");
    } else {
        pc.printf("Not Connected...\n");
    }

    while(1) { }
}