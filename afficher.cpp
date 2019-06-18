#include "afficher.h"
#include "ui_afficher.h"

Afficher::Afficher(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Afficher)
{
    ui->setupUi(this);
}

Afficher::~Afficher()
{
    delete ui;
}
