#include "Puller.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Puller w;
    w.show();
    return a.exec();
}
