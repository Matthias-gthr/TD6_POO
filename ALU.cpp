#include "ALU.h"
#include <iostream>

ALU::ALU(ReadableMemory& a, ReadableMemory& b, WritableMemory& o)
    : inputA(a), inputB(b), output(o), command(ALUCommand::COPYA) {
}

void ALU::setCommand(ALUCommand value) {
    command = value;
}

void ALU::compute() 
{

    switch (command) {

    case ALUCommand::COPYA:

        output.write(inputA.read());
        break;

    case ALUCommand::ADD:

        output.write(inputA.read() + inputB.read());
        break;

    case ALUCommand::SUB:

        output.write(inputB.read() - inputA.read());
        break;

    case ALUCommand::MUL:

        output.write(inputA.read() * inputB.read());
        break;

    case ALUCommand::DIV:

        if (inputB.read() != 0) {

            output.write(inputA.read() / inputB.read());

        }
        else {

            std::cerr << "Erreur : Division par zero !" << std::endl;
            output.write(0);

        }
        break;

	case ALUCommand::AND:

        output.write(inputA.read() & inputB.read());
		break;

    case ALUCommand::OR:

        output.write(inputA.read() | inputB.read());
		break;

    case ALUCommand::SHIFTL:
        output.write(inputA.read() << inputB.read());
		break;

	case ALUCommand::SHIFTR:
        output.write(inputA.read() >> inputB.read());
        break;
    }

}