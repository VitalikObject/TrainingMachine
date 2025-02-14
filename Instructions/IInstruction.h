#pragma once

#include "../ExecutionContext.h"

class IInstruction {
public:
    virtual ~IInstruction() = default;
    virtual int execute(class ::ExecutionContext& context, int currentPC) = 0;
};
