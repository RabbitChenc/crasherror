/*
*
*brief:  获取xml文件中窗口的属性值
*
*author: Chenjm
*
*/

#ifndef HFWIDGET_FACADE_ATTR_H
#define HFWIDGET_FACADE_ATTR_H
#include <QString>

typedef struct{
    QString backgroundColor;
    QString foregroundColor;
}tHFWidgetFacadeAttri;



class HFWidgetFacadeAttrs
{
public:
    HFWidgetFacadeAttrs();
    virtual ~HFWidgetFacadeAttrs();
    const tHFWidgetFacadeAttri *getWidgetAttri();
    void setWidgetAttri(tHFWidgetFacadeAttri &widget);
    void widgetInfoParse();
    void debugTest(tHFWidgetFacadeAttri &state);

protected:
    tHFWidgetFacadeAttri attriWidget;
};

#endif // HFWIDGET_FACADE_ATTR_H
