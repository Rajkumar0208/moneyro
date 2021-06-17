#include "components/PaymentList.hpp"

namespace Moneyro {
  PaymentList::PaymentList(int x, int y, int w, int h, const char *name=0, PaymentCollection* payments = nullptr): Fl_Table(x,y,w,h,name){
    columnHeaders = { "Valor", "Carteira", "Data" };
    this->setPayments(payments);

    rows(this->payments->getPayments().size() + 1);
    row_height_all(20);
    row_resize(0);

    cols(columnHeaders.size());
    col_header(1);
    col_width_all(80);
    col_resize(1);
    end();
  };

  void PaymentList::setPayments(PaymentCollection* payments) {
    this->payments = payments;
  }

  //TODO filter by name

  void PaymentList::draw_cell(TableContext context, int ROW=0, int COL=0, int X=0, int Y=0, int W=0, int H=0) {
    switch ( context ) {
      case CONTEXT_STARTPAGE:
        fl_font(FL_HELVETICA, 16);
        return;
      case CONTEXT_COL_HEADER:
        DrawHeader(COL < static_cast<int>(columnHeaders.size()) ? columnHeaders[COL].c_str() : "",X,Y,W,H);
        return;
      case CONTEXT_CELL:
        if(ROW < static_cast<int>(this->payments->getPayments().size())) {
          Payment payment = this->payments->getPayments().at(ROW);
          switch(COL) {
            case 0:
              DrawData(std::to_string(payment.getValue()),X,Y,W,H);
              break;
            case 1:
              DrawData(payment.getSource()->getName(),X,Y,W,H);
              break;
            case 2:
              DrawData(payment.getDestination()->getName(),X,Y,W,H);
              break;
          }
        } else {
          if(COL == 0){
            DrawData(std::to_string(payments->getTotal()),X,Y,W,H);
          }

        }
        return;
      default:
        return;
    }
  }

  void PaymentList::DrawData(std::string s, int X, int Y, int W, int H) {
    fl_push_clip(X,Y,W,H);
    fl_color(FL_WHITE); fl_rectf(X,Y,W,H);
    fl_color(FL_GRAY0); fl_draw(s.c_str(), X,Y,W,H, FL_ALIGN_CENTER);
    //fl_color(color()); fl_rect(X,Y,W,H);
    fl_pop_clip();
  }

  void PaymentList::DrawHeader(const char *s, int X, int Y, int W, int H) {
    fl_push_clip(X,Y,W,H);
    //fl_draw_box(FL_THIN_UP_BOX, X,Y,W,H, row_header_color());
    fl_color(FL_BLACK);
    fl_draw(s, X,Y,W,H, FL_ALIGN_CENTER);
    fl_pop_clip();
  }
}
