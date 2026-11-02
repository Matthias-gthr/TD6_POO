#include "RAM.h"
#include <sstream>

RAM::RAM(int size) {
    values.resize(size, 0);
}

void RAM::setAddress(int value) {
    address = value;
}

int RAM::read() const {
    return values.at(address);
}

void RAM::write(int newValue) {
    if (address < 0 || address >= values.size()) {
        throw std::out_of_range("Address is out of range");
    }
    else {
        values.at(address) = newValue;
    }
}