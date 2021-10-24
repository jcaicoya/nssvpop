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

public slots:
    void zoom_in();
    void zoom_out();
    void corridor_width_value_changed_handler(int width);

protected:
    void keyPressEvent(QKeyEvent *event) override;
#if QT_CONFIG(wheelevent)
    void wheelEvent(QWheelEvent *event) override;
#endif
    void drawBackground(QPainter *painter, const QRectF &rect) override;

    void scale_view(qreal scaleFactor);

private:
    QGraphicsScene *scene_;
    CorridorItem * corridor_item_;
    QList<FlatItem *> flat_list_;
    int corridor_width_;

    void calculate_flats();
    void display();
};

