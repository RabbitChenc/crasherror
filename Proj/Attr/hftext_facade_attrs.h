/*
*
*brief:  获取xml文件text文本的属性值
*
*author: Chenjm
*
*/
#ifndef HFTEXT_FACADE_ATTRS_H
#define HFTEXT_FACADE_ATTRS_H
#include <QString>

typedef struct{
    QString background;
    QString color;
    QString border;
    QString solidColor;
}tHFTextFacadeAttr;

class HFTextFacadeAttrs
{
public:
    HFTextFacadeAttrs();
    virtual ~HFTextFacadeAttrs();
    const tHFTextFacadeAttr* getTextAttr();
    void setTextAttr(tHFTextFacadeAttr&state);
    void debugTest(tHFTextFacadeAttr&state);
private:
    tHFTextFacadeAttr attriText;
};

#endif // HFTEXT_FACADE_ATTRS_H
