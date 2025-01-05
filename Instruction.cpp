#include "Instruction.h"

QList<Instruction> Instruction::allInstructions() {
    return QList<Instruction> {
        Instruction("01", "СЛВ"),
        Instruction("11", "СЛЦ"),
        Instruction("02", "ВЧВ"),
        Instruction("12", "ВЧЦ"),
        Instruction("03", "УМВ"),
        Instruction("13", "УМЦ"),
        Instruction("04", "ДЕВ"),
        Instruction("14", "ДЕЦ"),
        Instruction("15", "МОД"),
        Instruction("10", "ПЕР"),
        Instruction("20", "ЦЕЛ"),
        Instruction("21", "ВЕЩ"),
        Instruction("09", "БЕЗ"),
        Instruction("19", "УСЛ"),
        Instruction("20", "ПР"),
        Instruction("21", "ПНР"),
        Instruction("22", "ПБ"),
        Instruction("23", "ПМ"),
        Instruction("24", "ПБР"),
        Instruction("25", "ПМР"),
        Instruction("31", "ОСТ"),
        Instruction("06", "ВВМ"),
        Instruction("07", "ВВВ"),
        Instruction("17", "ВВЦ")
    };
}
