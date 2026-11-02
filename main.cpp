#include <iostream>
#include "Register.h"
#include "ALU.h"
#include "ALUCommand.h"
#include "RAM.h"
#include "Keyboard.h"
#include "InputMemorySelector.h"

int main() {
    
    Keyboard kb;
    RAM ram(16);
    Register accumulator;
    InputMemorySelector selector;

    
    selector.addMemory(&kb); 
    selector.addMemory(&ram); 

    
    ALU alu(selector, accumulator, accumulator);

    ram.setAddress(0);
    ram.write(5);
    ram.setAddress(1);
    ram.write(2);

    try {
        selector.selectMemory(1);
        alu.setCommand(ALUCommand::COPYA);
        alu.compute();
    }catch (const std::out_of_range& e) {
        std::cerr << "Erreur : " << e.what() << std::endl;
        return 1; 
	}

    std::cout << "Saisie de la variable y :" << std::endl;
    try {
        selector.selectMemory(0); 
        alu.setCommand(ALUCommand::ADD);
        alu.compute(); 
    }
    catch (const std::out_of_range& e) {
        std::cerr << "Erreur : " << e.what() << std::endl;
        return 1;
    }

    ram.setAddress(2);
    ram.write(accumulator.read());

    ram.setAddress(0);
    try {
        selector.selectMemory(1);
        alu.setCommand(ALUCommand::COPYA);
        alu.compute();
    }
    catch (const std::out_of_range& e) {
        std::cerr << "Erreur : " << e.what() << std::endl;
        return 1;
	}

    std::cout << " Saisie de la variable x :" << std::endl;
    try {
        selector.selectMemory(0);
        alu.setCommand(ALUCommand::ADD);
        alu.compute();
    }
    catch (const std::out_of_range& e) {
        std::cerr << "Erreur : " << e.what() << std::endl;
        return 1;
	}

    ram.setAddress(2);
    try {
        selector.selectMemory(1);

        alu.setCommand(ALUCommand::SUB);
        alu.compute();
    }
    catch (const std::out_of_range& e) {
        std::cerr << "Erreur : " << e.what() << std::endl;
        return 1;
    }


    std::cout << "\nResultat de (5 + x) - (2 + y) : " << accumulator.read() << std::endl;

    return 0;
}