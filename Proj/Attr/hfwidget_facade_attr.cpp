#include "hfwidget_facade_attr.h"
#include <QtDebug>
#include "../hfsin_hungry.h"


PtrHungry &hungry1 = PtrHungry::getInstance();
QXmlStreamReader &xmlReader1 = hungry1.xmlReader;
HFWidgetFacadeAttrs::HFWidgetFacadeAttrs()
{
    setWidgetAttri(attriWidget);
}

const tHFWidgetFacadeAttri*HFWidgetFacadeAttrs::getWidgetAttri()
{
    return &attriWidget;
}
void HFWidgetFacadeAttrs::setWidgetAttri(tHFWidgetFacadeAttri &attr)
{
    if(xmlReader1.attributes().hasAttribute("background")){
        QString backcolor = xmlReader1.attributes().value("background").toString() ;
        if(backcolor.startsWith("0x") || backcolor.startsWith("0X")){
            attr.backgroundColor = backcolor.mid(2);
        }else{
            attr.backgroundColor = backcolor;
        }
    }
    if(xmlReader1.attributes().hasAttribute("foreground")){

        QString forecolor = xmlReader1.attributes().value("foreground").toString() ;
        if(forecolor.startsWith("0x") || forecolor.startsWith("0X")){
            attr.foregroundColor = forecolor.mid(2);

        }else{
            attr.foregroundColor = forecolor;
        }
    }
}





void HFWidgetFacadeAttrs::debugTest(tHFWidgetFacadeAttri &state)
{
    qDebug() << "widget:"<<state.backgroundColor<< ";" <<state.foregroundColor<<endl;
}

HFWidgetFacadeAttrs::~HFWidgetFacadeAttrs()
{

}
