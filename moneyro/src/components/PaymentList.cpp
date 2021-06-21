#include "components/PaymentList.hpp"

namespace Moneyro {
  PaymentList::PaymentList(int x, int y, int w, int h, const char *name= 0, PaymentCollection* payments = nullptr): Fl_Table(x,y,w,h,0){
    box(FL_NO_BOX);
    columnHeaders = { "Valor", "Conta", "Issue Date" };
    cols(columnHeaders.size()+1);
    col_width_all(300);

    this->setPayments(payments);

    row_height_all(20);
    row_resize(0);

    col_header(1);
    col_resize(1);
    end();
  };

  void PaymentList::setPayments(PaymentCollection* payments) {
    this->payments = payments;
    rows(this->payments->getPayments().size() + 1);
  }

  void PaymentList::addPayment(Payment payment) {
    this->payments->add(payment);
    rows(this->payments->getPayments().size() + 1);
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
              DrawData(payment.getAccount()->getName(),X,Y,W,H);
              break;
            case 2:
              DrawData(payment.getIssueDate().format("%F"),X,Y,W,H);
              break;
          }
        } else {
          if(COL == 0){
            DrawData("Total: " + std::to_string(payments->getTotal()),X,Y,W,H);
          } else {
            fl_push_clip(X,Y,W,H);
            fl_color(FL_WHITE); fl_rectf(X,Y,W,H);
            //fl_color(FL_GRAY0); fl_draw(s.c_str(), X,Y,W,H, FL_ALIGN_LEFT);
            //fl_color(color()); fl_rect(X,Y,W,H);
            fl_pop_clip();

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
    fl_color(FL_GRAY0); fl_draw(s.c_str(), X,Y,W,H, FL_ALIGN_LEFT);
    //fl_color(color()); fl_rect(X,Y,W,H);
    fl_pop_clip();
  }

  void PaymentList::DrawHeader(const char *s, int X, int Y, int W, int H) {
    fl_push_clip(X,Y,W,H);
    fl_color(FL_GRAY); fl_rectf(X,Y,W,H);
    //fl_draw_box(FL_THIN_UP_BOX, X,Y,W,H, row_header_color());
    fl_color(FL_BLACK); fl_draw(s, X,Y,W,H, FL_ALIGN_LEFT);
    fl_pop_clip();
  }
}
