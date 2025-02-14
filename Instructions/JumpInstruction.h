#pragma once

#include "IInstruction.h"
#include "../ExecutionContext.h"

class JumpInstruction : public IInstruction {
public:
    JumpInstruction(int targetPC)
        : m_targetPC(targetPC) {}

    virtual int execute(ExecutionContext& context, int /*currentPC*/) override;
private:
    int m_targetPC;
};
