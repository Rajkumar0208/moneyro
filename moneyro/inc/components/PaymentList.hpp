//TODO fazer tabela e desenhar as contas e tal blablabla
//draw_cell e a porra toda (olhar exemplos do fltk)
//


#ifndef MONEYRO_PAYMENT_LIST_INCLUDED
#define MONEYRO_PAYMENT_LIST_INCLUDED

#include <string>
#include <vector>
#include <iostream>
#include <memory>
#include <cmath>

#include "FL/Fl_Table.H"
#include "FL/Fl_Table_Row.H"
#include "FL/fl_draw.H"

#include "core/Payment.hpp"
#include "core/PaymentCollection.hpp"

namespace Moneyro {
  class PaymentList: public Fl_Table_Row {
    public:
      void setPayments(PaymentCollection* payments);
      PaymentList(int x, int y, int w, int h, const char *name, PaymentCollection* payments);
      void addPayment(Payment payment);
      //TODO void removePayment(Payament payment);
    private:
      std::vector<std::string> columnHeaders;
      PaymentCollection* payments;
      void draw();
      void resize_columns();
      void draw_cell(TableContext context, int ROW, int COL, int X, int Y, int W, int H);
      void DrawData(std::string s, int X, int Y, int W, int H);
      void DrawHeader(const char *s, int X, int Y, int W, int H);
  };
}
#endif //MONEYRO_PAYMENT_LIST_INCLUDED
