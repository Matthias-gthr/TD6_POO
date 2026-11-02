#pragma once

class WritableMemory {

public:

    virtual ~WritableMemory() = default;
    virtual void write(int newValue) = 0;

};