#pragma once
#include "ALUCommand.h"
#include "ReadableMemory.h"
#include "WritableMemory.h"

class ALU 
{

private:
    ALUCommand command;
    ReadableMemory& inputA;
    ReadableMemory& inputB;
    WritableMemory& output;

public:
    ALU(ReadableMemory& a, ReadableMemory& b, WritableMemory& o);
    void setCommand(ALUCommand value);
    void compute();

};