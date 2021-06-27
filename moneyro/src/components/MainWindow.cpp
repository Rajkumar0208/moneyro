#include "components/MainWindow.hpp"


namespace Moneyro {
  MainWindow::MainWindow() : Fl_Double_Window(640, 800, "Moneyro") {
    begin();

    profile = std::make_unique<Profile>();

    menuBar = std::make_unique<Fl_Menu_Bar>(0,0,w(),30);
    {
      menuBar->box(FL_ENGRAVED_BOX);

      menuBar->add("File/Save", FL_CTRL+'s', [](Fl_Widget* w, void* u){
          MainWindow* mainWindow = static_cast<MainWindow*>(u);

          //if(window->profile.filename())
          //  mainWindow->profile->saveAll(mainWindow->profile.filename());
          ////else
          //TODO Request filename here


          },this);

      menuBar->add("File/Load", FL_CTRL+'o', [](Fl_Widget* w, void* u){
            MainWindow* mainWindow = static_cast<MainWindow*>(u);
            mainWindow->openProfile(false);
          }, this);
    }

    leftPanel = std::make_unique<Fl_Group>(10,menuBar->h()+10,250,h());
    {
      tabs = std::make_unique<Fl_Tabs>(leftPanel->x(),leftPanel->y(),250,250);
      {
        transactionTab =  std::make_unique<Fl_Group>(tabs->x()+10,tabs->y()+20,245,250, "Transação");
        {
          paymentLabel = std::make_unique<Fl_Input>(transactionTab->x(), tabs->y()+30, 80, 30, "");
          accountChoice = std::make_unique<Fl_Choice>(paymentLabel->x()+paymentLabel->w()+10, tabs->y()+30, 140, 30);
          int addButtonWidth = 100;
          addButton = std::make_unique<Fl_Button>(transactionTab->h() - addButtonWidth, accountChoice->y()+accountChoice->h()+10, addButtonWidth, 30, "Add");
          addButton->shortcut(FL_Enter);
        }
        transactionTab->resizable(0);
        transactionTab->end();
      }
      tabs->resizable(0);
      tabs->end();

      //TODO replace empty for charts later
      empty = std::make_unique<Fl_Group>(10,leftPanel->h(),250,h());
      leftPanel->resizable(empty.get());
    }
    leftPanel->end();



    testCallback = [this](){
      std::string inputValue = paymentLabel.get()->value();

      try {
        if(selectedAccount) {
          paymentList->addPayment((Payment(std::stol(inputValue), selectedAccount)));
        }
      } catch(const std::exception&) {

      }
      paymentLabel->value(0);

    };

    sFLTK::safeCallbackHandler(addButton.get(), &testCallback);

    paymentList = std::make_unique<PaymentList>(x()+270, menuBar->h()+10, 360, h()-60, "Contas", nullptr);


    

    resizable(*(paymentList.get()));
    end();

    Fl::visual(FL_DOUBLE|FL_INDEX);
    show();
    openProfile(true);
  }

  void MainWindow::openProfile(bool newProfile){
    if(newProfile){
      profile = std::make_unique<Profile>();
    } else {
      std::string filename = fl_file_chooser("Teste", "*.db", "test.db", 0 );
      profile = std::make_unique<Profile>(filename);
    }

    paymentList->setPayments(profile->getPayments());

    accountChoice->clear();
    selectedAccount = nullptr;

    for(auto account : *(profile->getAccounts())) {
      accountChoice->add(account.name().c_str(), 0, [](Fl_Widget *w, void *u){
          MainWindow* window = static_cast<MainWindow*>(u);
          Fl_Choice* accountChoice = static_cast<Fl_Choice*>(w);

          window->selectedAccount = &(window->profile->getAccounts()->at(accountChoice->value()));

          }, this);
    };

    accountChoice->redraw();
  }


}




