#pragma once

#include <QGraphicsView>
#include <QList>

class CorridorItem;
class FlatItem;
class QGraphicsScene;


class DisplayView : public QGraphicsView
{
    Q_OBJECT

public:
    explicit DisplayView(QWidget *parent = nullptr);


private:
    QGraphicsScene *scene_;
    QList<CorridorItem *> corridor_list_;
    QList<FlatItem *> flat_list_;

    void display();
};

