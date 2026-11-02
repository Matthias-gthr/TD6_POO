#include "InputMemorySelector.h"
#include <stdexcept>

InputMemorySelector::InputMemorySelector() 
    : selectedMemory(0) {
}

void InputMemorySelector::addMemory(ReadableMemory* memory) {
    memories.push_back(memory);
}

void InputMemorySelector::selectMemory(int index) {
    if (index >= 0 && index < memories.size()) {
        selectedMemory = index;
    }
    else
    {
		throw std::out_of_range("Index de mémoire sélectionnée hors limites.");
	}
}

int InputMemorySelector::read() const {
    return memories.at(selectedMemory)->read();
}