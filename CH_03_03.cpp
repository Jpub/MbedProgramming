#include "mbed.h"

class Student{          // 클래스 정의
private:                        // 직접 접근할 수 없는 멤버 변수
    int age;
    double weight;
public:                     // 직접 접근할 수 있는 멤버 함수
    void setAge(int _age) { age = _age; };
    void setWeight(double _weight) { weight = _weight; };

    int getAge() { return age; };
    double getWeight() { return weight; };
};

int main() {
    Student student;
    
    student.setAge(21);     // 멤버 함수를 통한 대입
    student.setWeight(61.5);    
    
    // 멤버 함수를 통한 값 읽기
    printf("Age : %d, Weight : %f\n", student.getAge(), student.getWeight());
    
    while(1) {
    }
}