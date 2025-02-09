#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>
#include <QSqlError>
//#include <QLabel>



QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void populateCategories();
    void populateOrigins();

private slots:
    void on_pushButton_View_clicked();
    void on_comboBox_cate_currentIndexChanged(const QString& category);
    void on_comboBox_org_currentIndexChanged(const QString& origin);
    void loadDishes(const QString& query, bool includeHeaders);


    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    QSqlDatabase DB_Connection;
};
#endif // MAINWINDOW_H
