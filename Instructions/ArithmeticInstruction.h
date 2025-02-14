#pragma once

#include "IInstruction.h"

class ArithmeticInstruction : public IInstruction {
public:
    ArithmeticInstruction(int target, int addr2, int addr3)
        : m_targetAddress(target), m_address2(addr2), m_address3(addr3) {}

protected:
    int m_targetAddress;
    int m_address2;
    int m_address3;
};
