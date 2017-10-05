#ifndef COMMISSION_H
#define COMMISSION_H

#include "Employee.h"

class CommissionWorker : public Employee
{
public:
    CommissionWorker(const string& first_name,
        const string& surname,
        double BaseSalary,
        double ItemCommision,
        int Items);

    void SetBaseSalary(double BaseSalary);
    void SetCommisionPerItem(double ItemCommision);
    void SetItemsSold(int Items);

    virtual double earnings() const override;
    void print() const;

private:
    double _BaseSalary;
    double _ItemCommision;
    int _Items;
};

#endif