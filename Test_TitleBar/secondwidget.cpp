#include "secondwidget.h"
#include "qicon.h"

SecondWidget::SecondWidget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	
	this->setWindowFlags(Qt::CustomizeWindowHint | Qt::FramelessWindowHint);
	installEventFilter(ui.widget);
	setWindowTitle("Second_Window");
	QIcon icon(":/Test_TitleBar/Resources/Fullscreen.png");
	setWindowIcon(icon);
}

SecondWidget::~SecondWidget()
{
}
