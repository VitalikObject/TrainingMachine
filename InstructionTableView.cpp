#include "InstructionTableView.h"
#include <QTableWidgetItem>
#include <QHeaderView>
#include <QLineEdit>
#include <QtWidgets/qboxlayout.h>
#include "Utils.h"
#include "Instruction.h"

InstructionTableView::InstructionTableView(QWidget* parent)
    : QWidget(parent)
    , m_table(new QTableWidget(this))
    , m_completer(new InstructionCompleter(this))
{
    m_table->setRowCount(512);
    m_table->setColumnCount(5);
    m_table->setHorizontalHeaderLabels({"АДР", "КОП", "А1", "А2", "А3"});
    m_table->verticalHeader()->setVisible(false);
    m_table->setEditTriggers(QAbstractItemView::AllEditTriggers);

    initializeTable();
}

InstructionTableView::~InstructionTableView()
{
    delete m_table;
    delete m_completer;
}

void InstructionTableView::initializeTable()
{
    for (int i = 1; i <= 512; ++i) {
        setAddressCell(i);
        setInstructionCell(i);
        setAdditionalCells(i);
    }
}

void InstructionTableView::setAddressCell(int row)
{
    QTableWidgetItem* addrItem = new QTableWidgetItem(Utils::intToString(row));
    addrItem->setFlags(addrItem->flags() & ~Qt::ItemIsEditable);
    m_table->setItem(row - 1, 0, addrItem);
}

void InstructionTableView::setInstructionCell(int row)
{
    QLineEdit* lineEdit = new QLineEdit("ПЕР");
    lineEdit->setCompleter(m_completer);
    m_table->setCellWidget(row - 1, 1, lineEdit);
    ensureItemExists(row - 1, 1);
    connect(lineEdit, &QLineEdit::textChanged, this, [this, lineEdit, row]() {
        QString input = lineEdit->text().toUpper();
        lineEdit->setText(input);
        m_table->item(row - 1, 1)->setText(input);
        emit instructionCellChanged(row - 1, 1);
    });
}

void InstructionTableView::setAdditionalCells(int row)
{
    m_table->setItem(row - 1, 2, new QTableWidgetItem("000"));
    m_table->setItem(row - 1, 3, new QTableWidgetItem("000"));
    m_table->setItem(row - 1, 4, new QTableWidgetItem("000"));
}

void InstructionTableView::ensureItemExists(int row, int column, const QString& initialValue)
{
    if (!m_table->item(row, column)) {
        QTableWidgetItem* item = new QTableWidgetItem(initialValue);
        m_table->setItem(row, column, item);
    }
}

QList<int> InstructionTableView::getRowByIndex(int index)
{
    QList<int> rowItems;
    if (index >= 0 && index < m_table->rowCount()) {
        for (int col = 0; col < m_table->columnCount(); ++col) {
            if (col != 1) {
                rowItems.append(m_table->item(index, col)->text().toInt());
            } else {
                auto* widget = m_table->cellWidget(index, col);
                if (auto* lineEdit = qobject_cast<QLineEdit*>(widget)) {
                    rowItems.append(Instruction::getCodeNumber(lineEdit->text()));
                }
            }
        }
    }
    return rowItems;
}

void InstructionTableView::setRowByIndex(int index, const QList<int>& values)
{
    if (index >= 0 && index < m_table->rowCount() && values.size() == m_table->columnCount() - 1) {
        for (int col = 1; col < m_table->columnCount(); ++col) {
            if (col != 1) {
                QString formattedValue = QString::number(values[col - 1], 10).rightJustified(3, '0');
                m_table->item(index, col)->setText(formattedValue);
            } else {
                auto* widget = m_table->cellWidget(index, col);
                if (auto* lineEdit = qobject_cast<QLineEdit*>(widget)) {
                    lineEdit->setText(Instruction::getCodeName(values[col - 1]));
                }
            }
        }
    }
}

void InstructionTableView::applyChangesAndClearFocus()
{
    if (m_table->currentItem()) {
        m_table->closePersistentEditor(m_table->currentItem());
    }
    m_table->clearFocus();
}

