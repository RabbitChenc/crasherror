
/*
*
*brief      ：构建一个控件外观基类 成员变量 包含控件属性类
*             继承了object类
*             用来实现渲染外部控件的功能
*
*
*           控件外观基类
*           继承QWidget
*           成员变量包含 外观属性类
*           普通按钮控件外观类的父类
*
*author     ：Chenjm
*
*/

#ifndef HFVIEWFACADE_H
#define HFVIEWFACADE_H
#include <QObject>
#include<QWidget>
#include "./Attr/hfview_facade_attrs.h"

class HFViewFacade :public QWidget
{
public:
    HFViewFacade(QWidget *parent = nullptr);
    ~HFViewFacade();

protected:
    HFviewFacadeAttrs& vistViewAttri();
private:
    HFviewFacadeAttrs mViewAttri;
};

#endif // HFVIEWFACADE_H
