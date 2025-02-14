#include "AssignmentInstruction.h"

int AssignmentInstruction::execute(ExecutionContext& context, int currentPC) {
    int value = context.getMemory().getValue(m_sourceAddress);
    context.accumulator = value;
    context.getMemory().setValue(m_targetAddress, value);
    return currentPC + 1;
}
