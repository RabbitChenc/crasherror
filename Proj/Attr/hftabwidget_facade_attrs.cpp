#include "hftabwidget_facade_attrs.h"
#include <QtDebug>
#include "../hfsin_hungry.h"


PtrHungry &hungryTabWidget = PtrHungry::getInstance();
QXmlStreamReader &xmlReaderTabWidget = hungryTabWidget.xmlReader;
HFTabWidgetFacadeAttrs::HFTabWidgetFacadeAttrs()
{
    setTabWidgetAttr(attriTabWidget);
}
HFTabWidgetFacadeAttrs::~HFTabWidgetFacadeAttrs()
{

}
const tHFTabWidgetFacadeAttr* HFTabWidgetFacadeAttrs::getTabWidgetAttr()
{
    return &attriTabWidget;
}
void HFTabWidgetFacadeAttrs::setTabWidgetAttr(tHFTabWidgetFacadeAttr&state)
{
    if(xmlReaderTabWidget.attributes().hasAttribute("background")){
        QString backcolor = xmlReaderTabWidget.attributes().value("background").toString() ;
        if(backcolor.startsWith("0x") || backcolor.startsWith("0X")){
            state.backgroundColor = backcolor.mid(2);
        }else{
            state.backgroundColor = backcolor;
        }
    }
}
void HFTabWidgetFacadeAttrs::debugTest(tHFTabWidgetFacadeAttr&state)
{
    qDebug() << "tab"<< state.backgroundColor;
}
