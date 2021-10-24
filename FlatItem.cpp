#include "FlatItem.h"
#include <QPainter>
#include <QStyleOptionGraphicsItem>


FlatItem::FlatItem(const QRect& rect)
    : QGraphicsRectItem(rect)
{
    setFlag(ItemIsSelectable);
    setFlag(ItemSendsGeometryChanges);
    setCacheMode(DeviceCoordinateCache);
    setZValue(-1);
}


void FlatItem::paint(QPainter *painter, [[maybe_unused]] const QStyleOptionGraphicsItem *option, [[maybe_unused]] QWidget *widget)
{
    // TODO: painting a wider border implies to define bounding rect properly
    //painter->setPen(QPen(Qt::black, 1));
    painter->drawRect(boundingRect());
    if (option->state.testFlag(QStyle::State_Selected))
    {
        painter->fillRect(boundingRect(), Qt::blue);
    }
    else
    {
        painter->fillRect(boundingRect(), Qt::yellow);
    }
}
