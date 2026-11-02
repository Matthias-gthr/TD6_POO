#pragma once

class ReadableMemory {

public:

    virtual ~ReadableMemory() = default;
    virtual int read() const = 0;

};