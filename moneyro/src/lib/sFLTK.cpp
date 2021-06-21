#include "lib/sFLTK.hpp"

namespace sFLTK {

  void safeCallback(Fl_Widget *w, void *u) {
    std::function<void()>* teste = reinterpret_cast<std::function<void()>*>(u);

    try {
      (*teste)();
    }
    catch(std::exception&){
    }
  }

  void safeCallbackHandler(Fl_Widget *w, std::function<void()>* func){
    w->callback(safeCallback, func);
  }
}

