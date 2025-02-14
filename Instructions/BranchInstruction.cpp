#include "BranchInstruction.h"

int BranchInstruction::execute(ExecutionContext& context, int /*currentPC*/) {
    if (context.accumulator < 0)
        return m_negativePC-1;
    else if (context.accumulator > 0)
        return m_positivePC-1;
    else
        return m_zeroPC-1;
}

