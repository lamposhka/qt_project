#include "game.h"
#include "screencontroller.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    ScreenController w;
    ScreenController w;
    w.show();
    return a.exec();
}
