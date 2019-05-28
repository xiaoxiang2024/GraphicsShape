#ifndef GSCOMMONDEF_H
#define GSCOMMONDEF_H

#include <QGraphicsItem>

enum GsShapeType{
    Shape_Line,         //直线
    Shape_Rectange,     //矩形
    Shape_Circle,       //正圆
    Shape_Oval          //椭圆
};

#define SAFE_DELETE(x) if(x) \
    { \
        delete (x); \
        (x) = nullptr; \
    }

enum GsItemType{
    Type_RootItem = QGraphicsItem::UserType + 10,
    Type_ShapeItem
};

#endif // GSCOMMONDEF_H
