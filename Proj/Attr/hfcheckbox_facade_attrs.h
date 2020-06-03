
/*
*
*brief:  获取xml文件中checkbox的属性值
*
*author: Chenjm
*
*/
#ifndef HFCHECKBOX_FACADE_ATTRS_H
#define HFCHECKBOX_FACADE_ATTRS_H
#include <QString>

typedef struct {

    QString backgroundColor;
    QString space;
} tHFCheckBoxFacadeState;



class HFCheckboxFacadeAttrs
{
public:
    HFCheckboxFacadeAttrs();
    virtual ~HFCheckboxFacadeAttrs();
    const tHFCheckBoxFacadeState*getCheckBoxAttr();
    void setCheckBoxAttr(tHFCheckBoxFacadeState&state);
    void checkInfoPrase();
    void debugTest(tHFCheckBoxFacadeState &state);

protected:
    tHFCheckBoxFacadeState attricheckBox;
};

#endif // HFCHECKBOX_FACADE_ATTRS_H
