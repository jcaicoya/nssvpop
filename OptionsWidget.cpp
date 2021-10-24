#include "OptionsWidget.h"
#include "DisplayViewConstants.h"
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QSpinBox>
#include <QDebug>


OptionsWidget::OptionsWidget(QWidget *parent)
    : QGroupBox("Options widget", parent)
{
    QLabel *more_things_label = new QLabel("There will be more things here");
    do_nothing_button_ = new QPushButton("Doing nothing\nfor the moment");

    QLabel *corridor_width_label = new QLabel("Corridor width:");
    corridor_width_sping_box_ = new QSpinBox;
    corridor_width_sping_box_->setRange(DisplayViewConstants::minimum_corridor_width_,
                                        DisplayViewConstants::maximum_corridor_width);
    corridor_width_sping_box_->setSingleStep(5);
    corridor_width_sping_box_->setValue(DisplayViewConstants::default_corridor_width_);

    QHBoxLayout *corridor_width_layout = new QHBoxLayout;
    corridor_width_layout->addWidget(corridor_width_label);
    corridor_width_layout->addWidget(corridor_width_sping_box_);

    connect(corridor_width_sping_box_, QOverload<int>::of(&QSpinBox::valueChanged),
            [=](int width){
        qDebug() << "OptionsWidget emiting corridor_width_value_changed(" << width << ")";
        emit corridor_width_value_changed(width); });

    QVBoxLayout *options_layout = new QVBoxLayout;
    options_layout->addWidget(more_things_label);
    options_layout->addStretch();
    options_layout->addLayout(corridor_width_layout);
    options_layout->addStretch();
    options_layout->addWidget(do_nothing_button_);

    setLayout(options_layout);
}
