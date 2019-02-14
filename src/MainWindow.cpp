#include "MainWindow.h"

#include "Controls/Image.h"

using namespace MidiHero;

MainWindow::MainWindow()
{
	Image* img = new Image(":/background");

	this->setCentralWidget(img);
}
