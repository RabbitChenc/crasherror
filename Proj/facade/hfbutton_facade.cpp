#include "hfbutton_facade.h"
#include <QPainter>
#include <QtDebug>

HFButtonFacade::HFButtonFacade(QWidget*parent):HFViewFacade(parent),btnWidth(100),btnHight(40)
{
    press = false;
    resize(btnWidth,btnHight);
    qDebug() <<"普通按键类 构造函数";
}

HFButtonFacade::~HFButtonFacade()
{

}

void HFButtonFacade::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setRenderHint(QPainter::TextAntialiasing);
    drawImage(&painter);
}

//鼠标的按下事件重写
void HFButtonFacade::mousePressEvent(QMouseEvent *event)
{
   press = true;
   emit pressed();
   repaint();
}

//鼠标的松开事件重写
void HFButtonFacade::mouseReleaseEvent(QMouseEvent *event)
{
    press = false;
    emit released();
    repaint();
}

void HFButtonFacade::drawImage(QPainter*painter)
{
    QPixmap pixmap;
    if(press){
         mImageName = vistViewAttri().getBtnAttri()->GetNormalAttrs()->imgFilename;
    }else{

         mImageName = vistViewAttri().getBtnAttri()->GetPressedAttrs()->imgFilename;//这一句仍然 没有被执行
        qDebug() << "mimaaggename" <<mImageName;
    }

//    if(press){
//         mImageName = "/home/rabbitchenc/Qt/btn_custom/btn2_normal.png";
//    }else{
//         mImageName = "/home/rabbitchenc/Qt/btn_custom/btn2_pressed.png";
//    }

    qDebug() << "mimaaggename" <<mImageName;

    pixmap = QPixmap(mImageName);
    int pixWidth = pixmap.width();
    int pixHeight = pixmap.height();
    pixmap = *ninePatch(mImageName,pixWidth/3,pixHeight/3, width(),height());
    pixmap = generatePixmap(pixmap,width(),height());
    painter->drawPixmap(0,0,width(),height(),pixmap);

}


/*
**  功能             : 九宫格图处理
**  picName          : 图片名字
**  iHorzSplit       : 四个角上格子的宽度
**  iVertSplit       : 四个角上格子的高度
**  DstWidth         : 整个图片缩放的宽度
**  DstWidth         : 整个图片缩放的高度
**  返回值           : 处理完成的图片
*/

 QPixmap* HFButtonFacade::ninePatch(QString picName,int iHorzSplit,int iVertSplit, int DstWidth, int DstHeight)
 {
     QPixmap * pix = new QPixmap(picName);
     int pixWidth = pix->width();
     int pixHeight = pix->height();

     //将原图分割成九部分
     QPixmap pix_1 = pix->copy(0,0,iHorzSplit,iVertSplit);
     QPixmap pix_2 = pix->copy(iHorzSplit, 0, pixWidth-iHorzSplit*2, iVertSplit);
     QPixmap pix_3 = pix->copy(pixWidth-iHorzSplit, 0, iHorzSplit, iVertSplit);

     QPixmap pix_4 = pix->copy(0, iVertSplit, iHorzSplit, pixHeight-iVertSplit*2);
     QPixmap pix_5 = pix->copy(iHorzSplit, iVertSplit, pixWidth-iHorzSplit*2, pixHeight-iVertSplit*2);
     QPixmap pix_6 = pix->copy(pixWidth-iHorzSplit, iVertSplit, iHorzSplit, pixHeight-iVertSplit*2);

     QPixmap pix_7 = pix->copy(0, pixHeight-iVertSplit, iHorzSplit, iVertSplit);
     QPixmap pix_8 = pix->copy(iHorzSplit, pixHeight-iVertSplit, pixWidth-iHorzSplit*2, pixWidth - iHorzSplit*2);
     QPixmap pix_9 = pix->copy(pixWidth-iHorzSplit, pixHeight-iVertSplit, iHorzSplit, iVertSplit);

     //2 4 5 6 8 图 进行缩放
     pix_2 = pix_2.scaled(DstWidth-iHorzSplit*2,iVertSplit, Qt::IgnoreAspectRatio);//保持高度拉宽
     pix_4 = pix_4.scaled(iHorzSplit, DstHeight-iVertSplit*2, Qt::IgnoreAspectRatio);//保持宽度拉高
     pix_5 = pix_5.scaled(DstWidth-iHorzSplit*2,DstHeight-iVertSplit*2, Qt::IgnoreAspectRatio);//宽高都缩放
     pix_6 = pix_6.scaled(iHorzSplit, DstHeight-iVertSplit*2, Qt::IgnoreAspectRatio);//保持宽度拉高
     pix_8 = pix_8.scaled(DstWidth-iHorzSplit*2, iVertSplit);//保持高度拉宽


     QPixmap* resultImag = new QPixmap(DstWidth,DstHeight);
     QPainter*respainter = new QPainter(resultImag);
     if(!resultImag->isNull()){
         respainter->drawPixmap(0,0,pix_1);
         respainter->drawPixmap(iHorzSplit,0,pix_2);
         respainter->drawPixmap(DstWidth-iHorzSplit,0,pix_3);
         respainter->drawPixmap(0, iVertSplit, pix_4);
         respainter->drawPixmap(iHorzSplit, iVertSplit, pix_5);
         respainter->drawPixmap(DstWidth-iHorzSplit, iVertSplit, pix_6);

         respainter->drawPixmap(0, DstHeight-iVertSplit, pix_7);
         respainter->drawPixmap(iHorzSplit, DstHeight-iVertSplit, pix_8);
         respainter->drawPixmap(DstWidth-iHorzSplit, DstHeight-iVertSplit, pix_9);
         respainter->end();
     }
     return  resultImag;
 }


 /*
 ** 功能          ：方形图片边角处理
 ** src          ：原图片
 ** w            : 图片的宽
 ** h            : 图片的高
 */

 QPixmap HFButtonFacade::generatePixmap(const QPixmap &src, const int w,const int h) {

        if (src.isNull()) {
            return src;
        }
        QPixmap pixmap = QPixmap(src);

        QPixmap dest(w, h);
        dest.fill(Qt::transparent);
        QPainter painter(&dest);
        painter.setRenderHints(QPainter::Antialiasing, true);
        painter.setRenderHints(QPainter::SmoothPixmapTransform, true);
        QPainterPath path;
        path.addRect(0, 0, w, h);
        painter.setClipPath(path);
        painter.drawPixmap(0, 0, w, h, pixmap);

        return dest;
    }
