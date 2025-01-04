#include "InstructionCompleter.h"
#include "Instruction.h"

InstructionCompleter::InstructionCompleter(QObject* parent)
    : QCompleter(parent)
{
    QStringList instructionsList;
    for (const Instruction& instruction : Instruction::allInstructions()) {
        instructionsList.append(instruction.name());
    }
    setModel(new QStringListModel(instructionsList, this));
}
