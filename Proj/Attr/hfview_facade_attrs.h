/*
*
*brief      :解析出xml文件的属性
*           调用各种其他控件的属性保存类
*           对属性进行保存
*
*author     : Chenjm
*
*/

#ifndef HFVIEW_FACADE_ATTRS_H
#define HFVIEW_FACADE_ATTRS_H

#include "hfbutton_facade_attrs.h"
#include "hfwidget_facade_attr.h"
#include "hfcheckbox_facade_attrs.h"
#include "hflineedit_facade_attrs.h"
#include "hftabwidget_facade_attrs.h"
#include "hfradiobtn_facade_attrs.h"
#include "hflabel_facade_attrs.h"
#include "hftext_facade_attrs.h"

class HFviewFacadeAttrs
{
public:
    HFviewFacadeAttrs();
    virtual ~HFviewFacadeAttrs();
    int setFileInfo();
    void setKeyNAme(const QString&str);
    HFButtonFacadeAttrs* getBtnAttri();
    HFWidgetFacadeAttrs* getWidgetAttri();
    HFCheckboxFacadeAttrs* getCheckBoxAttri();
    HFLineEditFacadeAttrs* getLineEditAttri();
    HFTabWidgetFacadeAttrs* getTabWidgetAttri();
    HFRadiobtnFacadeAttrs* getRadioBtnAtrri();
    HFLabelFacadeAttrs* getLabelAttri();
    HFTextFacadeAttrs* getTextAttri();
private:
    QXmlStreamReader xmlReader;
    HFButtonFacadeAttrs *pBtnAttrs;
    HFWidgetFacadeAttrs *pWidgetAttrs;
    HFCheckboxFacadeAttrs *pCheckBoxAttrs;
    HFLineEditFacadeAttrs *pLineEditAttrs;
    HFTabWidgetFacadeAttrs *pTabWidgetAttrs;
    HFRadiobtnFacadeAttrs *pRadioAttrs;
    HFLabelFacadeAttrs *pLabelAttrs;
    HFTextFacadeAttrs *pTextAttrs;

    QString keyName;
};
#endif // HFVIEW_FACADE_ATTRS_H
