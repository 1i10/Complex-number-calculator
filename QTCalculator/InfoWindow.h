#pragma once

#include <QDialog>
#include "ui_InfoWindow.h"

class InfoWindow : public QDialog
{
	Q_OBJECT

public:
	InfoWindow(QWidget *parent = Q_NULLPTR);

private:
	Ui::InfoWindow ui;
};
