#pragma once

#include <QWidget>
#include "ui_cwidget.h"

class CWidget : public QWidget
{
	Q_OBJECT

public:
	CWidget(QWidget *parent = Q_NULLPTR);
	~CWidget();
	
	void setWindowTitle(const QString& title);
	void setTitleBarIcon(const QString& iconPath);
	virtual bool eventFilter(QObject* obj, QEvent* event);

	protected slots:
	void pbMaxNormal();
	void pbMin();
	void pbQuit();

protected:
	virtual void mouseDoubleClickEvent(QMouseEvent *event);
	virtual void mousePressEvent(QMouseEvent *event);

private:
	Ui::CWidget ui;
};
