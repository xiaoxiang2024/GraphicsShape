#ifndef GSSHAPELINEITEM_H
#define GSSHAPELINEITEM_H

#include "gsshapebaseitem.h"

class GsShapeLineItem : public GsShapeBaseItem
{
public:
    explicit GsShapeLineItem(QRectF rectF,QGraphicsObject *parent = 0);
    ~GsShapeLineItem();
    bool hasSelected(QPointF pos);
    GsShapeType shapeType() const;

protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = Q_NULLPTR);
};

#endif // GSSHAPELINEITEM_H
