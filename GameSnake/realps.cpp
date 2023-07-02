#include "realps.h"
#include "ui_realps.h"

realps::realps(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::realps)
{
    ui->setupUi(this);
}

realps::~realps()
{
    delete ui;
}
