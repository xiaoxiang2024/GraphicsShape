#include "gsshapeitem.h"
#include <QPainter>
#include <QDebug>

GsShapeItem::GsShapeItem(GsShapeType type, QRectF rectF,QGraphicsObject *parent):
    m_boundRectF(rectF),
    QGraphicsObject(parent)
{
//    setCacheMode(ItemCoordinateCache);
    setFlags(ItemIsMovable | ItemIsSelectable);
    m_type = type;
}

GsShapeItem::~GsShapeItem()
{

}

QRectF GsShapeItem::boundingRect() const
{
    return m_boundRectF;
}

int GsShapeItem::type() const
{
    return Type_ShapeItem;
}

void GsShapeItem::drawShape(QPointF p1, QPointF p2)
{
    m_firstPoint = p1;
    m_lastPoint = p2;
    update();
}

void GsShapeItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setRenderHint(QPainter::Antialiasing);
    QColor color = Qt::red;//(rand()%255,rand()%255,rand()%255);
    painter->setBrush(color);
    painter->setPen(QPen(color,3,Qt::SolidLine,Qt::RoundCap,Qt::RoundJoin));
    switch (m_type) {
    case Shape_Line:
        painter->drawLine(m_firstPoint,m_lastPoint);
        break;
    case Shape_Rectange:
        painter->drawRect(QRectF(m_firstPoint,m_lastPoint));
        break;
    case Shape_Circle:
        painter->drawEllipse(m_firstPoint.x(),m_firstPoint.y(),
                             qAbs(m_lastPoint.y() - m_firstPoint.y()),
                             qAbs(m_lastPoint.y() - m_firstPoint.y()));
        break;
    case Shape_Oval:
        painter->drawEllipse(QRectF(m_firstPoint,m_lastPoint));
        break;
    default:
        break;
    }
}
