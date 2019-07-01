#include "mbed.h"
#include "Sseg.h"

// (a, b, c, d, e, f, g, dp, d1, d2, d3, d4)
Sseg mySeg(D2, D3, D4, D5, D6, D7, D8, D9, D10, D11, D12, D13);

Ticker update_ticker;			// 자동 갱신

void update_7_segment(void) {		// 콜백 함수
	mySeg.update();
}

int main() {
	mySeg.setKcommon();			// 공통 음극 방식
	mySeg.begin();				// 내부 타이머 시작

	// 5ms 간격으로 자동 호출되는 콜백 함수 등록
	update_ticker.attach(update_7_segment, 0.005);

	char patterns[] = {			// 사용자 정의 패턴
		0b01111100, 0b10111100, 0b11011100,
		0b11101100, 0b11110100, 0b11111000 };
	int N = 6;					// 패턴의 개수
	int index = 0;				// 표시할 패턴 인덱스
	
	while(1) {
		mySeg.writeRawData(			// 사용자 정의 패턴 출력
			patterns[index], 
			patterns[(index + 1) % N], 
			patterns[(index + 2) % N], 
			patterns[(index + 3) % N]);
		
		index = (index + 1) % N;
		
		wait(1);
	}
}