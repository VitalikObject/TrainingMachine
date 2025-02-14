#include "InputInstruction.h"

int InputInstruction::execute(ExecutionContext& context, int currentPC) {
    QString inputData = context.getStreamInterpreter().readInput();
    std::istringstream inputStream(inputData.toStdString());

    for (int i = 0; i < count; ++i) {
        int input;
        if (inputStream >> input) {
            context.getMemory().setValue(startAddress + i, input);
        } else {
            throw std::invalid_argument("Error: Not enough valid input values.");
        }
    }

    std::string remainingInput = inputStream.str();
    context.getStreamInterpreter().writeInput(remainingInput);

    return currentPC + 1;
}
