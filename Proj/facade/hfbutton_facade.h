
/*
*
*brief:使用qpainter 画家类 自定义一个按钮控件
*      按钮继承了Qwidget 重写绘图事件 和鼠标相关的事件
*
*author: Chenjm
*
*/
#ifndef HFBUTTONFACADE_H
#define HFBUTTONFACADE_H
#include "../hfview_facade.h"
#include <QWidget>
#include <QColor>

class HFButtonFacade : public HFViewFacade
{
    Q_OBJECT
public:

    explicit HFButtonFacade(QWidget*parent = nullptr);
    virtual ~HFButtonFacade();

signals:
    void pressed();
    void released();
protected:
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);

    void drawImage(QPainter*painter);
    QPixmap* ninePatch(QString picName,int iHorzSplit,int iVertSplit, int DstWidth, int DstHeight);
    QPixmap generatePixmap(const QPixmap &src, const int w,const int h);

private:
    bool press;
    int btnWidth;
    int btnHight;
    int btnStyle;
    QString mImageName;

};

#endif // HFBUTTONFACADE_H
