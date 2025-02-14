#pragma once

#include "IInstruction.h"
#include "../ExecutionContext.h"

class BranchInstruction : public IInstruction {
public:
    BranchInstruction(int negPC, int posPC, int zeroPC)
        : negativePC(negPC), positivePC(posPC), zeroPC(zeroPC) {}

    virtual int execute(ExecutionContext& context, int /*currentPC*/) override;
private:
    int negativePC;
    int positivePC;
    int zeroPC;
};
