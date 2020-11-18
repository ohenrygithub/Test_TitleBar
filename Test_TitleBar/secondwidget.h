#pragma once

#include <QWidget>
#include "ui_secondwidget.h"

class SecondWidget : public QWidget
{
	Q_OBJECT

public:
	SecondWidget(QWidget *parent = Q_NULLPTR);
	~SecondWidget();
	bool nativeEvent(const QByteArray& eventType, void* message, long* result);
private:
	Ui::SecondWidget ui;
	int m_nBorderWidth;
};
