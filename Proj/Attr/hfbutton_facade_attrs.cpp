
/*
*
*brief: 解析xml中btn部分的属性
*
*author:Chenjm
*/

#include "hfbutton_facade_attrs.h"
#include <QDebug>
#include <QString>
#include "../hfsin_hungry.h"


PtrHungry &hungry = PtrHungry::getInstance();
QXmlStreamReader &xmlReader = hungry.xmlReader;
HFButtonFacadeAttrs::HFButtonFacadeAttrs()
{
    BtnInfoParse();

}
const tHFButtonFacadeState* HFButtonFacadeAttrs::GetNormalAttrs()
{
    SetBtnAttrs(stateNormal);
    return &stateNormal;
}

const tHFButtonFacadeState* HFButtonFacadeAttrs::GetPressedAttrs()
{
   SetBtnAttrs(statePressd);
   return &statePressd;
}

const tHFButtonFacadeState* HFButtonFacadeAttrs::GetDisabledAttrs()
{
     SetBtnAttrs(stateDisabled);
     return &stateDisabled;
}


void HFButtonFacadeAttrs::SetBtnAttrs(tHFButtonFacadeState &state)
{
       if(xmlReader.attributes().hasAttribute("background")){

        QString backcolor = xmlReader.attributes().value("background").toString() ;
        if(backcolor.startsWith("0x") || backcolor.startsWith("0X")){
            state.backgroundColor = backcolor.mid(2);
        }else{
            state.backgroundColor = backcolor;
        }

    }
       //增加对数据进制的判断
    if(xmlReader.attributes().hasAttribute("left")){

        state.leftMargin = xmlReader.attributes().value("left").toString();
    }
    if(xmlReader.attributes().hasAttribute("top")){

        state.topMargin = xmlReader.attributes().value("top").toString();
    }
    if(xmlReader.attributes().hasAttribute("right")){

        state.rightMargin = xmlReader.attributes().value("right").toString();

    }
    if(xmlReader.attributes().hasAttribute("bottom")){

        state.bottomMargin = xmlReader.attributes().value("bottom").toString();
    }
    if(xmlReader.attributes().hasAttribute("text_color")){

        QString text_color = xmlReader.attributes().value("text_color").toString();
        if(text_color.startsWith("0x")|| text_color.startsWith("0X")){
            state.textColor = text_color.mid(2);
        }else{
            state.textColor = text_color;
        }
        state.imgFilename = xmlReader.readElementText();
    }
}


void HFButtonFacadeAttrs::debugTest(tHFButtonFacadeState &state)
{
    qDebug() << state.textColor << ";" << state.topMargin << ";" << state.leftMargin <<";"
             <<state.imgFilename <<";" << state.rightMargin <<";" << state.bottomMargin << ";"
             <<state.backgroundColor <<endl;
}


void HFButtonFacadeAttrs::BtnInfoParse()
{
    while(!xmlReader.atEnd()){
        QXmlStreamReader::TokenType token = xmlReader.readNext();
        if(token == QXmlStreamReader::StartElement){
           if(xmlReader.name() == "Normal"){
               GetNormalAttrs();
           }
           if(xmlReader.name() == "Press"){

               GetPressedAttrs();
           }
           if(xmlReader.name() == "Disabled"){

               GetDisabledAttrs();
           }
           if(xmlReader.name() == "Button"){

               break;
           }
        }
    }
}


HFButtonFacadeAttrs::~HFButtonFacadeAttrs()
{

}
