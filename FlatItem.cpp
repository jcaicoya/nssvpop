#include "FlatItem.h"
#include "DisplayViewConstants.h"
#include "FlatsState.h"
#include <QPainter>
#include <QStyleOptionGraphicsItem>


using namespace DisplayViewConstants;


FlatItem::FlatItem(int x, int y, QGraphicsItem *parent)
    : QGraphicsRectItem(x, y, flat_width_, flat_height_, parent)
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
    else if (FlatsState::distribution_is_optimal_)
    {
        painter->fillRect(boundingRect(), Qt::green);
    }
    else
    {
        painter->fillRect(boundingRect(), Qt::darkRed);
    }
}
