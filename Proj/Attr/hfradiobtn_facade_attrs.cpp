#include "hfradiobtn_facade_attrs.h"
#include <QtDebug>
#include "../hfsin_hungry.h"

PtrHungry &hungryRadioBtn = PtrHungry::getInstance();
QXmlStreamReader &xmlReaderRadioBtn = hungryRadioBtn.xmlReader;

HFRadiobtnFacadeAttrs::HFRadiobtnFacadeAttrs()
{
    setRadioBtnAtrr(attrRadioButton);
}
HFRadiobtnFacadeAttrs::~HFRadiobtnFacadeAttrs()
{

}

const tHFRadiobtnFacadeAttr* HFRadiobtnFacadeAttrs::getRadioAttr()
{
    return &attrRadioButton;
}

void HFRadiobtnFacadeAttrs::setRadioBtnAtrr(tHFRadiobtnFacadeAttr &state)
{
    if(xmlReaderRadioBtn.attributes().hasAttribute("background")){
        QString backcolor = xmlReaderRadioBtn.attributes().value("background").toString() ;
        if(backcolor.startsWith("0x") || backcolor.startsWith("0X")){
            state.background = backcolor.mid(2);
        }else{
            state.background = backcolor;
        }
    }
    if(xmlReaderRadioBtn.attributes().hasAttribute("spacing")){
        QString spacing = xmlReaderRadioBtn.attributes().value("spacing").toString() ;
        if(spacing.startsWith("0x") || spacing.startsWith("0X")){
            state.background = spacing.mid(2);
        }else{
            state.background = spacing;
        }
    }
    debugTest(state);
}
void HFRadiobtnFacadeAttrs::debugTest(tHFRadiobtnFacadeAttr & state)
{
    qDebug() << "space"<<state.spacing<<"bc"<<state.background;
}
