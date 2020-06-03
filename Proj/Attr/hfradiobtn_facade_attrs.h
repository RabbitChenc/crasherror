
/*
*
*brief:  获取xml文件中radiobutton的属性值
*
*author: Chenjm
*
*/

#ifndef HFRADIOBTN_FACADE_ATTRS_H
#define HFRADIOBTN_FACADE_ATTRS_H
#include <QString>

typedef struct{
    QString background;
    QString spacing;
}tHFRadiobtnFacadeAttr;

class HFRadiobtnFacadeAttrs
{
public:
    HFRadiobtnFacadeAttrs();
    virtual ~HFRadiobtnFacadeAttrs();
    const tHFRadiobtnFacadeAttr* getRadioAttr();
    void setRadioBtnAtrr(tHFRadiobtnFacadeAttr &statee);
    void debugTest(tHFRadiobtnFacadeAttr & state);

private:
    tHFRadiobtnFacadeAttr attrRadioButton;
};

#endif // HFRADIOBTN_FACADE_ATTRS_H
