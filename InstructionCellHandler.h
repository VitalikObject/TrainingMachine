#pragma once

#include <QObject>
#include <QTableWidget>

class InstructionCellHandler : public QObject
{
    Q_OBJECT

public:
    explicit InstructionCellHandler(QTableWidget &table);

public slots:
    void onCellChanged(int row, int column);

private:
    bool isValidInstruction(const QString& input);

    QTableWidget &m_table;
};
