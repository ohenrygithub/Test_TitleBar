#include "test_titlebar.h"
#include <QtWidgets/QApplication>
#include <qfile.h>
#include <qfileinfo.h>
#include <qdebug.h>

void setStyle(QApplication&a);

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
	setStyle(a);
    Test_TitleBar w;
    w.show();
    return a.exec();
}

void setStyle(QApplication& a)
{
	/* 加载样式表 */
	QFile file(":/Test_TitleBar/qss/psblack.css");
	QFileInfo info = QFileInfo(file);
	qDebug() << info.absoluteFilePath();
	if (file.open(QFile::ReadOnly))
	{
		QString qss = QLatin1String(file.readAll());
		QString paletteColor = qss.mid(20, 7);
		a.setPalette(QPalette(QColor(paletteColor)));
		a.setStyleSheet(qss);
		file.close();
	}
}
