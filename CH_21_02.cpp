#include "mbed.h"
#include "Sseg.h"

// (a, b, c, d, e, f, g, dp, d1, d2, d3, d4)
Sseg mySeg(D2, D3, D4, D5, D6, D7, D8, D9, D10, D11, D12, D13);

int main() {
	mySeg.setKcommon();			// 공통 음극 방식
	mySeg.begin();				// 내부 타이머 시작

	int count = 1234;
	mySeg.writeNum(count);		// 표시할 숫자 출력
	
	while(1) {
		mySeg.update();			// 숫자 표시
		wait(0.005);				// 업데이트 주기
	}
}