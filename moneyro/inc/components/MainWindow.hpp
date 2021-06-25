#ifndef MONEYRO_MAIN_WINDOW_INCLUDED
#define MONEYRO_MAIN_WINDOW_INCLUDED

#include <iostream>
#include <memory>
#include <tuple>
#include <functional>

#include "FL/Fl_Window.H"
#include "FL/Fl_Double_Window.H"
#include "FL/Fl_Table.H"
#include "FL/Fl_Box.H"
#include "FL/Fl_Table_Row.H"
#include "FL/Fl_Table.H"
#include "FL/Fl_Menu_Bar.H"
#include "FL/Fl_Menu_Item.H"
#include "FL/Fl_Button.H"
#include "FL/Fl_Group.H"
#include "FL/Fl_Input.H"
#include "FL/Fl_Input_Choice.H"
#include "FL/Fl_Choice.H"
#include "FL/Fl_Menu_Button.H"
#include "FL/Fl_Tabs.H"
#include "FL/Fl_File_Chooser.H"

#include "lib/sFLTK.hpp"
#include "core/Profile.hpp"
#include "core/Account.hpp"
#include "core/PaymentCollection.hpp"
#include "components/PaymentList.hpp"

namespace Moneyro {


    class MainWindow: public Fl_Double_Window {

      private:
        std::unique_ptr<PaymentList> paymentList;
        std::unique_ptr<Fl_Tabs> tabs;
        std::unique_ptr<Fl_Menu_Bar> menuBar;
        std::unique_ptr<Fl_Group> transactionTab;
        std::unique_ptr<Fl_Group> leftPanel;
        std::unique_ptr<Fl_Group> empty;
        std::unique_ptr<Fl_Input> paymentLabel;
        std::unique_ptr<Fl_Button> addButton;
        std::unique_ptr<Fl_Choice> accountChoice;
        std::function<void()> testCallback;
        void openProfile(bool newProfile = true);
        PaymentCollection payments;
        Account* selectedAccount;
      public:
        //static void safeCallback(Fl_Widget *w, void *u);
        MainWindow();
        std::unique_ptr<Profile> profile;
    };
}

#endif //MONEYRO_MAIN_WINDOW_INCLUDED
