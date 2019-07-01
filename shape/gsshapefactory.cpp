#include "gsshapefactory.h"
#include "gsshapelineitem.h"
#include "gsshaperectangeitem.h"
#include "gsshapecircleitem.h"
#include "gsshapeovalitem.h"

GsShapeFactory::GsShapeFactory()
{

}

GsShapeFactory::~GsShapeFactory()
{

}

GsShapeBaseItem *GsShapeFactory::getShapeItem(GsShapeType type,QRectF rectF,
                                              QGraphicsObject *parent)
{
    GsShapeBaseItem * item = nullptr;
    switch (type) {
    case Shape_Line:
        item = new GsShapeLineItem(rectF,parent);
        break;
    case Shape_Rectange:
        item = new GsShapeRectangeItem(rectF,parent);
        break;
    case Shape_Circle:
        item = new GsShapeCircleItem(rectF,parent);
        break;
    case Shape_Oval:
        item = new GsShapeOvalItem(rectF,parent);
        break;
    default:
        break;
    }
    item->setZValue(10);
    return item;
}
