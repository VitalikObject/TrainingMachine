#pragma once

#include <QWidget>
#include <QTableWidget>
#include <QtWidgets/qboxlayout.h>
#include "InstructionCompleter.h"

class InstructionTableView : public QWidget
{
    Q_OBJECT

public:
    explicit InstructionTableView(QWidget* parent = nullptr);
    ~InstructionTableView();
    void initializeTable();

    QTableWidget *getTable() const { return m_table; }

signals:
    void instructionCellChanged(int row, int column);

private:
    void setAddressCell(int row);
    void setInstructionCell(int row);
    void setAdditionalCells(int row);
    void ensureItemExists(int row, int column, const QString& initialValue = "");

    QTableWidget *m_table;
    InstructionCompleter *m_completer;
};
