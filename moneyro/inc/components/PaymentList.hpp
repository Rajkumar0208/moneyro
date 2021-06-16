//TODO fazer tabela e desenhar as contas e tal blablabla
//draw_cell e a porra toda (olhar exemplos do fltk)
//


#ifndef MONEYRO_PAYMENT_LIST_INCLUDED
#define MONEYRO_PAYMENT_LIST_INCLUDED

#include <string>
#include <vector>
#include <iostream>
#include <memory>

#include "FL/Fl_Table.H"
#include "FL/fl_draw.H"

#include "core/Payment.hpp"

namespace Moneyro {
  class PaymentList: Fl_Table {
    private:
      long double total;
      std::vector<std::string> columnHeaders;
      std::shared_ptr<std::vector<Payment>> payments;
      void calculateTotal();
    public:
      void setPayments(std::shared_ptr<std::vector<Payment>> payments);
      PaymentList(int x, int y, int w, int h, const char *name, std::shared_ptr<std::vector<Payment>> payments);
      void draw_cell(TableContext context, int ROW, int COL, int X, int Y, int W, int H);
      void DrawData(std::string s, int X, int Y, int W, int H);
      void DrawHeader(const char *s, int X, int Y, int W, int H);
  };
}
#endif //MONEYRO_PAYMENT_LIST_INCLUDED
