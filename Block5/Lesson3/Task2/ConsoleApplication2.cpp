﻿#include <iostream>

class smart_array {
public:
    smart_array(const size_t size);
    smart_array(const smart_array& other);
    smart_array& operator=(const smart_array& other);
    ~smart_array();
    void add_element(const int value);
    int get_element(const size_t index);
    void print_smart_array();

private:
    int* sm_array_ = nullptr;
    size_t sizeOfArray_ = 0;
    size_t countForOverflow_ = 0;
};

smart_array::smart_array(const size_t size) {
    sizeOfArray_ = size;
    sm_array_ = new int[size] {};
}

smart_array::~smart_array() { delete[] sm_array_; }

smart_array::smart_array(const smart_array& other) {
    this->sizeOfArray_ = other.sizeOfArray_;
    this->countForOverflow_ = other.countForOverflow_;
    sm_array_ = new int[other.sizeOfArray_];
    for (int i = 0; i < other.sizeOfArray_; i++) {
        this->sm_array_[i] = other.sm_array_[i];
    }
    std::cout << std::endl;
}

smart_array& smart_array::operator=(const smart_array& other) {
    if (this != &other) {
        delete[] sm_array_;
        this->sizeOfArray_ = other.sizeOfArray_;
        this->countForOverflow_ = other.countForOverflow_;

        sm_array_ = new int[other.sizeOfArray_];
        for (int i = 0; i < other.sizeOfArray_; i++) {
            this->sm_array_[i] = other.sm_array_[i];
        }
        std::cout << std::endl;
    }
    return *this;
}

void smart_array::print_smart_array() {
    for (int i = 0; i < sizeOfArray_; i++)
        std::cout << sm_array_[i] << " ";

    std::cout << std::endl;
};

void smart_array::add_element(const int value) {
    if (countForOverflow_ >= sizeOfArray_) {
        throw std::out_of_range("Размер массива меньше колличества элементов");
    }
    sm_array_[countForOverflow_++] = value;
};

int smart_array::get_element(const size_t index) {
    if ((index >= sizeOfArray_) || (index < 0)) {
        throw std::out_of_range("Добавляемый элемент выходит за пределы массива");
    }
    return sm_array_[index];
};
int main(int argc, char** argv) {
    setlocale(LC_ALL, "Russian");

    try {

        smart_array arr(5);
        arr.add_element(1);
        arr.add_element(4);
        arr.add_element(155);
        arr.print_smart_array();
        std::cout << std::endl;
        std::cout << arr.get_element(2) << std::endl;

        smart_array new_array(2);
        new_array.add_element(44);
        new_array.add_element(34);
        new_array.print_smart_array();
        arr = new_array;
        arr.print_smart_array();
    }
    catch (const std::exception& ex) {
        std::cout << ex.what() << std::endl;
    }

    return 0;
}