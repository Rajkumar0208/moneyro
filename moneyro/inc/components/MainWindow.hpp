#ifndef MONEYRO_MAIN_WINDOW_INCLUDED
#define MONEYRO_MAIN_WINDOW_INCLUDED

#include <iostream>
#include <memory>
#include <tuple>

#include "FL/Fl_Window.H"
#include "FL/Fl_Table.H"
#include "FL/Fl_Box.H"
#include "FL/Fl_Table_Row.H"
#include "FL/Fl_Table.H"
#include "FL/Fl_Button.H"
#include "FL/Fl_Group.H"
#include "FL/Fl_Input.H"

#include "core/Profile.hpp"
#include "core/Account.hpp"
#include "components/PaymentList.hpp"
#include "core/PaymentCollection.hpp"

namespace Moneyro {

   struct addButtonArguments {
     PaymentCollection* payments;
     std::vector<Account>* accounts;
   };

    class MainWindow: public Fl_Window {
      private:
        std::unique_ptr<PaymentList> paymentList;
        std::unique_ptr<Fl_Input> paymentLabel;
        std::unique_ptr<Fl_Button> addButton;
        std::vector<Account> accounts;
        addButtonArguments addButtonParams;
        PaymentCollection payments;
      public:
        MainWindow();
        Profile profile;
    };
}

#endif //MONEYRO_MAIN_WINDOW_INCLUDED
