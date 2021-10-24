#pragma once

#include <QGraphicsRectItem>


class CorridorItem : public QGraphicsRectItem
{
public:
    CorridorItem(int width, QGraphicsItem *parent = nullptr);

    enum { Type = UserType + 1 };
    int type() const override { return Type; }
    //QRectF boundingRect() const override { return rect(); }
    //QPainterPath shape() const override { return boundingRect(); };
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
};
