#ifndef MODAL_WINDOW_H
#define MODAL_WINDOW_H

#include <QDialog>
#include "ui_modal_window.h"

namespace Ui {
class modal_window;
}

class modal_window : public QDialog
{
    Q_OBJECT

public:

    explicit modal_window(QWidget *parent = 0);
    ~modal_window();

private:

    Ui::modal_window *ui;
};

#endif // MODAL_WINDOW_H
