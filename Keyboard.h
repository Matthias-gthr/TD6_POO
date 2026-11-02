#pragma once
#include "ReadableMemory.h"

class Keyboard : public ReadableMemory 
{

public:
    int read() const override;
};