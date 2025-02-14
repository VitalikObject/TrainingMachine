#pragma once

#include "IInstruction.h"

class InputInstruction : public IInstruction {
public:
    InputInstruction(int count, int startAddress)
        : count(count), startAddress(startAddress) {}

    virtual int execute(ExecutionContext& context, int currentPC) override;

private:
    int count;
    int startAddress;
};
