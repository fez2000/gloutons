#include "afficher.h"
#include "ui_afficher.h"
#include "fontions.h"

Afficher::Afficher(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Afficher)
{
    ui->setupUi(this);

    new QListWidgetItem(tr((std::string("Les pieces sont : ")+to_str_p()).c_str()),this->ui->myListPiece);
    new QListWidgetItem(tr((std::string("Le type des pieces est : ")+ get_type()).c_str()),this->ui->myListPiece);
}

Afficher::~Afficher()
{
    delete ui;
}
