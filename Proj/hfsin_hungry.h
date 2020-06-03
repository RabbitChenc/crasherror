/*
 *brief: 创建一个单例 用于维护一个全局变量 QXmlStreamReader
 *       QXmlStreamReader用来读取xml文件
 *
 *author: cm
 *
*/


#ifndef PTRHUNGRY_H
#define PTRHUNGRY_H
#include <QXmlStreamReader>

class PtrHungry
{

public:
    static PtrHungry& getInstance(void){return sPtrHungry;};
private:
    PtrHungry(){};
    PtrHungry(const PtrHungry&){};
    static PtrHungry sPtrHungry;
public:
    QXmlStreamReader xmlReader;
};
#endif // PTRHUNGRY_H
