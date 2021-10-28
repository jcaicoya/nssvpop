#include "DisplayView.h"
#include "CorridorItem.h"
#include "FlatItem.h"
#include "FlatsState.h"
#include "DisplayViewConstants.h"
#include <cmath>
#include <QDebug>
#include <QKeyEvent>
#if QT_CONFIG(wheelevent)
#include <QWheelEvent>
#endif


using namespace DisplayViewConstants;


DisplayView::DisplayView(QWidget *parent)
    : QGraphicsView(parent)
    , scene_(nullptr)
    , corridor_item_(nullptr)
    , flat_list_()
    , corridor_width_(default_corridor_width_)
{
    scene_ = new QGraphicsScene(this);
    scene_->setItemIndexMethod(QGraphicsScene::NoIndex);
    scene_->setSceneRect(scene_x_origin_, scene_y_origin_, scene_width_, scene_heigh_);
    setScene(scene_);

    setCacheMode(QGraphicsView::CacheBackground);
    setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
    setRenderHint(QPainter::Antialiasing);
    setTransformationAnchor(QGraphicsView::AnchorUnderMouse);
    scale(qreal(0.8), qreal(0.8));
    setMinimumSize(800, 800);

    corridor_item_ = new CorridorItem(corridor_width_);
    scene_->addItem(corridor_item_);

    calculate_flats();
}


void DisplayView::zoom_in()
{
    scale_view(qreal(1.2));
}


void DisplayView::zoom_out()
{
    scale_view(1 / qreal(1.2));
}

void DisplayView::corridor_width_value_changed_handler(int width)
{
    if (corridor_width_ == width)
    {
        return;
    }

    corridor_width_ = width;

    auto rect = corridor_item_->rect();
    rect.setWidth(corridor_width_);
    corridor_item_->setRect(rect);

    calculate_flats();
}


void DisplayView::keyPressEvent(QKeyEvent *event)
{
    switch (event->key()) {
//    case Qt::Key_Up:
//        centerNode->moveBy(0, -20);
//        break;
//    case Qt::Key_Down:
//        centerNode->moveBy(0, 20);
//        break;
//    case Qt::Key_Left:
//        centerNode->moveBy(-20, 0);
//        break;
//    case Qt::Key_Right:
//        centerNode->moveBy(20, 0);
//        break;
    case Qt::Key_Plus:
        zoom_in();
        break;
    case Qt::Key_Minus:
        zoom_out();
        break;
//    case Qt::Key_Space:
//    case Qt::Key_Enter:
//        shuffle();
        break;
    default:
        QGraphicsView::keyPressEvent(event);
    }
}


void DisplayView::drawBackground(QPainter *painter, const QRectF &rect)
{
    QRectF sceneRect = this->sceneRect();
    QLinearGradient gradient(sceneRect.topLeft(), sceneRect.bottomRight());
    gradient.setColorAt(0, Qt::white);
    gradient.setColorAt(1, Qt::lightGray);
    painter->fillRect(rect.intersected(sceneRect), gradient);
    painter->setBrush(Qt::NoBrush);
    painter->drawRect(sceneRect);
}


void DisplayView::scale_view(qreal scaleFactor)
{
    qreal factor = transform().scale(scaleFactor, scaleFactor).mapRect(QRectF(0, 0, 1, 1)).width();
    if (factor < 0.2 || factor > 50)
    {
        return;
    }

    scale(scaleFactor, scaleFactor);
}

#if QT_CONFIG(wheelevent)
void DisplayView::wheelEvent(QWheelEvent *event)
{
    scale_view(std::pow(2., -event->angleDelta().y() / 240.0));
}
#endif


void DisplayView::calculate_flats()
{
    for (auto flat_item: flat_list_)
    {
        scene_->removeItem(flat_item);
    }

    flat_list_.clear();

    int number_of_upper_flats = corridor_width_ / flat_width_;
    int leftover_space = corridor_width_ - (flat_width_ + separation_between_flats_) * number_of_upper_flats;

    if (leftover_space < 0)
    {
        number_of_upper_flats--;
        leftover_space = corridor_width_ - (flat_width_ + separation_between_flats_) * number_of_upper_flats;
    }

    if (0 == leftover_space)
    {
        FlatsState::distribution_is_optimal_ = true;
    }
    else
    {
        FlatsState::distribution_is_optimal_ = false;
    }

    int flats_x = corridor_x_origin_ + leftover_space / 2;
    for (int ii=0; ii<number_of_upper_flats; ii++)
    {
        FlatItem *upper_flat_item = new FlatItem(flats_x, upper_flats_y_origin_);
        flat_list_.append(upper_flat_item);
        FlatItem *botton_flat_item = new FlatItem(flats_x, lower_flats_y_origin_);
        flat_list_.append(botton_flat_item);
        flats_x += flat_width_ + separation_between_flats_;
    }

    for (auto flat_item: flat_list_)
    {
        scene_->addItem(flat_item);
    }
}
