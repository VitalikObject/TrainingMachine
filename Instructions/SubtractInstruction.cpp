#include "SubtractInstruction.h"

int SubtractInstruction::execute(ExecutionContext& context, int currentPC) {
    int result = context.memory.getValue(address2) - context.memory.getValue(address3);
    context.accumulator = result;
    context.memory.setValue(targetAddress, result);
    return currentPC + 1;
}
