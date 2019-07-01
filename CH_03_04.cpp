#include "mbed.h"

class Student{
private:
    int age;
    double weight;
public:                     // 연산자 오버로딩 정의
    void operator=(const int &_age) { age = _age; };
    void operator=(const double &_weight) { weight = _weight; };

    operator int() { return age; };
    operator double() { return weight; };
};

int main() {
    Student student;

    student = 21;           // 대입 연산자 오버로딩을 통한 대입
    student = 61.5;

    // 캐스팅 연산자 오버로딩을 통한 값 읽기
    printf("Age : %d, Weight : %f\n", (int)student, (double)student);
    
    while(1) {
    }
}