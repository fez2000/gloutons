#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "fontions.h"
#include "welcome.h"
#include "afficher.h"
#include <QMainWindow>
#include <QMessageBox>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = NULL);

    ~MainWindow();

private slots:
    void on_calculer_clicked();

    void on_lineEdit_editingFinished();

public slots:
    void alert(const char * msg);
    void get_started_info();

private:
    Ui::MainWindow *ui;
    Afficher *one;
};

#endif // MAINWINDOW_H
