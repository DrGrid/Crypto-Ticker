#ifndef CROSS_MARKET_DIALOG_H
#define CROSS_MARKET_DIALOG_H

#include <QDialog>

namespace Ui {
class cross_market_dialog;
}

class cross_market_dialog : public QDialog
{
    Q_OBJECT

public:
    explicit cross_market_dialog(QWidget *parent = 0);
    ~cross_market_dialog();

private:
    Ui::cross_market_dialog *ui;
};

#endif // CROSS_MARKET_DIALOG_H
