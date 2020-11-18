#pragma once

#include <QtWidgets/QWidget>
#include "ui_test_titlebar.h"

class Test_TitleBar : public QWidget
{
    Q_OBJECT

public:
    Test_TitleBar(QWidget *parent = Q_NULLPTR);

private:
    Ui::Test_TitleBarClass ui;
};
