#include "cwidget.h"
#include "qevent.h"
#include "qpushbutton.h"
#include "qt_windows.h"

#ifdef Q_OS_WIN
#pragma comment(lib,"user32.lib")
#include <qt_windows.h>
#endif

CWidget::CWidget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
}

CWidget::~CWidget()
{
}

void CWidget::setWindowTitle(const QString & title)
{
	ui.lbWindowTitle->setAlignment(Qt::AlignCenter);
	ui.lbWindowTitle->setText(title);
}

void CWidget::setTitleBarIcon(const QString & iconPath)
{
	QPixmap map(iconPath);
	ui.lbLogo->setPixmap(map);
}

bool CWidget::eventFilter(QObject * obj, QEvent * event)
{
	QEvent::Type type = event->type();
	switch (type)
	{
	case QEvent::WindowTitleChange:
	{
		QWidget *pWidget = qobject_cast<QWidget *>(obj);
		if (pWidget)
		{
			ui.lbWindowTitle->setText(pWidget->windowTitle());
			return true;
		}
	}
	break;
	//设置图标
	case QEvent::WindowIconChange:
	{
		QWidget *pWidget = qobject_cast<QWidget *>(obj);
		if (pWidget)
		{
			QIcon icon = pWidget->windowIcon();
			ui.lbLogo->setPixmap(icon.pixmap(ui.lbLogo->size()));
			return true;
		}
	}
	break;
	// 窗口状态变化、窗口大小变化
	case QEvent::WindowStateChange:
	case QEvent::Resize:
		//updateMaximize();
		return true;
	default:
		return QWidget::eventFilter(obj, event);
	}
	return QWidget::eventFilter(obj, event);
}

void CWidget::pbMaxNormal()
{
	QWidget* pWindow = this->parentWidget();
	if (pWindow->isTopLevel())
	{
		if (pWindow->isMaximized())
		{
			pWindow->showNormal();
			ui.pbMaxNormal->setToolTip(QStringLiteral("最大化"));    //: / Test_Custom_Widget / Resources / Coherence.png
			ui.pbMaxNormal->setIcon(QPixmap(":/Test_TitleBar/Resources/Fullscreen.png"));
		}
		else
		{
			pWindow->showMaximized();

			ui.pbMaxNormal->setToolTip(QStringLiteral("恢复"));       //: / Test_Custom_Widget / Resources / Coherence.png
			ui.pbMaxNormal->setIcon(QPixmap(":/Test_TitleBar/Resources/Coherence.png"));
		}
	}
}

void CWidget::pbMin()
{
	QWidget* pWindow = this->parentWidget();
	if (pWindow->isTopLevel())
	{
		pWindow->showMinimized();
	}
}

void CWidget::pbQuit()
{
	QWidget* pWindow = this->parentWidget();
	if (pWindow->isTopLevel())
	{
		pWindow->close();
	}
}

void CWidget::mouseDoubleClickEvent(QMouseEvent * event)
{
	if (event->button() == Qt::LeftButton)
	{
		pbMaxNormal();
	}
}

void CWidget::mousePressEvent(QMouseEvent * event)
{
#ifdef Q_OS_WIN
	if (ReleaseCapture())
	{
		QWidget* pWindow = this->parentWidget();
		if (pWindow->isTopLevel())
		{
			SendMessage(HWND(pWindow->winId()), WM_SYSCOMMAND, SC_MOVE + HTCAPTION, 0);
		}
	}
	event->ignore();
#endif
}

