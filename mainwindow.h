#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QVector>
#include "function.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
public slots:
    void startCalculation();
    bool checkInput();
    void showCoeficientsEntering();
private:
    Ui::MainWindow *ui;
    function *currentFunction;
    QVector<QLineEdit* > lineEditCoeficients;
    QVector<QLineEdit* > lineEditXPowers;
    QVector<QLabel* > labelXs;
    QLineEdit *lineEditA;
    QLineEdit *lineEditB;
    QPushButton *buttonAllDone;
    QLineEdit *lineEditFreeCoefficient;
    QLabel *labelResult;
    double result;
};

#endif // MAINWINDOW_H
