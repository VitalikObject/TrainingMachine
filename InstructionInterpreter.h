#pragma once

#include <QString>
#include <QMap>
#include <QVector>
#include "InstructionTable.h"

class InstructionInterpreter {
public:
    InstructionInterpreter(InstructionTable& instructionTable);
    int getMemoryValue(int address) const;
    void executeProgram();

private:

    QMap<int, int> m_memory;
    InstructionTable &m_instructionTable;

    void executeInstruction(int opCode, int arg1, int arg2, int arg3);
    int accumulator;
};
