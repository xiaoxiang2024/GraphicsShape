#include "gsshaperectangeitem.h"
#include <QPainter>

GsShapeRectangeItem::GsShapeRectangeItem(QRectF rectF, QGraphicsObject *parent):
    GsShapeBaseItem(rectF,parent)
{

}

GsShapeRectangeItem::~GsShapeRectangeItem()
{

}

bool GsShapeRectangeItem::hasSelected(QPointF pos)
{
    return shape().contains(pos);
}

GsShapeType GsShapeRectangeItem::shapeType() const
{
    return Shape_Rectange;
}

void GsShapeRectangeItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setRenderHint(QPainter::Antialiasing);
    QColor color = Qt::red;//(rand()%255,rand()%255,rand()%255);
    painter->setBrush(color);
    painter->setPen(QPen(color,3,Qt::SolidLine,Qt::RoundCap,Qt::RoundJoin));
    painter->drawRect(QRectF(m_firstPoint,m_lastPoint));
}
