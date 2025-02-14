#pragma once

#include "IInstruction.h"
#include "../ExecutionContext.h"

class BranchInstruction : public IInstruction {
public:
    BranchInstruction(int negPC, int posPC, int zeroPC)
        : m_negativePC(negPC), m_positivePC(posPC), m_zeroPC(zeroPC) {}

    virtual int execute(ExecutionContext& context, int /*currentPC*/) override;
private:
    int m_negativePC;
    int m_positivePC;
    int m_zeroPC;
};
