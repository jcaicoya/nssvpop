#pragma once

#include <QGraphicsRectItem>


class FlatItem : public QGraphicsRectItem
{
public:
    FlatItem(int x, int t, QGraphicsItem *parent = nullptr);

    enum { Type = UserType + 1 };
    int type() const override { return Type; }
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
};
