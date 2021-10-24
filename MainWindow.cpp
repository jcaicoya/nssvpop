#include "MainWindow.h"
#include "OptionsWidget.h"
#include "DisplayWidget.h"
#include <QHBoxLayout>
#include <QMenuBar>
#include <QAction>
#include <QToolBar>


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

    create_actions();

    connect(options_widget_, &OptionsWidget::corridor_width_value_changed,
            display_widget_, &DisplayWidget::corridor_width_value_changed_handler);
}


void MainWindow::create_actions()
{
    QMenu *configuration_menu = menuBar()->addMenu(tr("&Configurations"));
    QToolBar *configuration_tool_bar = addToolBar(tr("Configurations"));

    QAction *size_configuration_action = new QAction(tr("Sizes"), this);
    size_configuration_action->setStatusTip(tr("Disabled: to define sizes"));
    //connect(sizeConfigurationAction, &QAction::triggered, this, &MainWindow::loadSizesConfiguration);
    configuration_menu->addAction(size_configuration_action);
    configuration_tool_bar->addAction(size_configuration_action);

    QAction *colors_configuration_action = new QAction(tr("Colors"), this);
    colors_configuration_action->setStatusTip(tr("Disabled: to define colors"));
    //connect(colors_configuration_action, &QAction::triggered, this, &MainWindow::loadColorsConfiguration);
    configuration_menu->addAction(colors_configuration_action);
    configuration_tool_bar->addAction(colors_configuration_action);
}
