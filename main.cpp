#include "mainwindow.h"

#include <QApplication>
#include <QScreen>
#include <Windows.h>

QColor getcolor(int x,int y){
    QScreen *screen = qApp->primaryScreen();
    QPixmap pixmap = screen->grabWindow(0, x, y, 0, 0);
    QImage image = pixmap.toImage();
    return image.pixel(0,0);
}

void mouse_click(int x,int y){
    SetCursorPos(x, y);
    mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
    mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    while(1)
        for(int i=200;i<GetSystemMetrics(SM_CXSCREEN);i+=400)
            for(int j=200;j<GetSystemMetrics(SM_CYSCREEN);j+=400){
                if(getcolor(i,j).green()>120&&getcolor(i,j).red()<40&&getcolor(i,j).blue()<100&&getcolor(i,j).blue()>80){
                   mouse_click(i+200,j);
                }
                QApplication::processEvents();
            }
    return a.exec();
}
