#pragma once

#include <QWidget>
#include "ui_secondwidget.h"

class SecondWidget : public QWidget
{
	Q_OBJECT

public:
	SecondWidget(QWidget *parent = Q_NULLPTR);
	~SecondWidget();

private:
	Ui::SecondWidget ui;
};
