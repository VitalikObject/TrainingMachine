#include "InstructionInterpreter.h"
#include "Instructions/InstructionFactory.h"

InstructionInterpreter::InstructionInterpreter(InstructionTable& instructionTable)
    : m_instructionTable(instructionTable)
    , m_memory(new Memory(instructionTable))
    , m_streamInterpreter(nullptr)
    , m_executionContext(nullptr)
{
    m_streamInterpreter = new StreamInterpreter();
    m_executionContext = new ExecutionContext(*m_memory, *m_streamInterpreter);
}

void InstructionInterpreter::executeProgram()
{
    int pc = 0;
    while (pc < m_instructionTable.getTableRowCount()) {
        const auto row = m_instructionTable.getRowByIndex(pc);
        auto instruction = InstructionFactory::createInstruction(row);
        pc = instruction->execute(*m_executionContext, pc);
    }
}
