#include "applicgaragewindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    cout << "wwwwwwwwwwwwwwwwwww" << endl;
    QApplication a(argc, argv);
    cout << "wwwwwwwwwwwwwwwwwww" << endl;
    ApplicGarageWindow w;
    cout << "wwwwwwwwwwwwwwwwwww" << endl;
    w.show();
    return a.exec();
}
