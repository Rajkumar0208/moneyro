#include <memory>
#include <iostream>

#include "FL/Fl.h"

#define PL_IMPLEMENTATION 1
#include "palanteer.h"


#include "components/MainWindow.hpp"

int main(){

  plInitAndStart("Moneyro");

  try {

    Fl::scheme("gtk+");
    std::unique_ptr<Moneyro::MainWindow> mainWindow = std::make_unique<Moneyro::MainWindow>();

    return Fl::run();
  } catch(...) {
  }

  plStopAndUninit();

}
