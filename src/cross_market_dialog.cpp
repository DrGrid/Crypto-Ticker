#include "cross_market_dialog.h"
#include "ui_cross_market_dialog.h"

cross_market_dialog::cross_market_dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::cross_market_dialog)
{
    ui->setupUi(this);
}

cross_market_dialog::~cross_market_dialog()
{
    delete ui;
}
