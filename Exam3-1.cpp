#include <iostream>
#include <stdexcept>

// 템플릿 클래스로 특정 타입(T)에 대해 작동하는 벡터를 정의
template <typename T>
class SimpleVector {
private:
    T* data;           // 템플릿 타입의 데이터를 저장할 배열
    size_t capa_1;     // 배열의 최대 크기 (capacity)
    size_t size_1;     // 현재 저장된 원소의 개수 (size)

public:
    // 생성자: 기본값으로 크기 10인 배열을 생성 (capacity를 전달받을 수도 있음)
    SimpleVector(size_t capacity = 10)
        : data(new T[capacity]), capa_1(capacity), size_1(0) {
    }

    // 소멸자: 동적 메모리 해제
    ~SimpleVector() {
        delete[] data;
    }

    // push_back: 배열의 맨 끝에 원소를 추가
    void push_back(const T& element) {
        if (size_1 < capa_1) {
            data[size_1++] = element; // 데이터를 추가한 뒤 size_1을 증가
        }
        else {
            // 배열이 꽉 찬 경우 아무 동작도 하지 않음
        }
    }

    // pop_back: 배열의 맨 끝 원소를 제거
    void pop_back() {
        if (size_1 > 0) {
            --size_1; // size_1을 감소시켜 마지막 원소 제거
        }
    }

    // size: 현재 저장된 원소의 개수를 반환
    size_t size() const {
        return size_1;
    }

    // capacity: 배열의 최대 크기를 반환
    size_t capacity() const {
        return capa_1;
    }

    // operator[]: 배열처럼 원소를 인덱스를 통해 접근 (쓰기 가능)
    T& operator[](size_t index) {
        if (index >= size_1) {
            throw std::out_of_range("Index out of range");
        }
        return data[index];
    }

    // const operator[]: const 버전의 인덱스 접근 (읽기 전용)
    const T& operator[](size_t index) const {
        if (index >= size_1) {
            throw std::out_of_range("Index out of range");
        }
        return data[index];
    }
};

// main 함수: SimpleVector 클래스의 동작 확인
int main() {
    // int 타입의 SimpleVector 생성 (기본 크기 10)
    SimpleVector<int> vec;

    // 벡터에 원소 추가
    vec.push_back(42);
    vec.push_back(7);
    vec.push_back(19);

    // 벡터 원소 출력
    std::cout << "Vector elements: ";
    for (size_t i = 0; i < vec.size(); ++i) {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;

    // 맨 끝 원소 제거
    vec.pop_back();
    std::cout << "After pop_back, size: " << vec.size() << std::endl;

    // double 타입의 SimpleVector 생성 (크기 5)
    SimpleVector<double> doubleVec(5);
    doubleVec.push_back(3.14);
    doubleVec.push_back(2.71);

    // double 벡터 원소 출력
    std::cout << "Double Vector elements: ";
    for (size_t i = 0; i < doubleVec.size(); ++i) {
        std::cout << doubleVec[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}