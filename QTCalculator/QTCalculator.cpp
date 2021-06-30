#include "QTCalculator.h"
#include "ComplexNumber.h"
#include "AddOperation.h"
#include "SubOperation.h"
#include "MultOperation.h"
#include "DivOperation.h"
#include "ModulForComparison.h"
#include "ArgForComparison.h"
#include "HistoryWindow.h"
#include <QAction>


QTCalculator::QTCalculator(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

    ui.PushButton_Eq->setEnabled(false);//ограничить доступ к кнопке =
    ui.InputLine->setMaxLength(30);

    connect(ui.InputLine, SIGNAL(textChanged(QString)), this, SLOT(CheckText()));
    connect(ui.PushButton_Del, SIGNAL(clicked()), this, SLOT(ClearInputLine()));
    connect(ui.PushButton_BackSpace, SIGNAL(clicked()), this, SLOT(DeleteOneSymbol()));

    connect(ui.PushButton_0, SIGNAL(clicked()), this, SLOT(KeyboardCalculator()));
    connect(ui.PushButton_1, SIGNAL(clicked()), this, SLOT(KeyboardCalculator()));
    connect(ui.PushButton_2, SIGNAL(clicked()), this, SLOT(KeyboardCalculator()));
    connect(ui.PushButton_3, SIGNAL(clicked()), this, SLOT(KeyboardCalculator()));
    connect(ui.PushButton_4, SIGNAL(clicked()), this, SLOT(KeyboardCalculator()));
    connect(ui.PushButton_5, SIGNAL(clicked()), this, SLOT(KeyboardCalculator()));
    connect(ui.PushButton_6, SIGNAL(clicked()), this, SLOT(KeyboardCalculator()));
    connect(ui.PushButton_7, SIGNAL(clicked()), this, SLOT(KeyboardCalculator()));
    connect(ui.PushButton_8, SIGNAL(clicked()), this, SLOT(KeyboardCalculator()));
    connect(ui.PushButton_9, SIGNAL(clicked()), this, SLOT(KeyboardCalculator()));
    connect(ui.PushButton_LeftBracket, SIGNAL(clicked()), this, SLOT(KeyboardCalculator()));
    connect(ui.PushButton_RightBracket, SIGNAL(clicked()), this, SLOT(KeyboardCalculator()));
    connect(ui.PushButton_i, SIGNAL(clicked()), this, SLOT(KeyboardCalculator()));
    connect(ui.PushButton_Dot, SIGNAL(clicked()), this, SLOT(KeyboardCalculator()));
    connect(ui.PushButton_Div, SIGNAL(clicked()), this, SLOT(KeyboardCalculator()));
    connect(ui.PushButton_Mult, SIGNAL(clicked()), this, SLOT(KeyboardCalculator()));
    connect(ui.PushButton_Minus, SIGNAL(clicked()), this, SLOT(KeyboardCalculator()));
    connect(ui.PushButton_Plus, SIGNAL(clicked()), this, SLOT(KeyboardCalculator()));
    connect(ui.PushButton_Compare, SIGNAL(clicked()), this, SLOT(KeyboardCalculator()));

    connect(ui.PushButton_Eq, SIGNAL(clicked()), this, SLOT(ClickOnPushButton_Eq()));

    Window = new HistoryWindow(this);
    Window->hide();//видимость false
    connect(ui.PushButton_History, SIGNAL(clicked()), this, SLOT(OpenHistoryWindow()));

    QAction* InfoIcon = new QAction();
    InfoIcon->setIcon(QIcon(":/QTCalculator/image/InfoIcon.png"));
    ui.InputLine->addAction(InfoIcon, QLineEdit::LeadingPosition);

    Iwindow = new InfoWindow(this);
    Iwindow->hide();//видимость false
    connect(InfoIcon, SIGNAL(triggered(bool)), this, SLOT(OpenInfoWindow()));

}

void QTCalculator::KeyboardCalculator()
{
    QPushButton* Button = (QPushButton*)sender();

    QString Expr = ui.InputLine->text() + Button->text();

    ui.InputLine->setText(Expr);
}

QTCalculator::~QTCalculator()
{
    delete Window;
    delete Iwindow;
}

