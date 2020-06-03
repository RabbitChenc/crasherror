#include "hflabel_facade_attrs.h"
#include <QDebug>
#include "../hfsin_hungry.h"
PtrHungry &hungryLabel = PtrHungry::getInstance();
QXmlStreamReader &xmlReaderLabel = hungryLabel.xmlReader;
HFLabelFacadeAttrs::HFLabelFacadeAttrs()
{
    setLabelAttr(attrLabel);
}
HFLabelFacadeAttrs::~HFLabelFacadeAttrs()
{

}
const tHFLabelFacadeAttr *HFLabelFacadeAttrs::getLabelAttr()
{
    return &attrLabel;
}
void HFLabelFacadeAttrs::setLabelAttr(tHFLabelFacadeAttr &state)
{
    if(xmlReaderLabel.attributes().hasAttribute("background")){
        QString backcolor = xmlReaderLabel.attributes().value("background").toString() ;
        if(backcolor.startsWith("0x") || backcolor.startsWith("0X")){
            state.background = backcolor.mid(2);
        }else{
            state.background = backcolor;
        }
    }
    if(xmlReaderLabel.attributes().hasAttribute("border")){
        QString border = xmlReaderLabel.attributes().value("border").toString() ;
        if(border.startsWith("0x") || border.startsWith("0X")){
            state.border = border.mid(2);
        }else{
            state.border = border;
        }
    }
     state.imageFile = xmlReaderLabel.readElementText();
     debugTest(state);
}
void HFLabelFacadeAttrs::debugTest(tHFLabelFacadeAttr& state)
{

    qDebug()<<"bc" <<state.background << "bo"<<state.border <<"imf"<<state.imageFile;

}
