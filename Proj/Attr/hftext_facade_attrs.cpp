#include "hftext_facade_attrs.h"
#include <QtDebug>
#include "../hfsin_hungry.h"

PtrHungry &hungryTextEdit = PtrHungry::getInstance();
QXmlStreamReader &xmlReaderTextEdit = hungryTextEdit.xmlReader;
HFTextFacadeAttrs::HFTextFacadeAttrs()
{
    setTextAttr(attriText);
}

HFTextFacadeAttrs::~HFTextFacadeAttrs()
{

}

const tHFTextFacadeAttr* HFTextFacadeAttrs::getTextAttr()
{
    return &attriText;
}
void HFTextFacadeAttrs::setTextAttr(tHFTextFacadeAttr&state)
{
    if(xmlReaderTextEdit.attributes().hasAttribute("background")){
        QString background = xmlReaderTextEdit.attributes().value("background").toString() ;
        if(background.startsWith("0x") || background.startsWith("0X")){
            state.background = background.mid(2);
        }else{
            state.background = background;
        }
    }
    if(xmlReaderTextEdit.attributes().hasAttribute("border")){
        QString border = xmlReaderTextEdit.attributes().value("border").toString() ;
        if(border.startsWith("0x") || border.startsWith("0X")){
            state.border = border.mid(2);
        }else{
            state.border = border;
        }
    }
    if(xmlReaderTextEdit.attributes().hasAttribute("solid-color")){
        QString solidColor = xmlReaderTextEdit.attributes().value("solid-color").toString() ;
        if(solidColor.startsWith("0x") || solidColor.startsWith("0X")){
            state.solidColor = solidColor.mid(2);
        }else{
            state.solidColor = solidColor;
        }
    }
    if(xmlReaderTextEdit.attributes().hasAttribute("color")){
        QString Color = xmlReaderTextEdit.attributes().value("color").toString() ;
        if(Color.startsWith("0x") || Color.startsWith("0X")){
            state.color = Color.mid(2);
        }else{
            state.color = Color;
        }
    }
}
void HFTextFacadeAttrs::debugTest(tHFTextFacadeAttr&state)
{
    qDebug()<<"color"<<state.color <<"bor"<<state.border<<\
           "bc"<<state.background<<"sc"<<state.solidColor;


}
