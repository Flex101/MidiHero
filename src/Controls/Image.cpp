#include "Controls/Image.h"

#include <QPainter>

using namespace MidiHero;

Image::Image(QString _src)
{
	src = _src;
}

void Image::paintEvent(QPaintEvent* event)
{
	QPainter painter(this);
	painter.setRenderHint(QPainter::SmoothPixmapTransform);

	QPixmap img(src);
	img = img.scaled(this->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
	painter.drawPixmap(this->rect(), img);

	painter.end();
}
