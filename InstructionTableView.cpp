#include "InstructionTableView.h"
#include <QTableWidgetItem>
#include <QHeaderView>
#include <QLineEdit>
#include <QtWidgets/qboxlayout.h>
#include "Utils.h"

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

InstructionTableView::~InstructionTableView() {
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
