#pragma once

#include <QGroupBox>

class QPushButton;


class OptionsWidget : public QGroupBox
{
    Q_OBJECT
public:
    explicit OptionsWidget(QWidget *parent = nullptr);

signals:

private:
    QPushButton *do_nothing_button_;
};
