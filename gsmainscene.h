#ifndef GSMAINSCENE_H
#define GSMAINSCENE_H

#include <QGraphicsScene>
#include "gscommondef.h"
#include "gsshapeitem.h"
#include "gsrootitem.h"

class GsMainScene : public QGraphicsScene
{
    Q_OBJECT

public:
    GsMainScene(const QSizeF &size, QObject *parent = 0);
    ~GsMainScene();

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent * e);
    void mouseMoveEvent(QGraphicsSceneMouseEvent * e);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent * e);
    void keyPressEvent(QKeyEvent * e);

private:
    bool scenePress(int id, const QPointF &pos);
    bool sceneMove(int id, const QPointF &prepos, const QPointF &pos);
    bool sceneRelease(int id, const QPointF &pos);
    bool isHitItem(QPointF p);


private:
    GsRootItem * m_pRootItem = nullptr;

};

#endif // GSMAINSCENE_H
