#include "OptionsWidget.h"
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>


OptionsWidget::OptionsWidget(QWidget *parent)
    : QGroupBox("Options widget", parent)
{
    QLabel *label = new QLabel("There will be things here");
    do_nothing_button_ = new QPushButton("Doing nothing\nfor the moment");

    QVBoxLayout *options_layout = new QVBoxLayout;
    options_layout->addWidget(label);
    options_layout->addWidget(do_nothing_button_);

    setLayout(options_layout);
}
