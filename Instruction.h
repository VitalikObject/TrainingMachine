#pragma once

#include <QString>
#include <QList>

class Instruction {
public:
    Instruction(const QString& code, const QString& name)
        : m_code(code), m_name(name) {}

    QString code() const { return m_code; }
    QString name() const { return m_name; }

    static QList<Instruction> allInstructions();

private:
    QString m_code;
    QString m_name;
};
