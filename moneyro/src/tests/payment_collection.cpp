#include "gtest/gtest.h"
#include "core/PaymentCollection.hpp"
#include "core/Payment.hpp"
#include "core/Account.hpp"

namespace {
  class PaymentCollectionTest : public ::testing::Test {
    protected:
      PaymentCollectionTest() {
      }

      virtual ~PaymentCollectionTest() {
      }


      virtual void SetUp() {
      }

      virtual void TearDown() {
      }
  };

  TEST_F(PaymentCollectionTest, PaymentCollectionSum) {
    Moneyro::PaymentCollection paymentCollection;
    Moneyro::Account account;
    Moneyro::Payment paymentA(1.0, &account);
    Moneyro::Payment paymentB(5.0, &account);
    Moneyro::Payment paymentC(10.0, &account);

    paymentCollection.add(paymentA);
    paymentCollection.add(paymentB);
    paymentCollection.add(paymentC);


    EXPECT_EQ(paymentCollection.getTotal(), 16);

    Moneyro::Payment paymentD(5.0, &account);
    Moneyro::Payment paymentE(10.0, &account);

    paymentCollection.add(paymentE);
    paymentCollection.add(paymentD);

    EXPECT_EQ(paymentCollection.getTotal(), 31);
  }

  TEST_F(PaymentCollectionTest, PaymentCollectionSumMultiple) {

    Moneyro::Account account;

    Moneyro::PaymentCollection paymentCollection;

    Moneyro::Payment paymentA(1.0, &account);
    Moneyro::Payment paymentB(5.0, &account);
    Moneyro::Payment paymentC(10.0, &account);
    std::vector<Moneyro::Payment> payments = {paymentA, paymentB, paymentC};

    paymentCollection.add(payments);

    EXPECT_EQ(paymentCollection.getTotal(), 16);

    Moneyro::Payment paymentD(5.0, &account);
    Moneyro::Payment paymentE(10.0, &account);

    std::vector<Moneyro::Payment> morePayments = { paymentD, paymentE };
    paymentCollection.add(morePayments);


    EXPECT_EQ(paymentCollection.getTotal(), 31);
  }
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
