#ifndef GSSHAPECIRCLEITEM_H
#define GSSHAPECIRCLEITEM_H

#include "gsshapebaseitem.h"

class GsShapeCircleItem : public GsShapeBaseItem
{
public:
    explicit GsShapeCircleItem(QRectF rectF,QGraphicsObject *parent = 0);
    ~GsShapeCircleItem();
    bool hasSelected(QPointF pos);
    GsShapeType shapeType() const;

protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = Q_NULLPTR);
};


#endif // GSSHAPECIRCLEITEM_H
