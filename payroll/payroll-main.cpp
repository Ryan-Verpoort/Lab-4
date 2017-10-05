// Using the Employee hierarchy - inheritance and polymorphism

#include <memory>
using std::shared_ptr;
using std::make_shared;

#include <iomanip>
using std::setiosflags;
using std::setprecision;
using std::ios;

#include <iostream>
using std::endl;
using std::cout;

#include "employee.h"
#include "fixed.h"
#include "hourly.h"

int main()
{
    // set output formatting for floating point types
    cout << setiosflags(ios::fixed | ios::showpoint) << setprecision(2);

    shared_ptr<FixedRateWorker> fixed_rate_ptr = make_shared<FixedRateWorker>("Ted", "Ramgasamy", 905.00);
    shared_ptr<HourlyWorker> hourly_ptr = make_shared<HourlyWorker>("Louisa", "Mahlungu", 12.00, 52);

    fixed_rate_ptr->print();                                    // static binding
    cout << " earned R " << fixed_rate_ptr->earnings() << endl; // dynamic binding

    hourly_ptr->print();                                    // static binding
    cout << " earned R " << hourly_ptr->earnings() << endl; // dynamic binding

    cout << endl;
    cout << "Why is the output below not identical to the output above ?" << endl;
    cout << endl;

    shared_ptr<Employee> employee1_ptr = make_shared<FixedRateWorker>("Ted", "Ramgasamy", 905.00);
    shared_ptr<Employee> employee2_ptr = make_shared<HourlyWorker>("Louisa", "Mahlungu", 12.00, 52);

    employee1_ptr->print();                                    // static binding
    cout << " earned R " << employee1_ptr->earnings() << endl; // dynamic binding

    employee2_ptr->print();                                    // static binding
    cout << " earned R " << employee2_ptr->earnings() << endl; // dynamic binding

    cout << endl;
    return 0;
}

// The Print Function Was not decleared a Virtual This meant the main did not know which class it was
// being taken from so it did not display what the employee salary was part of