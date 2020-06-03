/*
 *brief         :用于测试自定义的控件是否可以成功的被 调用
 *
 *
 * author       :Chenjm
 *
*/

#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "./Proj/Attr/hfview_facade_attrs.h"
QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
class HFviewFacadeAttrs;//控件的外观属性类
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    void InfoDel();

private:
    Ui::Widget *ui;
public:
    QString strName;//？？？
    HFviewFacadeAttrs * xmlAttrs;
};
#endif // WIDGET_H
