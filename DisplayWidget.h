#pragma once

#include <QGroupBox>

class DisplayView;


class DisplayWidget : public QGroupBox
{
    Q_OBJECT
public:
    explicit DisplayWidget(QWidget *parent = nullptr);

public slots:
    void corridor_width_value_changed_handler(int width);

signals:
    void corridor_width_value_changed(int width);

private:
     DisplayView *display_view_;
};
