#include "InstructionInterpreter.h"
#include <stdexcept>

InstructionInterpreter::InstructionInterpreter(InstructionTable& instructionTable)
    : accumulator(0)
    , m_instructionTable(instructionTable)
{

}

void InstructionInterpreter::executeProgram()
{
    for (int i = 0; i < m_instructionTable.getTableRowCount(); ++i) {
        auto row = m_instructionTable.getRowByIndex(i);
        executeInstruction(row[1], row[2], row[3], row[4]);
    }
}

void InstructionInterpreter::executeInstruction(int opCode, int arg1, int arg2, int arg3)
{
    if (opCode == 1) {
        int sum = arg2 + arg3;

        int targetRow = arg1 - 1;
        if (targetRow < 0 || targetRow >= m_instructionTable.getTableRowCount()) {
            //throw std::out_of_range("Invalid memory address");
        }

        int part1 = (sum / 1000000) % 1000;
        int part2 = (sum / 1000) % 1000;
        int part3 = sum % 1000;

        m_instructionTable.setRowByIndex(targetRow, {0, part1, part2, part3});
    }
}
