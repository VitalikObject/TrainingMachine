#include "MainWindow.h"
#include "./ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , m_ui(new Ui::MainWindow)
    , m_instructionTable(new InstructionTable(this))
    , m_inputField(new QTextEdit(this))
    , m_outputField(new QTextEdit(this))
    , m_runButton(new QPushButton(this))
{
    m_ui->setupUi(this);

    setupLayouts();
    setupWidgets();
    setupRunButton();
    setupConnections();
}

MainWindow::~MainWindow()
{
    delete m_ui;
    delete m_instructionTable;
    delete m_inputField;
    delete m_outputField;
    delete m_runButton;
    delete m_leftLayout;
    delete m_rightLayout;
    delete m_mainLayout;
}

void MainWindow::setupLayouts()
{
    m_mainLayout = new QHBoxLayout;

    m_leftLayout = new QVBoxLayout;
    m_leftLayout->addWidget(m_instructionTable);

    m_rightLayout = new QVBoxLayout;
    m_rightLayout->addWidget(m_inputField);
    m_rightLayout->addWidget(m_outputField);
    m_rightLayout->addWidget(m_runButton);

    m_mainLayout->addLayout(m_leftLayout);
    m_mainLayout->addLayout(m_rightLayout);

    setCentralWidget(createCentralWidget());
}

QWidget* MainWindow::createCentralWidget()
{
    QWidget *centralWidget = new QWidget(this);
    centralWidget->setLayout(m_mainLayout);
    return centralWidget;
}

void MainWindow::setupWidgets()
{
    m_inputField->setPlaceholderText("Enter input here...");
    m_outputField->setPlaceholderText("Output will be shown here...");
    m_outputField->setReadOnly(true);
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

void MainWindow::setupConnections()
{
    connect(m_runButton, &QPushButton::clicked, this, &MainWindow::onRunClicked);
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
