#include "FlatItem.h"
#include <QPainter>


FlatItem::FlatItem(const QRect& rect)
    : QGraphicsRectItem(rect)
{
}

void FlatItem::paint(QPainter *painter, [[maybe_unused]] const QStyleOptionGraphicsItem *option, [[maybe_unused]] QWidget *widget)
{
    painter->setBrush(Qt::yellow);
    painter->setPen(QPen(Qt::black, 2));
    painter->drawRect(rect());
}
