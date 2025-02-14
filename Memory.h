#pragma once

#include "InstructionTable.h"

class Memory {
public:
    Memory(InstructionTable &instructionTable) : m_instructionTable(instructionTable) {}
    int getValue(int address) const;
    void setValue(int address, int value);

private:
    InstructionTable &m_instructionTable;
};
