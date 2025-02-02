#include "InstructionTable.h"

InstructionTable::InstructionTable(QWidget* parent)
    : QWidget(parent)
    , m_layout(new QVBoxLayout)
    , m_tableView(new InstructionTableView(this))
    , m_cellHandler(new InstructionCellHandler(*m_tableView->getTable()))
{
    connect(m_tableView, &InstructionTableView::instructionCellChanged, m_cellHandler, &InstructionCellHandler::onCellChanged);

    m_layout->addWidget(m_tableView->getTable());
    setLayout(m_layout);
}

InstructionTable::~InstructionTable()
{
    delete m_layout;
    delete m_tableView;
    delete m_cellHandler;
}
