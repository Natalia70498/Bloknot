#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialog.h"

#include <QFileDialog>
#include <QFile>
#include <QMessageBox>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->comboBox_2->setItemData(0, QBrush(Qt::black), Qt::TextColorRole);
    ui->comboBox_2->setItemData(1, QBrush(Qt::red), Qt::TextColorRole);
    ui->comboBox_2->setItemData(2, QBrush(Qt::blue), Qt::TextColorRole);
    ui->comboBox_2->setItemData(3, QBrush(Qt::green), Qt::TextColorRole);
    ui->comboBox_2->setItemData(4, QBrush(Qt::yellow), Qt::TextColorRole);
    ui->comboBox_2->setItemData(5, QBrush(Qt::magenta), Qt::TextColorRole);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_spinBox_valueChanged(int arg1)
{
    ui->textEdit->selectAll();
    ui->textEdit->setFontPointSize(arg1);
    QTextCursor textCursor = ui->textEdit->textCursor();
    textCursor.clearSelection();
    ui->textEdit->setTextCursor(textCursor);
}

void MainWindow::on_action_2_triggered()
{
    QString filename = QFileDialog::getOpenFileName();
    if(filename.isEmpty())
        return ;

    QFile file(filename);
    if(!file.open(QIODevice::ReadOnly))
        return ;

    ui->textEdit->setText(file.readAll());
    file.close();
}

void MainWindow::on_action_triggered()
{
    ui->textEdit->clear();
}

void MainWindow::on_action_6_triggered()
{
    ui->textEdit->clear();
}

void MainWindow::on_action_3_triggered()
{
    QString filename = QFileDialog::getSaveFileName();
    qDebug() << filename;
    if(filename.isEmpty())
        return ;

    QFile file(filename);
    if(!file.open(QIODevice::WriteOnly))
        return ;

    QByteArray arr;
    arr += ui->textEdit->document()->toPlainText();
    file.write(arr);
    file.close();
}

void MainWindow::on_comboBox_2_currentIndexChanged(int index)
{
    ui->textEdit->selectAll();
    QBrush brush = ui->comboBox_2->itemData(index, Qt::TextColorRole).value<QBrush>();
    ui->textEdit->setTextColor(brush.color());
    QTextCursor textCursor = ui->textEdit->textCursor();
    textCursor.clearSelection();
    ui->textEdit->setTextCursor(textCursor);
}

void MainWindow::on_comboBox_currentIndexChanged(int index)
{
    ui->textEdit->selectAll();
    switch(index) {
    case 0:
        ui->textEdit->setFontItalic(false);
        ui->textEdit->setFontUnderline(false);
        ui->textEdit->setFontWeight(QFont::Normal);
        break;
    case 1:
        ui->textEdit->setFontItalic(ui->textEdit->fontItalic());
        break;
    case 2:
        ui->textEdit->setFontUnderline(!ui->textEdit->fontUnderline());
        break;
    case 3:
        ui->textEdit->setFontWeight(QFont::Bold);
        break;
    default:
        break;
    }
    QTextCursor textCursor = ui->textEdit->textCursor();
    textCursor.clearSelection();
    ui->textEdit->setTextCursor(textCursor);
}

void MainWindow::on_action_8_triggered()
{
    Dialog dlg(this);
    dlg.exec();
}

void MainWindow::on_action_7_triggered()
{
    QString text = "Блокнот версия 1.2017";
    QMessageBox::about(this, "О программе", text);
}
