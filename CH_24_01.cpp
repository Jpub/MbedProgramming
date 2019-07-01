#include "mbed.h"
#include "ds1307.h"

I2C myI2C(D14, D15);
DS1307 myRTC(myI2C);			// (SDA, SCL)

int main() {
	// 0초, 0분, 8시, 1일, 1월, 2019년, 화요일
	struct tm initialTime = { 0, 0, 8, 1, 0, 119, 2 };
	struct tm *currentTime;
	
	myRTC.setTime(&initialTime);		// 현재 시간 설정

	while(1) {
		currentTime = myRTC.getTime();	// 현재 시간 읽기
		
		printf("%04d-%02d-%02d, %02d:%02d:%02d\n", 
			currentTime->tm_year + 1900, currentTime->tm_mon + 1, 
			currentTime->tm_mday, currentTime->tm_hour, 
			currentTime->tm_min, currentTime->tm_sec);
		
		wait(1);
	}
}