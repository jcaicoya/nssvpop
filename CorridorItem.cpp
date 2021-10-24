#include "CorridorItem.h"
#include <QPainter>
#include <QStyleOptionGraphicsItem>


CorridorItem::CorridorItem(const QRect& rect)
    : QGraphicsRectItem(rect)
{
    setFlag(ItemIsSelectable);
    setFlag(ItemSendsGeometryChanges);
    setCacheMode(DeviceCoordinateCache);
    setZValue(-1);
}


void CorridorItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, [[maybe_unused]] QWidget *widget)
{
    // TODO: painting a wider border implies to define bounding rect properly
    //painter->setPen(QPen(Qt::black, 1));
    painter->drawRect(boundingRect());
    if (option->state.testFlag(QStyle::State_Selected))
    {
        painter->fillRect(boundingRect(), Qt::red);
    }
    else
    {
        painter->fillRect(boundingRect(), Qt::green);
    }
}
