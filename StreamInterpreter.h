#pragma once

#include <sstream>
#include "IStreamInterpreter.h"

class StreamInterpreter : public IStreamInterpreter {
public:
    virtual void writeInput(const std::string& text) override;
    virtual QString readInput() override;
    virtual void writeOutput(const std::string& text) override;
    virtual QString readOutput() override;

    void clear();
private:
    std::stringstream m_inputStream;
    std::stringstream m_outputStream;
};
