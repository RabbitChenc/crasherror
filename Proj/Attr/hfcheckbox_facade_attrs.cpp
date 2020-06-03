#include "hfcheckbox_facade_attrs.h"
#include "../hfsin_hungry.h"
#include <QDebug>

PtrHungry &hungryCheckBox = PtrHungry::getInstance();
QXmlStreamReader &xmlReaderCheckBox = hungryCheckBox.xmlReader;
HFCheckboxFacadeAttrs::HFCheckboxFacadeAttrs()
{
    setCheckBoxAttr(attricheckBox);
}

HFCheckboxFacadeAttrs::~HFCheckboxFacadeAttrs()
{

}
const tHFCheckBoxFacadeState*HFCheckboxFacadeAttrs::getCheckBoxAttr()
{
    return  &attricheckBox;
}
void HFCheckboxFacadeAttrs::setCheckBoxAttr(tHFCheckBoxFacadeState&state)
{
    if(xmlReaderCheckBox.attributes().hasAttribute("background")){
        QString backcolor = xmlReaderCheckBox.attributes().value("background").toString() ;
        if(backcolor.startsWith("0x") || backcolor.startsWith("0X")){
            state.backgroundColor = backcolor.mid(2);
        }else{
            state.backgroundColor = backcolor;
        }
    }
        if(xmlReaderCheckBox.attributes().hasAttribute("spacing")){
            QString space = xmlReaderCheckBox.attributes().value("spacing").toString() ;
            if(space.startsWith("0x") || space.startsWith("0X")){
                state.space = space.mid(2);
            }else{
                state.space = space;
        }
    }
}



 void HFCheckboxFacadeAttrs::debugTest(tHFCheckBoxFacadeState &state)
 {
    qDebug() << "bc" <<state.backgroundColor << "space" <<state.space;
 }


