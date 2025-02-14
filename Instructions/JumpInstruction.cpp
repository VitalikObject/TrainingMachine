#include "JumpInstruction.h"

int JumpInstruction::execute(ExecutionContext& context, int /*currentPC*/) {
    return m_targetPC-1;
}

