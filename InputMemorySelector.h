#pragma once
#include <vector>
#include "ReadableMemory.h"

class InputMemorySelector : public ReadableMemory 
{

private:

    std::vector<ReadableMemory*> memories;
    int selectedMemory;

public:
    InputMemorySelector();
    void addMemory(ReadableMemory* memory);
    void selectMemory(int index);

    int read() const override;

};