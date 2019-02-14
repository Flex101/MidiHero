#pragma once

#include <QWidget>

namespace MidiHero {

class Image : public QWidget
{
public:
	explicit Image(QString src);
	virtual ~Image() {}

protected:
	void paintEvent(QPaintEvent* event);

protected:
	QString src;
};

} // namespace MidiHero
