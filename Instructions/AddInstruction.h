#pragma once

#include "ArithmeticInstruction.h"
#include "../ExecutionContext.h"

class AddInstruction : public ArithmeticInstruction {
public:
    using ArithmeticInstruction::ArithmeticInstruction;

    virtual int execute(ExecutionContext& context, int currentPC) override;
};
