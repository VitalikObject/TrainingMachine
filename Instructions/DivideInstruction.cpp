#include "DivideInstruction.h"

int DivideInstruction::execute(ExecutionContext& context, int currentPC) {
    int divisor = context.memory.getValue(address3);
    if (divisor == 0)
        throw std::runtime_error("Division by zero");
    int result = context.memory.getValue(address2) / divisor;
    context.accumulator = result;
    context.memory.setValue(targetAddress, result);
    return currentPC + 1;
}
