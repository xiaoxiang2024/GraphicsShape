#include "gstempcanvaslayer.h"
#include "gscommondef.h"
#include <QDebug>

GsTempCanvasLayer::GsTempCanvasLayer(const QSizeF &size, QGraphicsObject *parent):
    QGraphicsObject (parent),
    m_size(size)
{
    setCacheMode(ItemCoordinateCache);
    initCanvas();
}

GsTempCanvasLayer::~GsTempCanvasLayer()
{
    SAFE_DELETE(m_pTempPainter);
    SAFE_DELETE(m_pTempCanvas);
    qDebug() << "--->>>Lynn<<<---" << __FUNCTION__;
}

void GsTempCanvasLayer::clear()
{
    m_pTempCanvas->fill(Qt::transparent);
    this->update();
}

QRectF GsTempCanvasLayer::boundingRect() const
{
    return  QRectF(0,0,m_size.width(),m_size.height());
}

void GsTempCanvasLayer::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawImage(0,0,*m_pTempCanvas);
}

void GsTempCanvasLayer::drawShape(GsShapeType type, QPointF p1, QPointF p2)
{
    m_pTempCanvas->fill(Qt::transparent);
    m_pTempPainter->setRenderHint(QPainter::Antialiasing, true);
    m_pTempPainter->setCompositionMode(QPainter::CompositionMode_Source);
    m_pTempPainter->setPen(QPen(Qt::red,3, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
    switch(type){
    case Shape_Line:
        m_pTempPainter->drawLine(p1,p2);
        break;
    case Shape_Rectange:
        m_pTempPainter->drawRect(QRectF(p1,p2));
        break;
    case Shape_Circle:
        m_pTempPainter->drawEllipse(p1.x(),p1.y(),
                             qAbs(p2.y() - p1.y()),
                             qAbs(p2.y() - p1.y()));
        break;
    case Shape_Oval:
        m_pTempPainter->drawEllipse(QRectF(p1,p2));
        break;
    default:
        break;
    }
    update();
}

void GsTempCanvasLayer::initCanvas()
{
    m_pTempCanvas = new QImage(m_size.toSize(),QImage::Format_ARGB32_Premultiplied);
    m_pTempCanvas->fill(Qt::transparent);
    m_pTempPainter = new QPainter(m_pTempCanvas);
}
