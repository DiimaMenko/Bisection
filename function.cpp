#include "function.h"
#include <QDebug>

function::function(){
    this->_eps = 0.001;
    this->_numberOfCoefficients = 1;
    Coefficient *temp = new Coefficient(0.0, 1.0);
    this->_coefficients.push_back(temp);
}

function::function(int numberCoefficients, double accuracy){
    this->_eps = accuracy;
    if(numberCoefficients > 0){
        this->_numberOfCoefficients = numberCoefficients;
    }
    else{
        this->_numberOfCoefficients = 1;
    }
    for(int i = 0; i < this->_numberOfCoefficients; i++){
        Coefficient *temp = new Coefficient(0.0, 1.0);
        this->_coefficients.push_back(temp);
    }
    Coefficient *temp = new Coefficient(0.0, 0.0);
    this->_freeCoeff = temp;
}

double function::functionWithX(double x){
    double f = 0.0;
    for(int i = 0; i < this->_numberOfCoefficients; i++){
        f += this->_coefficients[i]->coeff() * pow(x, this->_coefficients[i]->xPower());
    }
    f += this->_freeCoeff->coeff();
    return f;
}

double function::calculate(double a, double b){
    double result = 0.0;
    double eps1 = 100.0;
    this->a = a;
    this->b = b;
    int i = 0;
    while(eps1 > this->eps()){
        if(functionWithX((this->b + this->a) / 2) > 0){
            this->b = (this->b + this->a) / 2;
            eps1 = this->b - this->a;
        }
        else if(functionWithX((this->b + this->a) / 2) < 0){
            this->a = (this->b + this->a) / 2;
            eps1 = this->b - this->a;
        }
        else
        {
            result = (this->b + this->a) / 2;
            eps1 = 0;
            return result;
        }
        this->_listOfSteps += QString::number(i) + ": (" + QString::number(this->a) + ";\t" + QString::number(this->b) + ");\t eps = " + QString::number(eps1) + "\n";
        i++;
    }
    result = (this->b + this->a) / 2;
    return result;
}

double function::calculateWithEps(double a, double b, double eps){
    this->_eps = eps;
    return this->calculate(a, b);
}

int function::numberOfCoefficients(){
    return this->_numberOfCoefficients;
}

double function::eps(){
    return this->_eps;
}

void function::setCoefficients(QVector<Coefficient *> coefficients){
    this->_coefficients = coefficients;
}

void function::setFreeCoefficient(double coefficient){
    this->_freeCoeff = new Coefficient(coefficient, 0);
}

QString function::listOfSteps(){
    return this->_listOfSteps;
}
