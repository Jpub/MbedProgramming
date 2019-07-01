#include "mbed.h"
#include "DHT.h"

DHT dht(D2, DHT22);			// DHT22 센서 사용

int main() {
    wait(2);					// 센서 안정화 대기
    while(1) {
        int error = dht.readData();	// 센서 데이터 읽기
        
        if(error == ERROR_NONE){	// 센서 데이터 읽기 성공
            float temperature = dht.ReadTemperature(CELCIUS);
            float humidity = dht.ReadHumidity();
            
            printf("Temperature : %.2f, Humidity : %.2f\n", 
											temperature, humidity);
        }
        else{					// 센서 데이터 읽는 중 오류 발생
            printf(" ** Error occurred : %d\n", error);
        }

        wait(3);
    }
}