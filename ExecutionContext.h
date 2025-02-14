#pragma once

#include "Memory.h"

class ExecutionContext {
public:
    Memory& memory;
    int accumulator;

    ExecutionContext(Memory& mem)
        : memory(mem), accumulator(0) {}
};
