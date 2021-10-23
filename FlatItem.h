#pragma once

#include <QGraphicsRectItem>
#include <QGraphicsItem>


class FlatItem : public QGraphicsRectItem
{
public:
    FlatItem(const QRect &rect);

    enum { Type = UserType + 1 };
    int type() const override { return Type; }
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

private:
};



