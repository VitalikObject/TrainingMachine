#pragma once

#include <QMainWindow>
#include <QtWidgets/qgroupbox.h>
#include "InstructionInterpreter.h"
#include "InstructionTable.h"
#include <QTextEdit>
#include <QPushButton>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onRunClicked();

private:
    void setupLayouts();
    void setupWidgets();
    void setupRunButton();
    void setupConnections();
    QWidget* createCentralWidget();

    QString processInput(const QString &input);

    Ui::MainWindow *m_ui;
    InstructionTable *m_instructionTable;
    InstructionInterpreter *m_instructionInterpreter;
    QTextEdit *m_inputField;
    QTextEdit *m_outputField;
    QPushButton *m_runButton;
    QVBoxLayout *m_leftLayout;
    QVBoxLayout *m_rightLayout;
    QHBoxLayout *m_mainLayout;
};
