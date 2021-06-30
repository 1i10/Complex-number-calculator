#include "InfoWindow.h"
#include <QBitmap>

InfoWindow::InfoWindow(QWidget *parent)
	: QDialog(parent, Qt::Window | Qt::FramelessWindowHint)
{
	ui.setupUi(this);

	setWindowOpacity(0.8);

	QPixmap maskPix(":/QTCalculator/image/mask2.png");
	setMask(maskPix.scaled(QSize(254, 270)).mask());
}

