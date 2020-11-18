#pragma once

#include <QtWidgets/QWidget>
#include "ui_test_titlebar.h"
#include "secondwidget.h"

class Test_TitleBar : public QWidget
{
    Q_OBJECT

public:
    Test_TitleBar(QWidget *parent = Q_NULLPTR);

	bool nativeEvent(const QByteArray& eventType, void* message, long* result);
	protected slots:
	void pbSecond();

private:
    Ui::Test_TitleBarClass ui;
	SecondWidget* second;
	int m_nBorderWidth;   /* 鼠标位于边框缩放范围的宽度 */
};
