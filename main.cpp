#include "Widget.h"
#include "Snake.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Snake s;
    s.show();
//    Widget w;
//    w.show();
    return a.exec();
}
