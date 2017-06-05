#ifndef DRAWING_H
#define DRAWING_H
#include <QPointF>
#include <QPixmap>
#include <QPainter>
#include <QColor>

class drawing
{
public:
    drawing();
    static void lineBresenham(QPainter* canvas, QPointF* p1, QPointF* p2, int width=3, QColor color=Qt::green);
    static void lineDDA(QPainter* canvas, QPointF* p1, QPointF* p2, int width=3, QColor color = Qt::green);
    static void circleBresenham(QPainter* canvas, QPointF* point, int r, int width=3, QColor color = Qt::green);
    static void triangle(QPainter *canvas, QPointF *p1, QPointF *p2, QPointF *p3, int width=3, QColor color = Qt::green);
    static void triangle(QPainter* canvas, QPointF* p, int angle, int length=100, int width=3, QColor color = Qt::green);
    static void lineBresenhamWithAngle(QPainter* canvas, QPointF* posicion_actual, int angle, int length=100, int width=3, QColor color = Qt::green);
    static QPointF* rotate(QPointF* posicion_actual, int angle, int length=3);
};

#endif // DRAWING_H
