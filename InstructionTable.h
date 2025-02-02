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
    int getTableRowCount() const { return m_tableView->getRowCount(); }
    QList<int> getRowByIndex(int index) { return m_tableView->getRowByIndex(index); }
    void setRowByIndex(int index, const QList<int>& values) { m_tableView->setRowByIndex(index, values); }
    void applyChangesAndClearFocus() { m_tableView->applyChangesAndClearFocus(); }

private:
    InstructionTableView *m_tableView;
    InstructionCellHandler *m_cellHandler;
    QVBoxLayout *m_layout;
};
