#include "AssignmentInstruction.h"

int AssignmentInstruction::execute(ExecutionContext& context, int currentPC) {
    int value = context.memory.getValue(sourceAddress);
    context.accumulator = value;
    context.memory.setValue(targetAddress, value);
    return currentPC + 1;
}
