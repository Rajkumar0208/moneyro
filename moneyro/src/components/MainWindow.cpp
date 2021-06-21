#include "components/MainWindow.hpp"


namespace Moneyro {
  MainWindow::MainWindow() : Fl_Window(640, 800, "Moneyro") {
    begin();

    Fl_Group* leftPanel = new Fl_Group(10,10,250,h());
    {
      tabs = std::make_unique<Fl_Tabs>(10,10,250,250);
      {
        transactionTab =  std::make_unique<Fl_Group>(20,30,245,250, "Transação");
        {
          paymentLabel = std::make_unique<Fl_Input>(20, 40 , 80, 30, "");
          accountChoice = std::make_unique<Fl_Choice>(100, 40, 150, 30);
          addButton = std::make_unique<Fl_Button>(20, 70, 160, 30, " Add");
        }
        transactionTab->resizable(0);
        transactionTab->end();
      }
      tabs->resizable(0);
      tabs->end();

      Fl_Group* empty = new Fl_Group(10,250,250,h());
      leftPanel->resizable(empty);
    }
    leftPanel->end();


    accounts = std::vector<Account>();
    accounts.push_back(Account("Conta 1"));
    accounts.push_back(Account("Conta 2"));

    for(auto account : accounts) {
      accountChoice->add(account.getName().c_str(), 0, [](Fl_Widget *w, void *u){
          MainWindow* window = reinterpret_cast<MainWindow*>(u);
          Fl_Choice* accountChoice = reinterpret_cast<Fl_Choice*>(w);

          window->selectedAccount = &(window->accounts.at(accountChoice->value()));

          }, this);
    };

    payments = PaymentCollection();

    testCallback = [this](){
      std::string inputValue = paymentLabel.get()->value();

      try {
        if(selectedAccount) {
          paymentList.get()->addPayment((Payment(std::stol(inputValue), selectedAccount)));
        }
      } catch(const std::exception&) {

      }
      paymentLabel->value(0);

    };


    sFLTK::safeCallbackHandler(addButton.get(), &testCallback);

    paymentList = std::make_unique<PaymentList>(x()+270, y()+10, w(), h()-30, "Contas", &payments);
    paymentList->end();

    resizable(*(paymentList.get()));
    end();
    show();
  }

}




