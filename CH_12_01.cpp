#include "mbed.h"
#include "Ser25lcxxx.h"

SPI mySPI(D11, D12, D13);		// (MOSI, MISO, SCK)
// (SPI pointer, SS, Memory Size, Page Size)
Ser25LCxxx myEEPROM(&mySPI, A2, 128, 16);

int main() {
	for(int i = 0; i < 10; i++){
		char data = i;
		myEEPROM.write(i, 1, &data);		// 바이트 단위로 메모리에 쓰기
	}
	
	char *buffer;

	for(int i = 0; i < 10; i++){
		buffer = myEEPROM.read(i, 1);	// 1바이트 읽기
		printf("%d\n", buffer[i]);
		free(buffer);
	}
	
	while(1) {
	}
}