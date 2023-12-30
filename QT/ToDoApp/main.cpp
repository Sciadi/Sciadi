#include "todoapp.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ToDoApp w;
    w.show();
    return a.exec();
}
