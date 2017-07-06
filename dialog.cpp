#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    fillHTML();
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::fillHTML()
{
    QString html = "<font color=Red>Инструкция</font><br>"
                   "<br>";
    ui->textEdit->setHtml(html);
}
