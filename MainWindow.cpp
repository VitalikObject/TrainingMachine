#include "MainWindow.h"
#include "./ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , m_ui(new Ui::MainWindow)
    , m_instructionTable(new InstructionTable(this))
    , m_centralWidget(new QWidget(this))
    , m_mainLayout(new QHBoxLayout(m_centralWidget))
    , m_leftGroupBox(new QGroupBox(/*"Instructions",*/ m_centralWidget))
    , m_leftLayout(new QVBoxLayout(m_leftGroupBox))
    , m_rightGroupBox(new QGroupBox("", m_centralWidget))
    , m_rightLayout(new QVBoxLayout(m_rightGroupBox))
    , m_inputField(new QTextEdit(m_rightGroupBox))
    , m_outputField(new QTextEdit(m_rightGroupBox))
    , m_runButton(new QPushButton(m_rightGroupBox))
{
    m_ui->setupUi(this);

    m_leftLayout->addWidget(m_instructionTable);
    m_leftGroupBox->setLayout(m_leftLayout);

    m_mainLayout->addWidget(m_leftGroupBox);

    m_inputField->setPlaceholderText("Enter input here...");
    m_outputField->setPlaceholderText("Output will be shown here...");
    m_outputField->setReadOnly(true);

    m_rightLayout->addWidget(m_inputField);
    m_rightLayout->addWidget(m_outputField);

    setupRunButton();
    m_rightLayout->addWidget(m_runButton);

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

void MainWindow::setupRunButton()
{
    QIcon runIcon(":/icons/green_traingle.png");
    m_runButton->setFixedSize(40, 40);
    m_runButton->setIcon(runIcon);
    m_runButton->setIconSize(QSize(32, 32));
    m_runButton->setToolTip("Run");
    m_runButton->setFlat(true);
}

void MainWindow::onRunClicked()
{
    QString inputText = m_inputField->toPlainText();
    QString outputText = processInput(inputText);
    m_outputField->setText(outputText);
}

QString MainWindow::processInput(const QString &input)
{
    return "Processed: " + input;
}
