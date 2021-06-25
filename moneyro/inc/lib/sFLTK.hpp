#ifndef SFLTK_INCLUDED
#define SFLTK_INCLUDED

#include <functional>
#include <string>

#include "FL/Fl_Widget.H"
#include "FL/Fl_Menu_Bar.H"

namespace sFLTK {
  void safeCallback(Fl_Widget *w, void *u);
  void safeCallbackHandler(Fl_Widget *w, std::function<void()>* func);
  void sAddMenuItem(Fl_Menu_Bar *menuBar, std::string label, int shortcut, std::function<void()>* func, int flags = 0);
}

#endif //SFLTK_INCLUDED
