#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->line_passwd->setEchoMode(QLineEdit::PasswordEchoOnEdit);
}

MainWindow::~MainWindow()
{
    delete ui;
}

//
void MainWindow::on_btn_quit_clicked()
{
    this->close();
}

void MainWindow::on_btn_login_clicked()
{
   QString username;
   QString passwd;

   username = ui->line_user->text();
   passwd = ui->line_passwd->text();

   if((username == "zhuyong") && (passwd == "123456"))
       qDebug() << "Login success";
   else
       qDebug() << "username and passwd does not match";


}
