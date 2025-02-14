#include "OutputInstruction.h"

int OutputInstruction::execute(ExecutionContext& context, int currentPC) {
    std::string output = "";
    for (int i = 0; i < m_count; ++i) {
        output += std::to_string(context.getMemory().getValue(m_startAddress + i)) + " ";
    }
    output += "\n";
    context.getStreamInterpreter().writeOutput(output);
    return currentPC + 1;
}
