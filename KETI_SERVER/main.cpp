#include "KETI_SERVER.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    KETI_SERVER w;
    w.show();
    return a.exec();
}
