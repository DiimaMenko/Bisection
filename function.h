#ifndef FUNCTION_H
#define FUNCTION_H
#include <QVector>
#include "coefficient.h"
#include <QtMath>

class function
{
private:
    int _numberOfCoefficients;
    double _eps;
    QVector<Coefficient* > _coefficients;
    Coefficient* _freeCoeff;
    double a;
    double b;
    QString _listOfSteps;
public:
    function();
    function(int numberCoefficients, double accuracy);
    double functionWithX(double x);
    double calculate(double a, double b);
    double calculateWithEps(double a, double b, double eps);
    void setCoefficients(QVector<Coefficient* > coefficients);
    void setFreeCoefficient(double coefficient);
    int numberOfCoefficients();
    QString listOfSteps();
    double eps();
};

#endif // FUNCTION_H
