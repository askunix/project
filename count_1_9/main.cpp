#include "widget.h"
#include <QApplication>

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    Widget w;
    w.setWindowTitle("count_1.0");

    w.show();

    return a.exec();
}
