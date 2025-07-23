#include <QCoreApplication>
#include <QSettings>
#include <QTimer>
#include <QDebug>

int main(int argc, char *argv[])
{
	QSettings::setDefaultFormat(QSettings::IniFormat);

	QCoreApplication::setOrganizationName("MORKNet");
	QCoreApplication::setApplicationName("setex");
	QCoreApplication::setOrganizationDomain("de.morknet");

	QCoreApplication a(argc, argv);
	QTimer::singleShot(200, &a, &QCoreApplication::quit);


	QSettings settings(QSettings::IniFormat, QSettings::UserScope, "MORKNet", "setex");
	QSettings def1;
	QSettings def2;
	QSettings def3("MORKNet", "def");

	qInfo() << settings.format() << def1.format() << def2.format() << def3.format();
	qInfo() << settings.scope() << def1.scope() << def2.scope() << def3.scope();
	qInfo() << settings.fileName();
	qInfo() << def1.fileName();
	qInfo() << def2.fileName();
	qInfo() << def3.fileName();
	qInfo() << settings.value("Example", 42).toInt();

	return a.exec();
}
