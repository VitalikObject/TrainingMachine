#include "InstructionTable.h"

QString formatNumber(int number) {
    return QString("%1").arg(number, 3, 10, QChar('0'));
}

InstructionTable::InstructionTable(QWidget* parent) : QWidget(parent) {
    QTableWidget* table = new QTableWidget(this);

    table->setRowCount(512);
    table->setColumnCount(5);

    table->setHorizontalHeaderLabels({"АДР", "КОП", "А1", "А2", "А3"});

    table->setEditTriggers(QAbstractItemView::AllEditTriggers);

    for (int i = 1; i <= 512; ++i) {
        QTableWidgetItem* addrItem = new QTableWidgetItem(formatNumber(i));
        addrItem->setFlags(addrItem->flags() & ~Qt::ItemIsEditable);
        table->setItem((i - 1), 0, addrItem);

        table->setItem((i - 1), 1, new QTableWidgetItem("ПЕР"));
        table->setItem((i - 1), 2, new QTableWidgetItem("000"));
        table->setItem((i - 1), 3, new QTableWidgetItem("000"));
        table->setItem((i - 1), 4, new QTableWidgetItem("000"));
    }

    QVBoxLayout* layout = new QVBoxLayout;
    layout->addWidget(table);
    setLayout(layout);
}
