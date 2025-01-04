#pragma once

#include <QMainWindow>
#include <QtWidgets/qgroupbox.h>
#include "InstructionTable.h"

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
    void adjustWindowSize();

private:
    Ui::MainWindow *m_ui;
    InstructionTable *m_instructionTable;
    QWidget *m_centralWidget;
    QHBoxLayout *m_mainLayout;
    QGroupBox *m_leftGroupBox;
    QVBoxLayout *m_leftLayout;
    QGroupBox *m_rightGroupBox;
    QVBoxLayout *m_rightLayout;
};
