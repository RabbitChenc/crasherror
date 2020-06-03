/*
 *brief     :打开窗口 并将参数传进来的文件名 传递给其他文件
 *
 *author    :Chenjm
 *
*/


#include "widget.h"
#include <QApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.strName = argv[1];
    qDebug() << "w.strname" <<w.strName;
    //调用我们的功能处理函数
//    w.InfoDel();
    w.show();
    return a.exec();
}
