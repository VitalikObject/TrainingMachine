#pragma once

#include "Memory.h"
#include "StreamInterpreter.h"

class ExecutionContext {
public:
    int accumulator;

    ExecutionContext(Memory& memory, StreamInterpreter& streamInterpreter)
        : m_memory(memory), m_streamInterpreter(streamInterpreter), accumulator(0) {}

    Memory& getMemory() const { return m_memory; }
    StreamInterpreter& getStreamInterpreter() const { return m_streamInterpreter; }
private:
    Memory& m_memory;
    StreamInterpreter& m_streamInterpreter;
};
