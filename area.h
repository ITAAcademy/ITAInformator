#ifndef AREA_H
#define AREA_H

#include <QDialog>

namespace Ui {
class Area;
}

class Area : public QDialog
{
    Q_OBJECT

public:
    explicit Area(QWidget *parent = 0);
    ~Area();

private:
    Ui::Area *ui;
};

#endif // AREA_H
