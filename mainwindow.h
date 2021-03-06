#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_spinBox_valueChanged(int arg1);

    void on_action_2_triggered();

    void on_action_triggered();

    void on_action_6_triggered();

    void on_action_3_triggered();    
    void on_comboBox_2_currentIndexChanged(int index);

    void on_comboBox_currentIndexChanged(int index);

    void on_action_8_triggered();

    void on_action_7_triggered();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
