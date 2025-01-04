#include "MainWindow.h"
#include "./ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , m_ui(new Ui::MainWindow)
    , m_instructionTable(new InstructionTable(this))
    , m_centralWidget(new QWidget(this))
    , m_mainLayout(new QHBoxLayout(m_centralWidget))
    , m_leftGroupBox(new QGroupBox("Instructions", m_centralWidget))
    , m_leftLayout(new QVBoxLayout(m_leftGroupBox))
    , m_rightGroupBox(new QGroupBox("", m_centralWidget))
    , m_rightLayout(new QVBoxLayout(m_rightGroupBox))
{
    m_ui->setupUi(this);

    m_leftLayout->addWidget(m_instructionTable);
    m_leftGroupBox->setLayout(m_leftLayout);

    m_mainLayout->addWidget(m_leftGroupBox);

    m_rightGroupBox->setLayout(m_rightLayout);

    m_mainLayout->addWidget(m_rightGroupBox);

    m_centralWidget->setLayout(m_mainLayout);
    setCentralWidget(m_centralWidget);

    m_mainLayout->setStretch(0, 1);
    m_mainLayout->setStretch(1, 1);
}

MainWindow::~MainWindow()
{
    delete m_ui;
}

void MainWindow::adjustWindowSize()
{
    //m_instructionTable->resizeColumnsToContents();
    //int tableWidth = m_instructionTable->horizontalHeader()->length();
    //int totalWidth = tableWidth + m_leftGroupBox->contentsMargins().left() + m_leftGroupBox->contentsMargins().right() + 20;

    //resize(totalWidth, height());
}
