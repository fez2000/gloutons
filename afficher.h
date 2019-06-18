#ifndef AFFICHER_H
#define AFFICHER_H

#include <QDialog>
#include <QListWidgetItem>
namespace Ui {
class Afficher;
}

class Afficher : public QDialog
{
    Q_OBJECT

public:
    explicit Afficher(QWidget *parent = 0);
    ~Afficher();

private:
    Ui::Afficher *ui;
};

#endif // AFFICHER_H
