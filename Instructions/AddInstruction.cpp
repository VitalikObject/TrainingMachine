#include "AddInstruction.h"

int AddInstruction::execute(ExecutionContext& context, int currentPC) {
    int result = context.getMemory().getValue(m_address2) + context.getMemory().getValue(m_address3);
    context.accumulator = result;
    context.getMemory().setValue(m_targetAddress, result);
    return currentPC + 1;
}
