#pragma once

#include <QWidget>
#include <QTableWidget>
#include <QVBoxLayout>
#include "InstructionTableView.h"
#include "InstructionCellHandler.h"

class InstructionTable : public QWidget
{
    Q_OBJECT

public:
    explicit InstructionTable(QWidget* parent = nullptr);
    ~InstructionTable();

private:
    InstructionTableView *m_tableView;
    InstructionCellHandler *m_cellHandler;
    QVBoxLayout *m_layout;
};
