#include "Commission.h"

CommissionWorker::CommissionWorker(const string& first_name,
    const string& surname,
    double BaseSalary,
    double ItemCommision,
    int Items)
    : Employee(first_name, surname)
    , _BaseSalary(BaseSalary)
    , _ItemCommision(ItemCommision)
    , _Items(Items){};

void CommissionWorker::SetBaseSalary(double BaseSalary)
{
    _BaseSalary = BaseSalary;
}

void CommissionWorker::SetItemsSold(int Items)
{
    _Items = Items;
}

void CommissionWorker::SetCommisionPerItem(double ItemCommision)
{
    _ItemCommision = ItemCommision;
}

double CommissionWorker::earnings() const
{
    return _BaseSalary + (_ItemCommision * _Items);
}

void CommissionWorker::print() const
{
    cout << "CommissionWorker: ";
    // re-use Employee's print function (DRY principle)
    Employee::print();
}