#include "mbed.h"

Serial serial1(PA_9, PA_10);		// UART1 포트 (TX, RX)

int main() {
    int i = 1;

    serial1.printf("Hello World !\n");

    while(1) {
        wait(1);
        serial1.printf("This program runs since %d seconds.\n", i++);
    }
}