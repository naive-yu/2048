#include "MyCPlus.h"
#include "./ui_MyCPlus.h"

MyCPlus::MyCPlus(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MyCPlus)
{
    ui->setupUi(this);
}

MyCPlus::~MyCPlus()
{
    delete ui;
}

