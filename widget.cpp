#include "widget.h"
#include "ui_widget.h"
#include "./Proj/facade/hfbutton_facade.h"
#include <QPushButton>
#include <QtDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    //1，先解析 xml文件  调用外观属性 解析函数
    //存在的问题的原因  在给文件赋名之前 就已经打开文件的动作
    xmlAttrs = new HFviewFacadeAttrs();
//
//    btn->

}

void Widget::InfoDel()
{
//    xmlAttrs->setKeyNAme(strName);
//    int result =xmlAttrs->setFileInfo();//应该在按键 的构造函数中 进行处理？
//    if(result >0){
//        HFButtonFacade *btn = new HFButtonFacade(this);
//        btn->resize(100,100);
//    }
}

Widget::~Widget()
{
    delete ui;
    if(xmlAttrs != NULL){
        delete  xmlAttrs;
        xmlAttrs = NULL;
    }
}

