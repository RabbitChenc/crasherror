
/*
*
*brief:  获取xml文件中tabWidget的属性值
*
*author: Chenjm
*
*/

#ifndef HFTABWIDGET_FACADE_ATTRS_H
#define HFTABWIDGET_FACADE_ATTRS_H
#include <QString>

typedef struct{
 QString backgroundColor;
}tHFTabWidgetFacadeAttr;

class HFTabWidgetFacadeAttrs
{
public:
    HFTabWidgetFacadeAttrs();
    virtual ~HFTabWidgetFacadeAttrs();
    const tHFTabWidgetFacadeAttr* getTabWidgetAttr();
    void setTabWidgetAttr(tHFTabWidgetFacadeAttr&state);
    void debugTest(tHFTabWidgetFacadeAttr&state);
private:
    tHFTabWidgetFacadeAttr attriTabWidget;
};

#endif // HFTABWIDGET_FACADE_ATTRS_H
