#pragma once

#include <QDialog>
#include "ui_HistoryWindow.h"
#include "Store.h"

class HistoryWindow : public QDialog
{
	Q_OBJECT

public:
	HistoryWindow(QWidget *parent = Q_NULLPTR);
	void SetHistoryUI(Store History);
	bool CheckHistoryUI();//проверка состояния истории (есть в ней информация или нет)

private:
	Ui::HistoryWindow ui;
};
