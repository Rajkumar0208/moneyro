#ifndef MONEYRO_MAIN_WINDOW_INCLUDED
#define MONEYRO_MAIN_WINDOW_INCLUDED

#include <iostream>
#include <memory>

#include "FL/Fl_Window.H"
#include "FL/Fl_Table.H"
#include "FL/Fl_Box.H"
#include "FL/Fl_Table_Row.H"
#include "FL/Fl_Table.H"
#include "FL/Fl_Button.H"

#include "core/Profile.hpp"
#include "core/Account.hpp"
#include "components/PaymentList.hpp"
#include "core/PaymentCollection.hpp"

namespace Moneyro {
    class MainWindow: public Fl_Window {
      private:
        std::unique_ptr<PaymentList> paymentList;
        std::vector<Account> accounts;
        PaymentCollection payments;
      public:
        MainWindow();
        Profile profile;
    };
}

#endif //MONEYRO_MAIN_WINDOW_INCLUDED
