#ifndef VOLUMECAPACITY_H
#define VOLUMECAPACITY_H

#include <QDialog>

namespace Ui {
class VolumeCapacity;
}

class VolumeCapacity : public QDialog
{
    Q_OBJECT

public:
    explicit VolumeCapacity(QWidget *parent = 0);
    ~VolumeCapacity();

private:
    Ui::VolumeCapacity *ui;
};

#endif // VOLUMECAPACITY_H
