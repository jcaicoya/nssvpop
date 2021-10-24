#include "DisplayWidget.h"
#include "DisplayView.h"
#include <QPushButton>
#include <QVBoxLayout>
#include <QDebug>


DisplayWidget::DisplayWidget(QWidget *parent)
    : QGroupBox("Display widget", parent)
    , display_view_(nullptr)
{
    QPushButton *do_nothing_button = new QPushButton("Doing nothing for the moment");
    display_view_ = new DisplayView;

    QVBoxLayout *display_layout = new QVBoxLayout;
    display_layout->addWidget(do_nothing_button);
    display_layout->addWidget(display_view_);

    setLayout(display_layout);

    connect(this, &DisplayWidget::corridor_width_value_changed,
            display_view_, &DisplayView::corridor_width_value_changed_handler);
}


void DisplayWidget::corridor_width_value_changed_handler(int width)
{
    emit corridor_width_value_changed(width);
}
