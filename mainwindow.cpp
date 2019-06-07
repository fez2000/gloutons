#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    load_piece();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_calculer_clicked()
{
   QString val = this->ui->lineEdit->text();
   this->ui->lineEdit->setReadOnly(true);
   this->ui->calculer->setDisabled(true);
   long long somme = convertion( val.toStdString().c_str());
   long numByPiece[num_piece()];
   if(somme < 0){
       alert("NOMBRE INVALIDE LA SOMME DOIS ETRE UN ENTIER");
   }else{
       if(somme != 0){

           this->ui->somme->setText(QString((::to_str(somme)+ std::string(" ") + get_type()).c_str()));
           size_t i = num_piece();
           long piece ;
            this->ui->etatpes->clear();
           while (true ) {
                --i;
               piece = get_piece(i);
               numByPiece[i] = num_piece_of(somme,piece);
               if(numByPiece[i]!=0){
                std::string msg("Choix glouton\t");
                msg += to_str<long>(piece) + std::string(",\nnombre de piece\t") + to_str<long>(numByPiece[i]) + std::string (",\nsomme restante\t") + to_str<long long>(somme) + std::string(".\n");
                new QListWidgetItem(tr(msg.c_str()),this->ui->etatpes);
               }

               if(i == 0 ){
                   break;
               }
           }
           i = num_piece();
           size_t j = 0;

           this->ui->reste->setText(QString((::to_str(somme)+std::string(" ") + get_type()).c_str()));
           this->ui->resultats->setRowCount(i);

            this->ui->resultats->setColumnCount(2);
           this->ui->resultats->setHorizontalHeaderItem(0,new QTableWidgetItem(tr("PIECE").arg((0+1)*(0+1))));
           this->ui->resultats->setHorizontalHeaderItem(1,new QTableWidgetItem(tr("NOMBRE").arg((0+1)*(1+1))));
            this->ui->resultats->setColumnWidth(1,120);
           this->ui->resultats->setColumnWidth(0,120);

           while (j <i) {

               this->ui->resultats->setRowHeight(j,50);


               QTableWidgetItem *newItem = new QTableWidgetItem(tr(to_str<long>( get_piece(j)).c_str()).arg((j+1)*(0+1)));
               newItem->setTextAlignment(Qt::AlignCenter);
               this->ui->resultats->setItem(j, 0, newItem);
               QTableWidgetItem *newItem2 = new QTableWidgetItem(tr(to_str<long>(numByPiece[j]).c_str()).arg((j+1)*(1+1)));
               this->ui->resultats->setItem(j, 1, newItem2);
               newItem2->setTextAlignment(Qt::AlignCenter);
               j ++;
           }


       }
   }

   this->ui->lineEdit->setReadOnly(false);
   this->ui->calculer->setDisabled(false);
}

void MainWindow::on_lineEdit_editingFinished()
{

}

void MainWindow::alert(const char * msg){
    QMessageBox::warning(this, "Alerte",msg );
}
