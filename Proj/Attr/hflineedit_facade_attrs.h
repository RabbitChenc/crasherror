/*
*
*brief:  获取xml文件中文本编辑框的属性值
*
*author: Chenjm
*
*/

#ifndef HFLINEEDIT_FACADE_ATTRS_H
#define HFLINEEDIT_FACADE_ATTRS_H
#include <QString>

typedef struct{
    QString backgroung;
    QString borderRadius;
    QString height;
    QString border;
    QString solid;
}tHFLineEditFacadeAttri;


class HFLineEditFacadeAttrs
{
public:
    HFLineEditFacadeAttrs();
    virtual ~HFLineEditFacadeAttrs();
    const tHFLineEditFacadeAttri*getLineEditAttr();
    void setLineEditAttr(tHFLineEditFacadeAttri & state);
    void debugTest(tHFLineEditFacadeAttri & state);

private:
    tHFLineEditFacadeAttri attrLineEdit;
};

#endif // HFLINEEDIT_FACADE_ATTRS_H
