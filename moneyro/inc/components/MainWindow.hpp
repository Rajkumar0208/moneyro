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

namespace Moneyro {
    class MainWindow: public Fl_Window {
      private:
        std::unique_ptr<PaymentList> paymentList;
        std::shared_ptr<std::vector<Account>> accounts;
        std::shared_ptr<std::vector<Payment>> payments;
      public:
        MainWindow();
        Profile profile;
    };
}

#endif //MONEYRO_MAIN_WINDOW_INCLUDED
