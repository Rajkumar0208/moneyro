#include "components/MainWindow.hpp"

namespace Moneyro {
  MainWindow::MainWindow() : Fl_Window(640, 800) {
    this->begin();
    this->accounts = std::vector<Account>();
    this->accounts.push_back(Account("Conta 1"));
    this->accounts.push_back(Account("Conta 2"));

    this->payments = PaymentCollection();
    this->payments.add(Payment(0, &(accounts.at(0)) ,  &(accounts.at(1)) ));
    this->payments.add(Payment(30.1, &(accounts.at(1)) ,  &(accounts.at(0)) ));
    this->payments.add(Payment(25.5, &(accounts.at(1)) ,  &(accounts.at(0)) ));
    this->paymentList = std::make_unique<PaymentList>(0, 0, 640, 800, "Contas", &payments);
    this->end();
    this->show();
  }
}
