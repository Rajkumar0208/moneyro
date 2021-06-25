#include "lib/sFLTK.hpp"

namespace sFLTK {

  void safeCallback(Fl_Widget *w, void *u) {
    std::function<void()>* callback = reinterpret_cast<std::function<void()>*>(u);

    try {
      (*callback)();
    }
    catch(...){
    }
  }

  void safeCallbackHandler(Fl_Widget *w, std::function<void()>* func){
    w->callback(safeCallback, func);
  }

  void sAddMenuItem(Fl_Menu_Bar *menuBar, std::string label, int shortcut, std::function<void()>* func, int flags) {
    menuBar->add(label.c_str(), shortcut, safeCallback, func, flags);
  }
}

