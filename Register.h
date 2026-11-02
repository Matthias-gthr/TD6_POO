#pragma once
#include "ReadableMemory.h"
#include "WritableMemory.h"

class Register : public ReadableMemory, public WritableMemory 
{

private:

    int value;

public:

    Register();
    int read() const override;
    void write(int newValue) override;

};