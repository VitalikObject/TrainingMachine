#pragma once

#include "IInstruction.h"
#include "../ExecutionContext.h"

class OutputInstruction : public IInstruction {
public:
    OutputInstruction(int count, int startAddress)
        : m_count(count), m_startAddress(startAddress) {}

    virtual int execute(ExecutionContext& context, int currentPC) override;

private:
    int m_count;
    int m_startAddress;
};
