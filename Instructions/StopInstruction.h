#pragma once

#include "IInstruction.h"
#include "../ExecutionContext.h"

class StopInstruction : public IInstruction {
public:
    StopInstruction() {}

    virtual int execute(ExecutionContext& context, int currentPC) override {
        return 511;
    };
};
