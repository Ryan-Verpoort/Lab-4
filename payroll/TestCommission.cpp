#include "employee.h"
#include "fixed.h"
#include "hourly.h"
#include "Commission.h"

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