#include "JumpInstruction.h"

int JumpInstruction::execute(ExecutionContext& context, int /*currentPC*/) {
    return targetPC-1;
}

