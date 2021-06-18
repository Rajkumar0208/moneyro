#include "components/MainWindow.hpp"

namespace Moneyro {
  MainWindow::MainWindow() : Fl_Window(640, 800) {


    begin();
    paymentLabel = std::make_unique<Fl_Input>(x(), y(), 80, 30, "");
    addButton = std::make_unique<Fl_Button>(x()+80, y(), 160, 30, " Add");

    //group.resizable(0);
    //group.begin();

    accounts = std::vector<Account>();
    accounts.push_back(Account("Conta 1"));
    accounts.push_back(Account("Conta 2"));


    payments = PaymentCollection();

    addButton.get()->callback([](Fl_Widget *w, void *u ){

        MainWindow* window = reinterpret_cast<MainWindow*>(u);

          std::string inputValue = window->paymentLabel.get()->value();
          try {
            window->paymentList.get()->addPayment((Payment(std::stol(inputValue), &(window->accounts.at(0)) ,  &(window->accounts.at(1)) )));
          } catch(const std::exception&) {

          }
          window->paymentLabel->value(0);


          std::cout << window->payments.getTotal() << std::endl;

        }, this);

    paymentList = std::make_unique<PaymentList>(x(), y()+30, w(), h()-30, "Contas", &payments);

    //group.end();
    end();
    show();
  }

}
