#include <iostream>
#include <stdexcept>

// ���ø� Ŭ������ Ư�� Ÿ��(T)�� ���� �۵��ϴ� ���͸� ����
template <typename T>
class SimpleVector {
private:
    T* data;           // ���ø� Ÿ���� �����͸� ������ �迭
    size_t capa_1;     // �迭�� �ִ� ũ�� (capacity)
    size_t size_1;     // ���� ����� ������ ���� (size)

public:
    // ������: �⺻������ ũ�� 10�� �迭�� ���� (capacity�� ���޹��� ���� ����)
    SimpleVector(size_t capacity = 10)
        : data(new T[capacity]), capa_1(capacity), size_1(0) {
    }

    // �Ҹ���: ���� �޸� ����
    ~SimpleVector() {
        delete[] data;
    }

    // push_back: �迭�� �� ���� ���Ҹ� �߰�
    void push_back(const T& element) {
        if (size_1 < capa_1) {
            data[size_1++] = element; // �����͸� �߰��� �� size_1�� ����
        }
        else {
            // �迭�� �� �� ��� �ƹ� ���۵� ���� ����
        }
    }

    // pop_back: �迭�� �� �� ���Ҹ� ����
    void pop_back() {
        if (size_1 > 0) {
            --size_1; // size_1�� ���ҽ��� ������ ���� ����
        }
    }

    // size: ���� ����� ������ ������ ��ȯ
    size_t size() const {
        return size_1;
    }

    // capacity: �迭�� �ִ� ũ�⸦ ��ȯ
    size_t capacity() const {
        return capa_1;
    }

    // operator[]: �迭ó�� ���Ҹ� �ε����� ���� ���� (���� ����)
    T& operator[](size_t index) {
        if (index >= size_1) {
            throw std::out_of_range("Index out of range");
        }
        return data[index];
    }

    // const operator[]: const ������ �ε��� ���� (�б� ����)
    const T& operator[](size_t index) const {
        if (index >= size_1) {
            throw std::out_of_range("Index out of range");
        }
        return data[index];
    }
};

// main �Լ�: SimpleVector Ŭ������ ���� Ȯ��
int main() {
    // int Ÿ���� SimpleVector ���� (�⺻ ũ�� 10)
    SimpleVector<int> vec;

    // ���Ϳ� ���� �߰�
    vec.push_back(42);
    vec.push_back(7);
    vec.push_back(19);

    // ���� ���� ���
    std::cout << "Vector elements: ";
    for (size_t i = 0; i < vec.size(); ++i) {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;

    // �� �� ���� ����
    vec.pop_back();
    std::cout << "After pop_back, size: " << vec.size() << std::endl;

    // double Ÿ���� SimpleVector ���� (ũ�� 5)
    SimpleVector<double> doubleVec(5);
    doubleVec.push_back(3.14);
    doubleVec.push_back(2.71);

    // double ���� ���� ���
    std::cout << "Double Vector elements: ";
    for (size_t i = 0; i < doubleVec.size(); ++i) {
        std::cout << doubleVec[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}