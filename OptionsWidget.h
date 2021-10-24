#pragma once

#include <QGroupBox>

class QPushButton;
class QSpinBox;


class OptionsWidget : public QGroupBox
{
    Q_OBJECT
public:
    explicit OptionsWidget(QWidget *parent = nullptr);

signals:
    void corridor_width_value_changed(int width);

private:
    QPushButton *do_nothing_button_;
    QSpinBox *corridor_width_sping_box_;
};
