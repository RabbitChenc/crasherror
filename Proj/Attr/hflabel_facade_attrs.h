
/*
*
*brief:  获取xml文件中label的属性值
*
*author: Chenjm
*
*/

#ifndef HFLABEL_FACADE_ATTRS_H
#define HFLABEL_FACADE_ATTRS_H
#include <QString>
typedef struct{

    QString background;
    QString border;
    QString imageFile;
}tHFLabelFacadeAttr;


class HFLabelFacadeAttrs
{
public:
    HFLabelFacadeAttrs();
    virtual ~HFLabelFacadeAttrs();
    const tHFLabelFacadeAttr *getLabelAttr();
    void setLabelAttr(tHFLabelFacadeAttr &state);
    void debugTest(tHFLabelFacadeAttr& state);
private:
    tHFLabelFacadeAttr attrLabel;
};

#endif // HFLABEL_FACADE_ATTRS_H
