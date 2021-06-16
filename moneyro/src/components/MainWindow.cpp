#include "components/MainWindow.hpp"

namespace Moneyro {
  MainWindow::MainWindow() : Fl_Window(640, 800) {
    this->begin();
    this->accounts = std::make_shared<std::vector<Account>>();
    this->accounts.get()->push_back(Account("Conta 1"));
    this->accounts.get()->push_back(Account("Conta 2"));

    this->payments = std::make_shared<std::vector<Payment>>();
    this->payments.get()->push_back(Payment(0, &(accounts.get()->at(0)),  &(accounts.get()->at(1))));
    this->payments.get()->push_back(Payment(30.1, &(accounts.get()->at(1)),  &(accounts.get()->at(0))));
    this->payments.get()->push_back(Payment(25.5, &(accounts.get()->at(1)),  &(accounts.get()->at(0))));
    this->paymentList = std::make_unique<PaymentList>(0, 0, 640, 800, "Contas", this->payments);
    this->end();
    this->show();
  }

}
