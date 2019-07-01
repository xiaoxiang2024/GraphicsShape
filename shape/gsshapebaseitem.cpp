#include "gsshapebaseitem.h"

GsShapeBaseItem::GsShapeBaseItem(QRectF rectF,QGraphicsObject *parent):
    QGraphicsObject(parent),
    m_boundRectF(rectF)
{
    setFlag(ItemIsSelectable,true);
    setFlag(ItemIsMovable,true);
//    setAcceptHoverEvents(true);
}

GsShapeBaseItem::~GsShapeBaseItem()
{

}

int GsShapeBaseItem::type() const
{
    return Type_ShapeItem;
}

void GsShapeBaseItem::drawShape(QPointF p1, QPointF p2)
{
    m_firstPoint = p1;
    m_lastPoint = p2;
    update();
}

QRectF GsShapeBaseItem::boundingRect() const
{
    return m_boundRectF;
}
