#include "classover.h"
#include "ui_classover.h"

#include <windows.h>
#include <QMouseEvent>
bool m_bPressed=false;
QPoint m_point;
bool execmode=false,classinmoverexec=false,autoclickexec=false;

void ClassOver::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton){
        m_bPressed = true;
        m_point = event->pos();
    }
}

void ClassOver::mouseMoveEvent(QMouseEvent *event)
{
    if (m_bPressed)
        move(event->pos() - m_point + pos());
}

void ClassOver::mouseReleaseEvent(QMouseEvent *event)
{
    Q_UNUSED(event);
    m_bPressed = false;
}

ClassOver::ClassOver(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ClassOver)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);
}

ClassOver::~ClassOver()
{
    delete ui;
}


void ClassOver::on_pushButton_clicked()
{
    WinExec("taskkill /f /im ClassIn_Mover.exe",SW_HIDE);
    QApplication::exit();
}


void ClassOver::on_pushButton_2_clicked()
{
    WinExec("taskkill /f /im ClassIn_Mover.exe",SW_HIDE);
    WinExec("taskkill /f /im AutoClick.exe",SW_HIDE);
    ui->listWidget->takeItem(0);
    ui->listWidget->takeItem(0);
    classinmoverexec=false;
}


void ClassOver::on_commandLinkButton_clicked()
{
    if(!classinmoverexec){
        ui->listWidget->addItem("ClassIn_Mover.exe");
        if(execmode)WinExec("ClassIn_Mover.exe",SW_MINIMIZE);
        else WinExec("ClassIn_Mover.exe",SW_HIDE);
    }
    classinmoverexec=true;
}


void ClassOver::on_comboBox_currentTextChanged(const QString &arg1)
{
    if(arg1=="Minimized")execmode=1;
    else execmode=0;
}


void ClassOver::on_pushButton_4_clicked()
{
    ShowWindow(GetForegroundWindow(),SW_MINIMIZE);
}


void ClassOver::on_commandLinkButton_3_clicked()
{
    WinExec("C:\\Program Files (x86)\\ClassIn\\ClassIn.exe",SW_MAXIMIZE);
}


void ClassOver::on_commandLinkButton_2_clicked()
{
    if(!autoclickexec){
        ui->listWidget->addItem("AutoClick.exe");
        if(execmode)WinExec("AutoClick.exe",SW_MINIMIZE);
        else WinExec("AutoClick.exe",SW_HIDE);
        Sleep(20000);
        WinExec("taskkill /f /im AutoClick.exe",SW_HIDE);
        ui->listWidget->takeItem(1);
    }
    autoclickexec=true;
}

