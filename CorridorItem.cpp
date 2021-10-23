#include "CorridorItem.h"
#include <QPainter>


CorridorItem::CorridorItem(const QRect& rect)
    : QGraphicsRectItem(rect)
{
}


void CorridorItem::paint(QPainter *painter, [[maybe_unused]] const QStyleOptionGraphicsItem *option, [[maybe_unused]] QWidget *widget)
{
    painter->setBrush(Qt::red);
    painter->setPen(QPen(Qt::black, 2));
    painter->drawRect(rect());
}
