#pragma once

#include <QString>
#include <QMap>
#include <QVector>
#include "ExecutionContext.h"
#include "InstructionTable.h"
#include "Memory.h"

class InstructionInterpreter {
public:
    InstructionInterpreter(InstructionTable& instructionTable);
    int getMemoryValue(int address) const;
    void executeProgram();

private:

    Memory *m_memory;
    ::ExecutionContext *m_executionContext;
    InstructionTable &m_instructionTable;

    void executeInstruction(int opCode, int arg1, int arg2, int arg3);
};
