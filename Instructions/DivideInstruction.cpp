#include "DivideInstruction.h"

int DivideInstruction::execute(ExecutionContext& context, int currentPC) {
    int divisor = context.getMemory().getValue(m_address3);
    if (divisor == 0)
        throw std::runtime_error("Division by zero");
    int result = context.getMemory().getValue(m_address2) / divisor;
    context.accumulator = result;
    context.getMemory().setValue(m_targetAddress, result);
    return currentPC + 1;
}
