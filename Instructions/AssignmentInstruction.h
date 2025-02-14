#pragma once

#include "IInstruction.h"
#include "../ExecutionContext.h"

class AssignmentInstruction : public IInstruction {
public:
    AssignmentInstruction(int target, int sourceAddress)
        : m_targetAddress(target), m_sourceAddress(sourceAddress) {}

    virtual int execute(ExecutionContext& context, int currentPC) override;

private:
    int m_targetAddress;
    int m_sourceAddress;
};
