#include "Instruction.h"

QList<Instruction> Instruction::allInstructions()
{
    return QList<Instruction> {
        Instruction("01", "СЛВ"),
        Instruction("02", "ВЧВ"),
        Instruction("03", "УМВ"),
        Instruction("04", "ДЕВ"),
        Instruction("11", "СЛЦ"),
        Instruction("12", "ВЧЦ"),
        Instruction("13", "УМЦ"),
        Instruction("14", "ДЕЦ"),
        Instruction("21", "МОД"),
        Instruction("20", "ВЕЩ"),
        Instruction("10", "ЦЕЛ"),
        Instruction("00", "ПЕР"),
        Instruction("05", "ВВВ"),
        Instruction("06", "ВВЦ"),
        Instruction("15", "ВЫВ"),
        Instruction("16", "ВЫЦ"),
        Instruction("09", "БЕЗ"),
        Instruction("19", "УСЛ"),
        Instruction("31", "ОСТ")
    };
}

int Instruction::getCodeNumber(const QString& name)
{
    auto instructions = allInstructions();

    for (const Instruction& instruction : instructions) {
        if (instruction.name() == name) {
            return instruction.code().toInt();
        }
    }

    return -1;
}

QString Instruction::getCodeName(int code)
{
    auto instructions = allInstructions();

    for (const Instruction& instruction : instructions) {
        if (instruction.code().toInt() == code) {
            return instruction.name();
        }
    }

    return "";
}


