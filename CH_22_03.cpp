#include "mbed.h"
#include "Sseg.h"

#define INTERVAL 0.002

Sseg matrix(
	D9, D8, D7, D6, D5, D4, D3, D2,	// 행 (코드 1, 2에서와는 반대로 지정)
	D10, D11, D12, D13, A0, A1, A2, A3 );	// 열

// 행 데이터로 선택된 LED만 1의 값을 가짐
char row_data[] = {
	0b00000000, 0b11111111, 0b10001001, 0b10001001, 
	0b10001001, 0b10001001, 0b01110110, 0b00000000 };

Ticker update_ticker;			// 자동 갱신

void update_matrix(void) {		// 콜백 함수
	matrix.update();
}

int main(void) {
	matrix.setKcommon();			// 공통 음극 방식 (열 공통 음극)
	matrix.begin();				// 내부 타이머 시작

	update_ticker.attach(update_matrix, INTERVAL);	// 콜백 함수 등록

	matrix.writeRawData(			// 사용자 정의 문자 등록
		row_data[0], row_data[1], row_data[2], row_data[3], 
		row_data[4], row_data[5], row_data[6], row_data[7]);
	
	while(1) {
	}
}