#include "classover.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ClassOver w;
    w.show();
    return a.exec();
}
