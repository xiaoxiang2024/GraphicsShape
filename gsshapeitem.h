#ifndef GSSHAPEITEM_H
#define GSSHAPEITEM_H

#include <QGraphicsItem>
#include "gscommondef.h"

class GsShapeItem : public QGraphicsObject
{
public:
    explicit GsShapeItem(GsShapeType type,QRectF rectF,QGraphicsObject *parent = 0);
    ~GsShapeItem();

    void drawShape(QPointF p1,QPointF p2);
    int type() const;


protected:
    QRectF boundingRect()const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = Q_NULLPTR);

private:
    QRectF m_boundRectF;
    GsShapeType m_type;
    QPointF m_firstPoint;   //起始点
    QPointF m_lastPoint;    //最新点
};

#endif // GSSHAPEITEM_H
