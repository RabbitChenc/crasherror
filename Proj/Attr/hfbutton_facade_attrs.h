/*
*
*brief:  获取xml文件中按键的属性值
*
*author: Chenjm
*
*/

#ifndef HFBUTTON_FACADE_ATTRS_H
#define HFBUTTON_FACADE_ATTRS_H
#include <QXmlStreamAttribute>

typedef struct {
    QString leftMargin;
    QString topMargin;
    QString rightMargin;
    QString bottomMargin;
    QString backgroundColor;
    QString textColor;
    QString imgFilename;
} tHFButtonFacadeState;



class HFButtonFacadeAttrs
{
public:
    HFButtonFacadeAttrs();
    virtual ~HFButtonFacadeAttrs();
    const tHFButtonFacadeState * GetNormalAttrs();
    const tHFButtonFacadeState * GetPressedAttrs();
    const tHFButtonFacadeState * GetDisabledAttrs();

    void SetBtnAttrs(tHFButtonFacadeState& state);
    void BtnInfoParse(void);

    //用于测试是否分离正确
    void debugTest(tHFButtonFacadeState& state);
protected:
    tHFButtonFacadeState stateNormal;
    tHFButtonFacadeState statePressd;
    tHFButtonFacadeState stateDisabled;
};

#endif
