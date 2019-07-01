#include "gsshapecircleitem.h"
#include <QPainter>

GsShapeCircleItem::GsShapeCircleItem(QRectF rectF, QGraphicsObject *parent):
    GsShapeBaseItem(rectF,parent)
{
}

GsShapeCircleItem::~GsShapeCircleItem()
{

}

bool GsShapeCircleItem::hasSelected(QPointF pos)
{
    QPainterPath path;
    path.addEllipse(boundingRect());

    return path.contains(pos);
}

GsShapeType GsShapeCircleItem::shapeType() const
{
    return Shape_Circle;
}

void GsShapeCircleItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setRenderHint(QPainter::Antialiasing);
    QColor color = Qt::red;//(rand()%255,rand()%255,rand()%255);
    painter->setBrush(color);
    painter->setPen(QPen(color,3,Qt::SolidLine,Qt::RoundCap,Qt::RoundJoin));

    painter->drawEllipse(m_firstPoint.x(),m_firstPoint.y(),
                         qAbs(m_lastPoint.y() - m_firstPoint.y()),
                         qAbs(m_lastPoint.y() - m_firstPoint.y()));
}
