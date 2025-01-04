#include "InstructionCellHandler.h"
#include "Instruction.h"
#include <QTableWidgetItem>
#include <QBrush>

InstructionCellHandler::InstructionCellHandler(QTableWidget* table)
    : m_table(table)
{
}

void InstructionCellHandler::onCellChanged(int row, int column)
{
    if (column == 1) {
        QString input = m_table->item(row, column)->text();
        bool isValid = isValidInstruction(input);

        if (isValid) {
            m_table->item(row, column)->setBackground(QBrush(Qt::transparent));
        } else {
            m_table->item(row, column)->setBackground(QBrush(Qt::red));
        }
    }
}

bool InstructionCellHandler::isValidInstruction(const QString& input)
{
    for (const Instruction& instruction : Instruction::allInstructions()) {
        if (instruction.name() == input) {
            return true;
        }
    }
    return false;
}
