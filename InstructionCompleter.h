#pragma once

#include <QCompleter>
#include <QStringListModel>

class InstructionCompleter : public QCompleter
{
    Q_OBJECT

public:
    explicit InstructionCompleter(QObject* parent = nullptr);
};
