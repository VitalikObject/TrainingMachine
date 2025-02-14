#pragma once

#include "IInstruction.h"

class ArithmeticInstruction : public IInstruction {
public:
    ArithmeticInstruction(int target, int addr2, int addr3)
        : targetAddress(target), address2(addr2), address3(addr3) {}

protected:
    int targetAddress;
    int address2;
    int address3;
};
