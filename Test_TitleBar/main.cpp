#include "test_titlebar.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Test_TitleBar w;
    w.show();
    return a.exec();
}
