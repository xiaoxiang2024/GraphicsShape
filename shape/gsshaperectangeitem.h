#ifndef GSSHAPERECTANGEITEM_H
#define GSSHAPERECTANGEITEM_H

#include "gsshapebaseitem.h"

class GsShapeRectangeItem : public GsShapeBaseItem
{
public:
    explicit GsShapeRectangeItem(QRectF rectF,QGraphicsObject *parent = 0);
    ~GsShapeRectangeItem();
    bool hasSelected(QPointF pos);
    GsShapeType shapeType() const;

protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = Q_NULLPTR);
};

#endif // GSSHAPERECTANGEITEM_H
