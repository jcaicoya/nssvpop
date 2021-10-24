#pragma once

#include <QMainWindow>

class OptionsWidget;
class DisplayWidget;


class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);

signals:


private:
    OptionsWidget *options_widget_;
    DisplayWidget *display_widget_;

    void create_actions();
};

