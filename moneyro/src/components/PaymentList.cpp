#include "components/PaymentList.hpp"

namespace Moneyro {
  PaymentList::PaymentList(int x, int y, int w, int h, const char *name=0, std::shared_ptr<std::vector<Payment>> payments = nullptr): Fl_Table(x,y,w,h,name){
    columnHeaders = { "Valor", "Carteira", "Data" };
    this->setPayments(payments);

    rows(this->payments.get()->size() + 1);
    row_height_all(20);
    row_resize(0);

    cols(columnHeaders.size());
    col_header(1);
    col_width_all(80);
    col_resize(1);
    end();
  };

  void PaymentList::setPayments(std::shared_ptr<std::vector<Payment>> payments) {
    this->payments = payments;
    this->calculateTotal();
  }

  void PaymentList::calculateTotal() {
    this->total = 0;
    if(this->payments){
      std::vector<Payment> payments = *this->payments.get();
      for(auto  i : payments){
        this->total += i.getValue();
      }
    } else {
      this->total = 0;
    }
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
        if(ROW < static_cast<int>(this->payments.get()->size())) {
          Payment payment = this->payments.get()->at(ROW);
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
            DrawData(std::to_string(this->total),X,Y,W,H);
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
