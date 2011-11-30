#ifndef CARDWIEW_H
#define CARDWIEW_H

#include <QDialog>

namespace Ui {
    class CardView;
}

class CardView : public QDialog
{
    Q_OBJECT

public:
    explicit CardView(QWidget *parent = 0);
    ~CardView();

private:
    Ui::CardView *ui;
};

#endif // CARDWIEW_H
