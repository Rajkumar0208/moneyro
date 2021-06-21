#include "FL/Fl.h"
#include <memory>

#include "components/MainWindow.hpp"

int main(){

  std::unique_ptr<Moneyro::MainWindow> mainWindow = std::make_unique<Moneyro::MainWindow>();


  return Fl::run();
}
