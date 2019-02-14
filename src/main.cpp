#include <QApplication>

#include "MainWindow.h"

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);
	Q_INIT_RESOURCE(resource);

	MidiHero::MainWindow mainWin;
	mainWin.showMaximized();

	return app.exec();
}
