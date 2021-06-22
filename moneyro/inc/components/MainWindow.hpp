#ifndef MONEYRO_MAIN_WINDOW_INCLUDED
#define MONEYRO_MAIN_WINDOW_INCLUDED

#include <iostream>
#include <memory>
#include <tuple>
#include <functional>

#include "FL/Fl_Window.H"
#include "FL/Fl_Table.H"
#include "FL/Fl_Box.H"
#include "FL/Fl_Table_Row.H"
#include "FL/Fl_Table.H"
#include "FL/Fl_Button.H"
#include "FL/Fl_Group.H"
#include "FL/Fl_Input.H"
#include "FL/Fl_Input_Choice.H"
#include "FL/Fl_Choice.H"
#include "FL/Fl_Menu_Button.H"
#include "FL/Fl_Tabs.H"

#include "lib/sFLTK.hpp"
#include "core/Profile.hpp"
#include "core/Account.hpp"
#include "core/PaymentCollection.hpp"
#include "components/PaymentList.hpp"

namespace Moneyro {

   struct addButtonArguments {
     PaymentCollection* payments;
     std::vector<Account>* accounts;
   };

    class MainWindow: public Fl_Window {

      private:
        std::unique_ptr<PaymentList> paymentList;
        std::unique_ptr<Fl_Tabs> tabs;
        std::unique_ptr<Fl_Group> transactionTab;
        std::unique_ptr<Fl_Input> paymentLabel;
        std::unique_ptr<Fl_Button> addButton;
        std::unique_ptr<Fl_Choice> accountChoice;
        std::vector<Account> accounts;
        std::function<void()> testCallback;
        addButtonArguments addButtonParams;
        PaymentCollection payments;
        Account* selectedAccount;
      public:
        //static void safeCallback(Fl_Widget *w, void *u);
        MainWindow();
        Profile* profile;
    };
}

#endif //MONEYRO_MAIN_WINDOW_INCLUDED
