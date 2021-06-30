#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_QTCalculator.h"
#include "Calculator.h"
#include "Store.h"
#include "HistoryWindow.h"
#include "InfoWindow.h"

class QTCalculator : public QMainWindow
{
    Q_OBJECT

public:
    QTCalculator(QWidget *parent = Q_NULLPTR);
    ~QTCalculator();

private:
    Ui::QTCalculatorClass ui;
    HistoryWindow *Window;
    InfoWindow* Iwindow;
    Calculator CalcExpr;
    Store HistoryExpr;
private slots:
    void KeyboardCalculator();
    void CheckText();
    void ClickOnPushButton_Eq();
    void ClearInputLine();
    void DeleteOneSymbol();
    void OpenHistoryWindow();
    void OpenInfoWindow();
};
