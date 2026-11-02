#include "Register.h"


Register::Register() {
}

int Register::read() const{
    return value;
}

void Register::write(int newValue) {
    value = newValue;
}