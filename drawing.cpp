#include "drawing.h"
#include <QPointF>
#include <QPixmap>
#include <QPainter>
#include <QColor>

drawing::drawing()
{

}

void drawing::lineBresenham(QPainter *canvas, QPointF *p1, QPointF *p2, int width, QColor color)
{
    QPen pen(color,width,Qt::SolidLine);
    canvas->setPen(pen);

    int dx=p2->x()-p1->x();
    int dy=p2->y()-p1->y();

    int x=p1->x();
    int y=p1->y();

    int steps;
    if(abs(dx)>abs(dy)){
        steps=dx;
    }else{
        steps=dy;
    }

    canvas->drawPoint(x,y);

    int G= 2*dy-dx;

    int i;
    for(i=0;i<steps;i++)
    {
        if(G>=0)
        {
            x=x+1;
            y=y+1;
            canvas->drawPoint(x,y);
            G=G+2*(dy-dx);
        }
        else
        {
            x=x+1;
            canvas->drawPoint(x,y);
            G=G+2*dy;
        }
    }
}

void drawing::lineDDA(QPainter *canvas, QPointF *p1, QPointF *p2, int width, QColor color)
{
        QPen pen(color,width,Qt::SolidLine);
        canvas->setPen(pen);
        float x,y,xinc,yinc;
        int dx=(p2->x()-p1->x());
        int dy=(p2->y()-p1->y());
        int len;
        if(abs(dx)>=abs(dy))
            len=dx;
        else
            len=dy;
        xinc=float(dx)/len;
        yinc=float(dy/len);
        x=p1->x();
        y=p1->y();
        canvas->drawPoint(x,y);

        int i;
        for(i=1;i<=len;i++)
        {
            x=x+xinc;
            y=y+yinc;
            canvas->drawPoint(x,y);
        }
}

void drawing::circleBresenham(QPainter *canvas, QPointF *point, int r, int width, QColor color)
{
    int x=0;
    int y=r;
    int xc=point->x();
    int yc=point->y();
    int p;
    canvas->drawPoint(xc+x,yc-y);
    canvas->setPen(QPen(color,width,Qt::SolidLine));
    p=3-(2*r);
    for(x=0;x<=y;x++)
    {
        if(p<0)
        {
            y=y;
            p=(p+(4*x)+6);
        }
        else
        {
            y=y-1;
            p=p+((4*(x-y)+10));
        }
        canvas->drawPoint(xc+x,yc-y);
        canvas->drawPoint(xc-x,yc-y);
        canvas->drawPoint(xc+x,yc+y);
        canvas->drawPoint(xc-x,yc+y);
        canvas->drawPoint(xc+y,yc-x);
        canvas->drawPoint(xc-y,yc-x);
        canvas->drawPoint(xc+y,yc+x);
        canvas->drawPoint(xc-y,yc+x);
    }
}

void drawing::triangle(QPainter* canvas, QPointF *p1, QPointF *p2, QPointF *p3, int width, QColor color)
{
    lineBresenham(canvas,p1,p2,width,color);
    lineBresenham(canvas,p2,p3,width,color);
    lineBresenham(canvas,p3,p1,width,color);
}

void drawing::triangle(QPainter *canvas, QPointF *p, int angle, int length, int width, QColor color)
{
    wingA = rotate(p,angle+30,length);
    wingB = rotate(p,angle-30,length);

    triangle(canvas, p, wingA, wingB, width, color);
}

void drawing::lineBresenhamWithAngle(QPainter* canvas, QPointF *posicion_actual, int angle, int length, int width, QColor color)
{
    qreal new_x, new_y;

    float fradians = qDegreesToRadians((float)angle);

    qreal radians = (qreal)fradians;
    new_x = (qreal)(posicion_actual->x() + length * qCos(radians));
    new_y = (qreal)(posicion_actual->y() + length * qSin(radians));

    QPointF* new_point = new QPointF(new_x, new_y);
    lineBresenham(canvas, posicion_actual, new_point,width,color);
}

QPointF *drawing::rotate(QPointF *posicion_actual, int angle, int length)
{
    qreal new_x, new_y;

    float fradians = qDegreesToRadians((float)angle);

    qreal radians = (qreal)fradians;
    new_x = (qreal)(posicion_actual->x() + length * qCos(radians));
    new_y = (qreal)(posicion_actual->y() + length * qSin(radians));

    QPointF* new_point = new QPointF(new_x, new_y);
    return new_point;
}
