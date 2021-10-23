#include "DisplayView.h"
#include "CorridorItem.h"
#include "FlatItem.h"
#include <QDebug>


DisplayView::DisplayView(QWidget *parent)
    : QGraphicsView(parent)
    , scene_(nullptr)
    , corridor_list_()
    , flat_list_()
{
    scene_ = new QGraphicsScene(this);
    scene_->setItemIndexMethod(QGraphicsScene::NoIndex);
    scene_->setSceneRect(-10, -300, 500, 600);
    setScene(scene_);

    setCacheMode(QGraphicsView::CacheBackground);
    setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
    setRenderHint(QPainter::Antialiasing);
    //setTransformationAnchor(QGraphicsView::AnchorUnderMouse);
    //scale(qreal(0.8), qreal(0.8));
    setMinimumSize(800, 800);

    constexpr int corridor_x = 0;
    constexpr int corridor_y = -25;
    constexpr int corridor_width = 500;
    constexpr int corridor_height = 50;
    CorridorItem *corridor_item = new CorridorItem(QRect(corridor_x, corridor_y, corridor_width, corridor_height));
    corridor_list_.append(corridor_item);

    constexpr int number_of_upper_flats = 5;
    constexpr int flats_initial_x = corridor_x;
    constexpr int flats_width = corridor_width / number_of_upper_flats;
    constexpr int flats_height = 300;
    constexpr int upper_flats_y = -corridor_height - flats_height;
    constexpr int botton_flats_y = corridor_height;
    for (int ii=0; ii<number_of_upper_flats; ii++)
    {
        FlatItem *upper_flat_item = new FlatItem(QRect(flats_initial_x + ii*flats_width, upper_flats_y, flats_width, flats_height));
        flat_list_.append(upper_flat_item);
        FlatItem *botton_flat_item = new FlatItem(QRect(flats_initial_x + ii*flats_width, botton_flats_y, flats_width, flats_height));
        flat_list_.append(botton_flat_item);
    }

    display();
}


void DisplayView::display()
{
    for (auto corridor: corridor_list_)
    {
        scene_->addItem(corridor);
    }

    for (auto flat: flat_list_)
    {
        scene_->addItem(flat);
    }

    qDebug() << corridor_list_;
    qDebug() << flat_list_;
}
