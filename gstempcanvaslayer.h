#ifndef WBTEMPCANVASLAYER_H
#define WBTEMPCANVASLAYER_H

#include <QGraphicsObject>
#include <QPainter>
#include "gscommondef.h"

class GsTempCanvasLayer : public QGraphicsObject
{
public:
    explicit GsTempCanvasLayer(const QSizeF & size,QGraphicsObject * parent = nullptr);
    ~GsTempCanvasLayer();
    void clear();  //清空画布
    void drawShape(GsShapeType type,QPointF p1,QPointF p2);

protected:
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

private:
    void initCanvas();                //初始化图层
private:
    QSizeF m_size;
    QImage   *m_pTempCanvas;//临时画布
    QPainter *m_pTempPainter = nullptr;//临时画布的painter
};

#endif // WBTEMPCANVASLAYER_H
