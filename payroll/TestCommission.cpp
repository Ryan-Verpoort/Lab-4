#include "employee.h"
#include "fixed.h"
#include "hourly.h"
#include "Commission.h"

#include <vector>
using std::vector;

#include <memory>
using std::make_shared;
using std::shared_ptr;

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest.h>

TEST_CASE("Earnings Returned Correct")
{
    shared_ptr<CommissionWorker> commissionWorker_ptr = make_shared<CommissionWorker>("John", "Smith", 500, 10.8, 5);

    CHECK(554.0 == commissionWorker_ptr->earnings());
}

TEST_CASE("Set New Base Salary")
{
    shared_ptr<CommissionWorker> commissionWorker_ptr = make_shared<CommissionWorker>("John", "Smith", 500, 10.8, 5);
    commissionWorker_ptr->SetBaseSalary(580);

    CHECK(634.0 == commissionWorker_ptr->earnings());
}

TEST_CASE("Set New Commision")
{
    shared_ptr<CommissionWorker> commissionWorker_ptr = make_shared<CommissionWorker>("John", "Smith", 500, 10.8, 5);
    commissionWorker_ptr->SetCommisionPerItem(20.78);

    CHECK(603.9 == commissionWorker_ptr->earnings());
}

TEST_CASE("Set New Number Of items")
{
    shared_ptr<CommissionWorker> commissionWorker_ptr = make_shared<CommissionWorker>("John", "Smith", 500, 75.95, 5);
    commissionWorker_ptr->SetItemsSold(20);

    CHECK(2019.0 == commissionWorker_ptr->earnings());
}

TEST_CASE("Total Employee Wages Calculation")
{
    shared_ptr<CommissionWorker> commissionWorker_ptr = make_shared<CommissionWorker>("John", "Smith", 500, 10.8, 5);
    shared_ptr<FixedRateWorker> fixed_rate_ptr = make_shared<FixedRateWorker>("Ted", "Ramgasamy", 905.00);
    shared_ptr<HourlyWorker> hourly_ptr = make_shared<HourlyWorker>("Louisa", "Mahlungu", 12.00, 52);
    vector<shared_ptr<Employee> > employees = { commissionWorker_ptr, fixed_rate_ptr, hourly_ptr };

    CHECK(2155.0 == TotalEmployeeWages(employees));
}