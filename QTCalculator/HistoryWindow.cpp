#include "HistoryWindow.h"

HistoryWindow::HistoryWindow(QWidget *parent)
	: QDialog(parent, Qt::Window | Qt::FramelessWindowHint)
{
	ui.setupUi(this);
}

void HistoryWindow::SetHistoryUI(Store History)
{
	for (Calculator Note : History.GetResultTable())
	{
		//добавляем первый
		ui.HistoryList->insertItem(0, QString::fromLocal8Bit(Note.GetExpression().c_str()) + " = " + QString::fromLocal8Bit(Note.GetResult().c_str()));
		break;
	}
}

bool HistoryWindow::CheckHistoryUI()
{
	if (ui.HistoryList->count() == 0)//история чиста
	{
		return true;
	}

	return false;
}
