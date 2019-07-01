#include "mbed.h"
#include "Ser25lcxxx.h"

SPI mySPI(D11, D12, D13);		// (MOSI, MISO, SCK)
// (SPI pointer, SS, Memory Size, Page Size)
Ser25LCxxx myEEPROM(&mySPI, A2, 128, 16);

int main() {
	char write_buffer[10];
	
	for(int i = 0; i < 10; i++){
		write_buffer[i] = i;
	}
	myEEPROM.write(0, 10, write_buffer);	// 페이지 단위로 메모리에 쓰기
	
	char *read_buffer;
	read_buffer = myEEPROM.read(0, 10);	// 10바이트 읽기

	for(int i = 0; i < 10; i++){
		printf("%d\n", read_buffer[i]);
	}

	free(read_buffer);
	
	while(1) {
	}
}