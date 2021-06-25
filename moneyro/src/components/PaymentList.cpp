#include "components/PaymentList.hpp"

namespace Moneyro {
  PaymentList::PaymentList(int x, int y, int w, int h, const char *name= 0, PaymentCollection* payments = nullptr): Fl_Table_Row(x,y,w,h,0){
    //table_box(FL_NO_BOX);
    //box(FL_NO_BOX);
    columnHeaders = { "Valor", "Conta", "Issue Date" };
    cols(columnHeaders.size());
    std::cout << w << std::endl;

    col_header_height(30);
    for(unsigned int i = 0; i < columnHeaders.size(); i++){
      col_width(i, w/columnHeaders.size());
    }

    row_header(0);

    col_header(1);
    col_resize(1);
    end();
  };

  void PaymentList::setPayments(PaymentCollection* payments) {
    if(payments){
      this->payments = payments;
      rows(this->payments->getPayments().size());
      row_height_all(30);
    } else {
      std::cout << "erro" << std::endl;
    }
  }

  void PaymentList::addPayment(Payment payment) {
    if(payments){
      this->payments->add(payment);
      std::cout << Fl_Table_Row::children() << std::endl;
      rows(this->payments->getPayments().size());
      row_height_all(30);
    row_resize_min(100);
    } else {
      std::cout << "Sem pagamento" << std::endl;
    }

  }

  void PaymentList::resize_columns(){
    int total_columns_width = 0;
    int lastColumIndex = columnHeaders.size()-1;
    for(int i = 0; i < lastColumIndex; i++){
      total_columns_width += col_width(i);
    }
    if((total_columns_width + row_resize_min() ) <= w()) {
        col_width(lastColumIndex, std::lround(w()-total_columns_width-2));
    }
  }

  void PaymentList::draw(){
    resize_columns();
    Fl_Table_Row::draw();
  }

  void PaymentList::draw_cell(TableContext context, int ROW=0, int COL=0, int X=0, int Y=0, int W=0, int H=0) {
    switch ( context ) {
      case CONTEXT_STARTPAGE:
        fl_font(FL_HELVETICA, 16);
        return;
      case CONTEXT_COL_HEADER:
        DrawHeader(COL < static_cast<int>(columnHeaders.size()) ? columnHeaders[COL].c_str() : "",X,Y,W,H);
        return;
      case CONTEXT_CELL:
        if(payments && ROW < static_cast<int>(this->payments->getPayments().size())) {
          Payment payment = this->payments->getPayments().at(ROW);
          switch(COL) {
            case 0:
              DrawData(std::to_string(payment.getValue()),X,Y,W,H);
              break;
            case 1:
              DrawData(payment.getAccount()->name(),X,Y,W,H);
              break;
            case 2:
              DrawData(payment.getIssueDate().format("%F"),X,Y,W,H);
              break;
          }
        }
        return;
      default:
        return;
    }
  }

  void PaymentList::DrawData(std::string s, int X, int Y, int W, int H) {
    fl_push_clip(X,Y,W,H);
    fl_color(FL_WHITE); 
    fl_rectf(X,Y,W,H);
    fl_color(FL_GRAY0); 
    fl_draw(s.c_str(), X+10,Y+2,W,H, FL_ALIGN_LEFT);
    fl_pop_clip();
  }

  void PaymentList::DrawHeader(const char *s, int X, int Y, int W, int H) {
    fl_push_clip(X,Y,W,H);
    fl_color(FL_GRAY); 
    fl_rectf(X,Y,W,H);
    fl_color(FL_BLACK);
    fl_draw(s, X+10,Y,W,H, FL_ALIGN_LEFT);
    fl_pop_clip();
  }
}
