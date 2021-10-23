#include "MainWindow.h"
#include "OptionsWidget.h"
#include "DisplayWidget.h"
#include <QHBoxLayout>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    options_widget_ = new OptionsWidget;
    display_widget_ = new DisplayWidget;
    QHBoxLayout *main_layout = new QHBoxLayout;
    main_layout->addWidget(options_widget_);
    main_layout->addWidget(display_widget_);
    QWidget* main_widget = new QWidget;
    main_widget->setLayout(main_layout);
    this->setCentralWidget(main_widget);
}
