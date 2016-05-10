#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(this->ui->pushButtonNumberOfCoefficients, SIGNAL(clicked(bool)), this, SLOT(showCoeficientsEntering()));
    this->ui->lineEditNumberOfCoefficients->setText("1");
    this->setStyleSheet(QString::fromUtf8("QLineEdit {border: 1px solid gray; border-radius: 10px;} QPushButton {border: 1px solid gray; border-radius: 10px;} "));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showCoeficientsEntering(){
    int tempInt = this->ui->lineEditNumberOfCoefficients->text().toInt();
    double tempAccuracy = this->ui->lineEditAccuracy->text().toDouble();
    this->currentFunction = new function(tempInt, tempAccuracy);
    this->ui->lineEditNumberOfCoefficients->setText(QString::number(this->currentFunction->numberOfCoefficients()));
    this->ui->lineEditAccuracy->setReadOnly(true);
    this->ui->lineEditNumberOfCoefficients->setReadOnly(true);
    this->ui->pushButtonNumberOfCoefficients->hide();
    this->ui->label0->setText("Current number of coefficients and accuracy:");

    QSize blockSize(330, 50);
    QSize paddings(20, 5);
    QSize bigLineEditSize(100, 20);
    QSize littleLineEditSize(100,20);
    QSize labelXSize(20, 20);

    int t = 0;
    for(int i = 0; i < this->currentFunction->numberOfCoefficients(); i++){
        QLineEdit *coefficient = new QLineEdit("1", this);
        QLineEdit *xPower = new QLineEdit("1", this);
        QLabel *xLabel = new QLabel("X", this);
        coefficient->resize(bigLineEditSize);
        xPower->resize(littleLineEditSize);
        xLabel->resize(labelXSize);

        coefficient->move(paddings.width(), (i + 2) * blockSize.height() + paddings.height() + xPower->height());
        xLabel->move(coefficient->x() + coefficient->width() + paddings.width(), (i + 2) * blockSize.height() + paddings.height() + xPower->height());
        xPower->move(xLabel->x() + xLabel->width(), (i + 2) * blockSize.height());

        coefficient->show();
        xPower->show();
        xLabel->show();

        this->lineEditCoeficients.push_back(coefficient);
        this->lineEditXPowers.push_back(xPower);
        this->labelXs.push_back(xLabel);

        t = i;
    }
    t++;
    this->lineEditFreeCoefficient = new QLineEdit("1", this);

    this->lineEditFreeCoefficient->resize(littleLineEditSize);

    this->lineEditFreeCoefficient->move(paddings.width(), (t + 2) * blockSize.height() + paddings.height());

    this->lineEditFreeCoefficient->show();

    this->lineEditA = new QLineEdit("-100", this);
    this->lineEditB = new QLineEdit("100", this);

    this->lineEditA->resize(100, 20);
    this->lineEditB->resize(100, 20);
    this->lineEditA->move(this->ui->label0->x() + this->ui->label0->width() + 20, this->ui->lineEditNumberOfCoefficients->y());
    this->lineEditB->move(this->lineEditA->x() + this->lineEditA->width() + 20, this->ui->lineEditNumberOfCoefficients->y());
    this->lineEditA->show();
    this->lineEditB->show();

    this->buttonAllDone = new QPushButton("Start Calculations", this);
    this->buttonAllDone->move(lineEditA->x(), this->lineEditA->y() + this->lineEditA->height() + 10);
    this->buttonAllDone->resize(220, 20);
    this->buttonAllDone->show();
    connect(this->buttonAllDone, SIGNAL(clicked(bool)), this, SLOT(startCalculation()));
}

bool MainWindow::checkInput(){
    QVector<Coefficient* > coefficients;
    for(int i = 0; i < this->currentFunction->numberOfCoefficients(); i++){
        Coefficient *tempCoefficient = new Coefficient(this->lineEditCoeficients[i]->text().toDouble(), this->lineEditXPowers[i]->text().toDouble());
        coefficients.push_back(tempCoefficient);
    }
    this->currentFunction->setCoefficients(coefficients);
    this->currentFunction->setFreeCoefficient(this->lineEditFreeCoefficient->text().toDouble());
    return true;
}

void MainWindow::startCalculation(){
    if(checkInput()){
        this->result = this->currentFunction->calculateWithEps(this->lineEditA->text().toDouble(), this->lineEditB->text().toDouble(), this->ui->lineEditAccuracy->text().toDouble());
        this->labelResult = new QLabel(this);
        this->labelResult->resize(400, 400);
        this->labelResult->move(this->buttonAllDone->x(), this->buttonAllDone->y() + 10);
        QString str;
        str += "Result:";
        str += QString::number(result);
        str += "\n";
        str += this->currentFunction->listOfSteps();
        this->labelResult->setText(str);
        this->labelResult->show();
    }
    else
        return;
}
