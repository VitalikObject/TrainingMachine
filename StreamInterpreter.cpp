#include "StreamInterpreter.h"

void StreamInterpreter::writeInput(const std::string& text) {
    m_inputStream << text;
}

QString StreamInterpreter::readInput() {
    return QString::fromStdString(m_inputStream.str());
}

void StreamInterpreter::writeOutput(const std::string& text) {
    m_outputStream << text << std::endl;
}

QString StreamInterpreter::readOutput() {
    return QString::fromStdString(m_outputStream.str());
}

void StreamInterpreter::clear() {
    m_inputStream.str("");
    m_inputStream.clear();

    m_outputStream.str("");
    m_outputStream.clear();
}
