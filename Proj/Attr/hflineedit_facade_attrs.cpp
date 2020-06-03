#include "hflineedit_facade_attrs.h"
#include <QtDebug>
#include "../hfsin_hungry.h"

PtrHungry &hungryLineEdit = PtrHungry::getInstance();
QXmlStreamReader &xmlReaderLineEdit = hungryLineEdit.xmlReader;

HFLineEditFacadeAttrs::HFLineEditFacadeAttrs()
{

    setLineEditAttr(attrLineEdit);
}

HFLineEditFacadeAttrs::~HFLineEditFacadeAttrs()
{

}

const tHFLineEditFacadeAttri*HFLineEditFacadeAttrs::getLineEditAttr()
{
    return &attrLineEdit;
}

void HFLineEditFacadeAttrs::setLineEditAttr(tHFLineEditFacadeAttri & state)
{
    if(xmlReaderLineEdit.attributes().hasAttribute("solide")){
        QString solide = xmlReaderLineEdit.attributes().value("solide").toString() ;
        if(solide.startsWith("0x") || solide.startsWith("0X")){
            state.solid = solide.mid(2);
        }else{
            state.solid = solide;
        }
    }
    if(xmlReaderLineEdit.attributes().hasAttribute("border-radius")){
        QString borderRadius = xmlReaderLineEdit.attributes().value("border-radius").toString() ;
        if(borderRadius.startsWith("0x") || borderRadius.startsWith("0X")){
            state.borderRadius = borderRadius.mid(2);
        }else{
            state.solid = borderRadius;
        }
    }
    if(xmlReaderLineEdit.attributes().hasAttribute("height")){
        QString height = xmlReaderLineEdit.attributes().value("height").toString() ;
        if(height.startsWith("0x") || height.startsWith("0X")){
            state.borderRadius = height.mid(2);
        }else{
            state.height = height;
        }
    }
    if(xmlReaderLineEdit.attributes().hasAttribute("border")){
        QString border = xmlReaderLineEdit.attributes().value("border").toString() ;
        if(border.startsWith("0x") || border.startsWith("0X")){
            state.borderRadius = border.mid(2);
        }else{
            state.solid = border;
        }
    }
    if(xmlReaderLineEdit.attributes().hasAttribute("solid")){
        QString solid = xmlReaderLineEdit.attributes().value("solid").toString() ;
        if(solid.startsWith("0x") || solid.startsWith("0X")){
            state.borderRadius = solid.mid(2);
        }else{
            state.solid = solid;
        }
    }
    debugTest(state);
}

void HFLineEditFacadeAttrs::debugTest(tHFLineEditFacadeAttri & state)
{
    qDebug() << "solide"<<state.solid<<"border"<<state.border << "height"\
             <<state.height<<"background" <<state.backgroung<<"radius"<<state.borderRadius;
}
