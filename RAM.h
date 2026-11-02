#pragma once
#include <vector>
#include "ReadableMemory.h"
#include "WritableMemory.h"

class RAM : public ReadableMemory, public WritableMemory 
{

private:
    std::vector<int> values;
    int address;

public:
    RAM(int size);
    void setAddress(int value);
    int read() const override;
    void write(int newValue) override;

};