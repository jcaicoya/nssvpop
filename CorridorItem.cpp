#include "CorridorItem.h"
#include "DisplayViewConstants.h"
#include <QPainter>
#include <QStyleOptionGraphicsItem>

using namespace DisplayViewConstants;


CorridorItem::CorridorItem(int width, QGraphicsItem *parent)
    : QGraphicsRectItem(corridor_x_origin_, corridor_y_origin_, width, corridor_height_, parent)
{
    setFlag(ItemIsSelectable);
    setFlag(ItemSendsGeometryChanges);
    setCacheMode(DeviceCoordinateCache);
    setZValue(-1);
}


void CorridorItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, [[maybe_unused]] QWidget *widget)
{
    //painter->setPen(QPen(Qt::black, 2));
    painter->drawRect(boundingRect());
    if (option->state.testFlag(QStyle::State_Selected))
    {
        painter->fillRect(boundingRect(), Qt::magenta);
    }
    else
    {
        painter->fillRect(boundingRect(), Qt::cyan);
    }
}
