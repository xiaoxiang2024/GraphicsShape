#include "gsmainscene.h"
#include <QApplication>
#include <QDesktopWidget>
#include <QGraphicsView>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QSize desktopSize = qApp->desktop()->screenGeometry().size();
    QScopedPointer<QGraphicsView> view(new QGraphicsView());
    QScopedPointer<GsMainScene> pScene(new GsMainScene(desktopSize));
    view->setScene(pScene.data());
    view->resize(desktopSize);
    view->show();

    return a.exec();
}
