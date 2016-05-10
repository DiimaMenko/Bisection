#ifndef COEFFICIENT_H
#define COEFFICIENT_H


class Coefficient
{
private:
    double _coeff;
    double _xPower;
public:
    Coefficient();
    Coefficient(double coeff, double xPower);
    double coeff();
    double xPower();
};

#endif // COEFFICIENT_H
