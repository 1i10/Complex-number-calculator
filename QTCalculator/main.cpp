#include "QTCalculator.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTCalculator w;
    w.setWindowTitle(QString::fromLocal8Bit("Калькулятор комплексных чисел"));
    w.show();
    return a.exec();
}
