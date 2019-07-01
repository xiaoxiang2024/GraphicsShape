#ifndef GSSHAPEOVALITEM_H
#define GSSHAPEOVALITEM_H

#include "gsshapebaseitem.h"

class GsShapeOvalItem : public GsShapeBaseItem
{
public:
    explicit GsShapeOvalItem(QRectF rectF,QGraphicsObject *parent = 0);
    ~GsShapeOvalItem();
    bool hasSelected(QPointF pos);
    GsShapeType shapeType() const;

protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = Q_NULLPTR);
};


#endif // GSSHAPEOVALITEM_H
