#include "test_titlebar.h"
//#include "secondwidget.h"
#include "qicon.h"

#ifdef Q_OS_WIN
#include <qt_windows.h>
#include <windowsx.h>
#endif


Test_TitleBar::Test_TitleBar(QWidget *parent)
	: QWidget(parent),
	m_nBorderWidth(5),
	second(nullptr)
{
	ui.setupUi(this);
	this->setWindowFlags(Qt::CustomizeWindowHint | Qt::FramelessWindowHint);
	installEventFilter(ui.widget);
	setWindowTitle("Test_TitleBar_Window");
	QIcon icon(":/Test_TitleBar/Resources/add_32.png");
	setWindowIcon(icon);
}

/* nativeEvent主要用在进程间通信-消息传递，使用这种方式来实现窗体的缩放 */

bool Test_TitleBar::nativeEvent(const QByteArray & eventType, void * message, long * result)
{
	Q_UNUSED(eventType)

		MSG *param = static_cast<MSG *>(message);

	switch (param->message)
	{
	case WM_NCHITTEST:
	{
		int nX = GET_X_LPARAM(param->lParam) - this->geometry().x();
		int nY = GET_Y_LPARAM(param->lParam) - this->geometry().y();

		// 如果鼠标位于子控件上，则不进行处理
		if (childAt(nX, nY) != nullptr)
			return QWidget::nativeEvent(eventType, message, result);

		*result = HTCAPTION;

		// 鼠标区域位于窗体边框，进行缩放
		if ((nX > 0) && (nX < m_nBorderWidth))
			*result = HTLEFT;

		if ((nX > this->width() - m_nBorderWidth) && (nX < this->width()))
			*result = HTRIGHT;

		if ((nY > 0) && (nY < m_nBorderWidth))
			*result = HTTOP;

		if ((nY > this->height() - m_nBorderWidth) && (nY < this->height()))
			*result = HTBOTTOM;

		if ((nX > 0) && (nX < m_nBorderWidth) && (nY > 0)
			&& (nY < m_nBorderWidth))
			*result = HTTOPLEFT;

		if ((nX > this->width() - m_nBorderWidth) && (nX < this->width())
			&& (nY > 0) && (nY < m_nBorderWidth))
			*result = HTTOPRIGHT;

		if ((nX > 0) && (nX < m_nBorderWidth)
			&& (nY > this->height() - m_nBorderWidth) && (nY < this->height()))
			*result = HTBOTTOMLEFT;

		if ((nX > this->width() - m_nBorderWidth) && (nX < this->width())
			&& (nY > this->height() - m_nBorderWidth) && (nY < this->height()))
			*result = HTBOTTOMRIGHT;

		return true;
	}
	}
	return QWidget::nativeEvent(eventType, message, result);
}


void Test_TitleBar::pbSecond()
{
	if (nullptr == second)
	{
		second = new SecondWidget();
	}
	if (second->isHidden())
	{
		second->show();
	}
	else
	{
		second->hide();
	}
}
