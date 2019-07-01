#include "gsrootitem.h"
#include <QDebug>
#include "gsshapebaseitem.h"
#include "gsshapelineitem.h"
#include <QGraphicsScene>

GsRootItem::GsRootItem(const QSizeF &size, QGraphicsObject *parent):
    QGraphicsObject (parent),
    m_size(size)
{
    m_pTempLayer = new GsTempCanvasLayer(size,this);
    m_pTempLayer->setZValue(10);

    m_pShapeFactory = new GsShapeFactory();
}

GsRootItem::~GsRootItem()
{
    SAFE_DELETE(m_pShapeFactory);
}

void GsRootItem::drawPress(int id, const QPointF &p)
{
    ShapeInfo info;
    info.firstPos = p;
    info.type = getCurType();
    m_Objs.insert(id,info);
}

void GsRootItem::drawMove(int id, const QPointF &lastPoint, const QPointF &curPoint)
{
    if(!m_Objs.contains(id)){
        return;
    }
    ShapeInfo info = m_Objs.value(id);
    m_pTempLayer->drawShape(info.type,info.firstPos,curPoint);
}

void GsRootItem::drawRelease(int id, const QPointF &point)
{
    if(!m_Objs.contains(id)){
        return;
    }
    ShapeInfo info = m_Objs.value(id);
    drawRealShape(info.type,info.firstPos,point);
    m_Objs.remove(id);
    m_pTempLayer->clear();
}

void GsRootItem::clear()
{
    QList<QGraphicsItem*> items = this->childItems();
    QList<QGraphicsItem*>::iterator it = items.begin();
    while(it != items.end()){
        QGraphicsItem* item = *it++;
        if(item->type() == Type_ShapeItem){
            delete item;
            item = nullptr;
        }
    }
}

QRectF GsRootItem::boundingRect() const
{
    return  QRectF(0,0,m_size.width(),m_size.height());
}

void GsRootItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(Qt::NoPen);
    painter->setBrush(Qt::white);
    painter->drawRect(this->boundingRect());
}

void GsRootItem::drawRealShape(GsShapeType type, QPointF p1, QPointF p2)
{
    //计算图形绘制区域
    QRectF rect;
    rect.setX(qMin(p1.x(),p2.x()));
    rect.setY(qMin(p1.y(),p2.y()));
    if(type == Shape_Circle){
        rect.setWidth(qAbs(p1.y() - p2.y()));
        rect.setHeight(qAbs(p1.y() - p2.y()));
    }
    else{
        rect.setWidth(qAbs(p1.x() - p2.x()));
        rect.setHeight(qAbs(p1.y() - p2.y()));
    }
    rect.adjust(-5,-5,5,5);
    GsShapeBaseItem * item = m_pShapeFactory->getShapeItem(type,rect,this);
    item->drawShape(p1,p2);
}
