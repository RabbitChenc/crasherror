
#include "hfview_facade_attrs.h"
#include <QFile>
#include <QDebug>
//#include <QXmlStreamReader>
#include "../hfsin_hungry.h"

PtrHungry PtrHungry::sPtrHungry;

HFviewFacadeAttrs::HFviewFacadeAttrs()
{
    qDebug() << "外观属性类构造函数";
}
HFviewFacadeAttrs::~HFviewFacadeAttrs()
{
    if(pBtnAttrs!=NULL){
        delete pBtnAttrs;
        pBtnAttrs = NULL;
    }
}

int HFviewFacadeAttrs::setFileInfo()
{
    QFile qtFile(keyName);

     qDebug()<< "file name" << keyName;
    if(!qtFile.open(QIODevice::ReadOnly | QIODevice::Text))
    {
         qDebug()<< "Open failed." << endl;
         return -1;
    }
     qDebug()<< "Open file success";
    PtrHungry &hungry = PtrHungry::getInstance();
    QXmlStreamReader &xmlReader = hungry.xmlReader;

     xmlReader.setDevice(&qtFile);
     while(!xmlReader.atEnd()){

          QXmlStreamReader::TokenType token = xmlReader.readNext();
          if(token == QXmlStreamReader::StartElement){
            qDebug() << xmlReader.name() ;
//            if(xmlReader.name() == "Widget"){
//                qDebug()<<"wid~~";
//               pWidgetAttrs = new HFWidgetFacadeAttrs();
//            }

//            if(xmlReader.name() == "LineEdit"){

//                pLineEditAttrs = new HFLineEditFacadeAttrs();
//            }
//            if(xmlReader.name() == "TabWidget"){
//                pTabWidgetAttrs = new HFTabWidgetFacadeAttrs();
//            }
            if(xmlReader.name() == "Button"){

                pBtnAttrs = new HFButtonFacadeAttrs();
            }
//            if(xmlReader.name() == "CheckBox"){

//                pCheckBoxAttrs = new HFCheckboxFacadeAttrs();
//            }
//            if(xmlReader.name() =="RadioButton"){
//                pRadioAttrs = new HFRadiobtnFacadeAttrs();
//            }
//            if(xmlReader.name()=="Label"){
//                pLabelAttrs = new HFLabelFacadeAttrs();
//            }
//            if(xmlReader.name() =="TextEdit"){
//                pTextAttrs = new HFTextFacadeAttrs();
//            }
          }
      }

     qDebug()<< "xml file deal.fini" << endl;
     if(xmlReader.hasError()){
        qDebug() << "error in file " <<endl;
        return -2;
     }
     qtFile.close();
     return 0;
}

void HFviewFacadeAttrs::setKeyNAme(const QString&str)
{
    keyName = str;
}

HFButtonFacadeAttrs* HFviewFacadeAttrs::getBtnAttri()
 {
    return pBtnAttrs;
 }
 HFWidgetFacadeAttrs* HFviewFacadeAttrs::getWidgetAttri()
 {
     return pWidgetAttrs;
 }
 HFCheckboxFacadeAttrs*HFviewFacadeAttrs::getCheckBoxAttri()
 {
     return pCheckBoxAttrs;
 }

 HFLineEditFacadeAttrs*HFviewFacadeAttrs::getLineEditAttri()
 {
     return pLineEditAttrs;
 }

  HFTabWidgetFacadeAttrs* HFviewFacadeAttrs::getTabWidgetAttri()
  {
      return pTabWidgetAttrs;
  }

 HFRadiobtnFacadeAttrs* HFviewFacadeAttrs::getRadioBtnAtrri()
 {
        return  pRadioAttrs;
 }
HFLabelFacadeAttrs* HFviewFacadeAttrs::getLabelAttri()
 {
    return pLabelAttrs;
 }
 HFTextFacadeAttrs* HFviewFacadeAttrs::getTextAttri()
 {
     return pTextAttrs;
 }

