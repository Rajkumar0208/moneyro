#ifndef SFLTK_INCLUDED
#define SFLTK_INCLUDED

#include "FL/Fl_Widget.H"
#include <functional>

namespace sFLTK {
  void safeCallback(Fl_Widget *w, void *u);
  void safeCallbackHandler(Fl_Widget *w, std::function<void()>* func);
}

#endif //SFLTK_INCLUDED
