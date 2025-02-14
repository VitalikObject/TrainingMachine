#pragma once

#include "IInstruction.h"
#include "../ExecutionContext.h"

class AssignmentInstruction : public IInstruction {
public:
    AssignmentInstruction(int target, int sourceAddress)
        : targetAddress(target), sourceAddress(sourceAddress) {}

    virtual int execute(ExecutionContext& context, int currentPC) override;

private:
    int targetAddress;
    int sourceAddress;
};
