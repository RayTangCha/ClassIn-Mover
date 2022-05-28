#ifndef CLASSOVER_H
#define CLASSOVER_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class ClassOver; }
QT_END_NAMESPACE

class ClassOver : public QMainWindow
{
    Q_OBJECT

public:
    ClassOver(QWidget *parent = nullptr);
    ~ClassOver();
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_commandLinkButton_clicked();

    void on_comboBox_currentTextChanged(const QString &arg1);

    void on_pushButton_4_clicked();

private:
    Ui::ClassOver *ui;
};
#endif // CLASSOVER_H
