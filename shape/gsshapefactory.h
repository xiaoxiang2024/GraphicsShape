#ifndef GSSHAPEFACTORY_H
#define GSSHAPEFACTORY_H

#include "gscommondef.h"
#include "gsshapebaseitem.h"


class GsShapeFactory
{
public:
    explicit GsShapeFactory();
    ~GsShapeFactory();

    GsShapeBaseItem * getShapeItem(GsShapeType type, QRectF rectF,
                                   QGraphicsObject *parent);
};

#endif // GSSHAPEFACTORY_H
