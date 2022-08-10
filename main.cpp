#include "QtWebTools.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QtWebTools w;
    w.show();
    return a.exec();
}
