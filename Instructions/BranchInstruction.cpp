#include "BranchInstruction.h"

int BranchInstruction::execute(ExecutionContext& context, int /*currentPC*/) {
    if (context.accumulator < 0)
        return negativePC-1;
    else if (context.accumulator > 0)
        return positivePC-1;
    else
        return zeroPC-1;
}

