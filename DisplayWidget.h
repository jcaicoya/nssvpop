#pragma once

#include <QGroupBox>

class DisplayView;


class DisplayWidget : public QGroupBox
{
    Q_OBJECT
public:
    explicit DisplayWidget(QWidget *parent = nullptr);

signals:

private:
     DisplayView *display_view_;
};

