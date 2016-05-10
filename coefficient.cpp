#include "coefficient.h"

Coefficient::Coefficient(){
    this->_coeff = 0.0;
    this->_xPower = 0.0;
}

Coefficient::Coefficient(double coeff, double xPower){
    this->_coeff = coeff;
    this->_xPower = xPower;
}

double Coefficient::coeff(){
    return this->_coeff;
}

double Coefficient::xPower(){
    return this->_xPower;
}
