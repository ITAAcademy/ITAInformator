#ifndef DISTANCEANDLENGTH_H
#define DISTANCEANDLENGTH_H

#include <QDialog>

namespace Ui {
class DistanceAndLength;
}

class DistanceAndLength : public QDialog
{
    Q_OBJECT

public:
    explicit DistanceAndLength(QWidget *parent = 0);
    ~DistanceAndLength();

private:
    Ui::DistanceAndLength *ui;
};

#endif // DISTANCEANDLENGTH_H
