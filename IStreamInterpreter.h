#pragma once

#include <QtCore/qobject.h>
#include <string>

class IStreamInterpreter {
public:
    virtual ~IStreamInterpreter() = default;
    virtual void writeInput(const std::string& text) = 0;
    virtual QString readInput() = 0;
    virtual void writeOutput(const std::string& text) = 0;
    virtual QString readOutput() = 0;
};