void QTCalculator::CheckText()
{
    QString Str = ui.InputLine->text();
    QString Number = "(0|([1-9][0-9]*))(\\.[0-9]+)?";
    QString ComplexNum = "\\((-?)" + Number + "(\\+|-)" + Number + "i" + "\\)";
    QString Expr = "^" + ComplexNum + "(\\+|-|/|\\*|\\?)" + ComplexNum + "$";
    QRegExp* q = new QRegExp(Expr);
    if (q->indexIn(Str) == -1)//если не соответствует
    {
        ui.PushButton_Eq->setEnabled(false);//ограничить доступ к кнопке =
        ui.InputLine->setStyleSheet(QString("QLineEdit {border-width: 1px;" " border-style: solid; " "border-color: red;}"));
    }
    else
    {
        ui.PushButton_Eq->setEnabled(true);//открыть доступ к кнопке =
        ui.InputLine->setStyleSheet(QString("QLineEdit {border-width: 1px;" " border-style: solid; " "border-color: black;}"));
    }

    if (ui.InputLine->text() == "")
    {
        ui.InputLine->setStyleSheet(QString("QLineEdit {border-width: 1px;" " border-style: solid; " "border-color: black;}"));
    }

}

void QTCalculator::ClickOnPushButton_Eq()
{
    //дл¤ истории
    //если чиста, то очищаем CalcExpr
    if (Window->CheckHistoryUI())
    {
        HistoryExpr.ClearTable();
    }

    CalcExpr.SetExpression(ui.InputLine->text().toStdString());//запись строчки из строки ввода

    std::vector <ComplexNumber> Numbers = CalcExpr.GetComplexNumbersFromExpression();//выт¤гиваем комплексные числа из строки

    char Operation = CalcExpr.GetOperationFromExpression();//выт¤гиваем операцию

    ComplexNumber Result;
    AddOperation AddExpr;
    SubOperation SubExpr;
    MultOperation MultExpr;
    DivOperation DivExpr;
    ModulForComparison ModulExpr;
    ArgForComparison ArgExpr;
    double Result1 = 0;
    double Result2 = 0;

    if (Operation == '+')
    {
        AddExpr.SetNum1(Numbers[0]);
        AddExpr.SetNum2(Numbers[1]);
     
        Result = AddExpr.AddResult();
        CalcExpr.SetResult(Result.ConvertComplexNumberToString());
    }
    if (Operation == '-')
    {
        SubExpr.SetNum1(Numbers[0]);
        SubExpr.SetNum2(Numbers[1]);

        Result = SubExpr.SubResult();
        CalcExpr.SetResult(Result.ConvertComplexNumberToString());
    }
    if (Operation == '*')
    {
        MultExpr.SetNum1(Numbers[0]);
        MultExpr.SetNum2(Numbers[1]);

        Result = MultExpr.MultResult();
        CalcExpr.SetResult(Result.ConvertComplexNumberToString());
    }
    if (Operation == '/')
    {
        if (Numbers[1].GetRealPart() == 0 && Numbers[1].GetImaginaryPart() == 0)
        {
            CalcExpr.SetResult("ƒеление на ноль");
        }
        else
        {
            DivExpr.SetNum1(Numbers[0]);
            DivExpr.SetNum2(Numbers[1]);

            Result = DivExpr.DivResult();
            CalcExpr.SetResult(Result.ConvertComplexNumberToString());
        }
    }
    if (Operation == '?')
    {
        if (ui.RadioButton_Modul->isChecked())//активна кнопка с модулем
        {
            Result1 = ModulExpr.GetModul(Numbers[0]);
            Result2 = ModulExpr.GetModul(Numbers[1]);

            CalcExpr.SetResult(ModulExpr.ComparisonResult(Result1, Result2));
        }
        else//активна кнопка с аргументом
        {
            Result1 = ArgExpr.GetArg(Numbers[0]);
            Result2 = ArgExpr.GetArg(Numbers[1]);

            CalcExpr.SetResult(ArgExpr.ComparisonResult(Result1, Result2));
        }
    }
    if (CalcExpr.GetResult() == "0+0i")
    {
        CalcExpr.SetResult("0");
    }
    ui.DisplayResult->setText(ui.InputLine->text() + " = " + QString::fromLocal8Bit(CalcExpr.GetResult().c_str()));
    ui.InputLine->setText("");

    HistoryExpr.AddInTable(CalcExpr);

    Window->SetHistoryUI(HistoryExpr);
}

void QTCalculator::ClearInputLine()
{
    ui.InputLine->setText("");
}

void QTCalculator::DeleteOneSymbol()
{
    ui.InputLine->backspace();
}

void QTCalculator::OpenHistoryWindow()
{
    if (Window->isVisible())
    {
        Window->close();
    }
    else
    {
        Window->setGeometry(this->geometry().x(), this->geometry().y() + 418, 595, 218);
        Window->show();
    }
}

void QTCalculator::OpenInfoWindow()
{
    if (Iwindow->isVisible())
    {
        Iwindow->close();
    }
    else
    {
        Iwindow->setGeometry(this->geometry().x()-95, this->geometry().y() - 107, 254, 210);
        Iwindow->show();
    }
}
