#pragma once

class Memory {
public:

	virtual ~Memory() {};

    virtual int read() const = 0;
	virtual void write(int newValue) = 0;
};