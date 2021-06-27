#include <memory>
#include <iostream>

#include "FL/Fl.h"



#include "components/MainWindow.hpp"

int main(){


  try {

    Fl::scheme("gtk+");
    std::unique_ptr<Moneyro::MainWindow> mainWindow = std::make_unique<Moneyro::MainWindow>();

    return Fl::run();
  } catch(...) {
  }


}
