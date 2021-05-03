#pragma once
#include <iostream>
#include <cstring>
class MyString {

private:

    char* str;
    size_t size;
    size_t capacity;

    void addString(const MyString& other);
    void copy(const MyString& other);
    void resize();
    void destroy();

public:

    MyString();
    MyString(const MyString& other);
    MyString& operator=(const MyString& other);
    ~MyString();

    MyString(const char* str);

    size_t getLen() const;

    const bool isEmpty() const;
    void addChar(const char& add);
    void removeChar();

    MyString& operator+(const MyString& other);
    MyString& operator+=(const MyString& other);
    char operator[](const size_t) const;
    bool operator==(const MyString& other);

    friend std::ostream& operator<<(std::ostream& os, const MyString& _string);
};

void MyString::addString(const MyString& other) {
    if (size == capacity) {
        resize();
    }
    if (capacity - size >= other.size) {
        size_t temp = size;
        for (int i = 0; i < other.size; i++) {
            str[temp] = other.str[i];
            ++temp;
        }
        size = size + other.size;
        str[size] = '\0';
    }
    else {
        resize();
        addString(other);
    }
}

void MyString::copy(const MyString& other) {
    capacity = other.capacity;
    size = other.size;
    str = new char[capacity + 1];

    for (int i = 0; i < size; i++) {
        str[i] = other.str[i];
    }
    str[size] = '\0';
}

void MyString::resize() {
    capacity = capacity * 2;
    char* temp = new char[capacity + 1];
    for (int i = 0; i < size; i++) {
        temp[i] = str[i];
    }
    delete[] str;
    str = temp;
}

void MyString::destroy() {
    delete[] this->str;
    this->str = nullptr;
}

MyString::MyString() :str(nullptr), size(0), capacity(8) {}

MyString::MyString(const MyString& other) {
    copy(other);
}

MyString& MyString::operator=(const MyString& other) {
    if (this != &other) {
        destroy();
        copy(other);
    }
    return *this;
}

MyString::~MyString() {
    destroy();
}

MyString::MyString(const char* _str) {
    size = strlen(_str);
    capacity = size * 2;
    str = new char[capacity + 1];
    strcpy_s(str, capacity + 1, _str);
    str[size] = '\0';
}

size_t MyString::getLen() const {
    return size;
}

const bool MyString::isEmpty() const {
    return size == 0;
}

char MyString::operator[](const size_t index) const {

    if (index >= this->size) {
        exit(-1);
    }
    return this->str[index];
}

void MyString::addChar(const char& add) {
    if (size == capacity - 1) {
        resize();
    }
    str[size] = add;
    ++size;
    str[size] = '\0';
}

void MyString::removeChar() {
    size--;
    str[size] = '\0';
}

MyString& MyString::operator+(const MyString& other) {
    addString(other);
    return*this;
}

MyString& MyString::operator+=(const MyString& other) {
    addString(other);
    return*this;
}

bool MyString::operator==(const MyString& other) {
    return strcmp(str, other.str) == 0 ? true : false;
}

std::ostream& operator<<(std::ostream& os, const MyString& _string) {
    for (int i = 0;i < _string.size;i++) {
        os << _string.str[i];
    }
    return os;
}

