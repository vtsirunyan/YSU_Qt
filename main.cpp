#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    mainWindow* window = new mainWindow();

    window->show();
    return a.exec();
}
