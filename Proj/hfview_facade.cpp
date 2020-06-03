#include "hfview_facade.h"
#include <QDebug>
//外观类的处理
HFViewFacade::HFViewFacade(QWidget *parent):QWidget(parent)
{
    qDebug()<<"控件外观基类的构造函数";
}

HFViewFacade::~HFViewFacade()
{
    qDebug()<<"控件外观基类的西沟函数";
}

 HFviewFacadeAttrs& HFViewFacade::vistViewAttri()
 {
    return mViewAttri;
 }
