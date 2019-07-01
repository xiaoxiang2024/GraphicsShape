#ifndef GSSHAPEBASEITEM_H
#define GSSHAPEBASEITEM_H

#include <QGraphicsItem>
#include "gscommondef.h"
#include <QDebug>

class GsShapeBaseItem : public QGraphicsObject
{
public:
    explicit GsShapeBaseItem(QRectF rectF,QGraphicsObject *parent = 0);
    virtual ~GsShapeBaseItem();
    virtual GsShapeType shapeType() const = 0;
    virtual void doPress(int id,const QPointF & pos){}
    virtual void doMove(int id,const QPointF & pos1,const QPointF & pos2) {}
    virtual void doRelease(int id,const QPointF & pos){}
    int type() const;
    void drawShape(QPointF p1, QPointF p2);
    virtual bool hasSelected(QPointF pos) = 0;  //是否被选中


protected:
    virtual QRectF boundingRect()const;

public:
    QPointF m_firstPoint;   //起始点
    QPointF m_lastPoint;    //最新点
private:
    QRectF m_boundRectF;
};

#endif // GSSHAPEBASEITEM_H
