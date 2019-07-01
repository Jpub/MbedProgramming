#include "mbed.h"

typedef struct{         // 구조체를 새로운 유형의 변수로 정의
    int age;                    // 나이 필드(field)
    float weight;           // 몸무게 필드(field)
}Student;                   // 새로운 유형의 이름

int main() {
    Student student;        // Student형 변수 선언
    
    student.age = 21;       // 구조체의 각 필드에 변수값 대입
    student.weight = 61.5;
    
    printf("Age : %d, Weight : %f\n", student.age, student.weight);
    
    while(1) {
    }
}