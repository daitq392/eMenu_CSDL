/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton_View;
    QComboBox *comboBox_cate;
    QComboBox *comboBox_org;
    QLabel *label;
    QLabel *label_2;
    QTableWidget *tableWidget;
    QLabel *label_3;
    QLabel *label_4;
    QPushButton *pushButton;
    QLabel *label_5;
    QMenuBar *menubar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1354, 665);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        pushButton_View = new QPushButton(centralwidget);
        pushButton_View->setObjectName("pushButton_View");
        pushButton_View->setGeometry(QRect(520, 0, 191, 61));
        QPalette palette;
        QBrush brush(QColor(255, 255, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(170, 255, 255, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        pushButton_View->setPalette(palette);
        QFont font;
        font.setFamilies({QString::fromUtf8("UD Digi Kyokasho NK-B")});
        font.setPointSize(18);
        font.setBold(true);
        pushButton_View->setFont(font);
        QIcon icon;
        icon.addFile(QString::fromUtf8("../1046849.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_View->setIcon(icon);
        pushButton_View->setIconSize(QSize(60, 60));
        comboBox_cate = new QComboBox(centralwidget);
        comboBox_cate->setObjectName("comboBox_cate");
        comboBox_cate->setGeometry(QRect(240, 155, 62, 22));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("UD Digi Kyokasho N-B")});
        font1.setBold(true);
        comboBox_cate->setFont(font1);
        comboBox_org = new QComboBox(centralwidget);
        comboBox_org->setObjectName("comboBox_org");
        comboBox_org->setGeometry(QRect(900, 155, 62, 22));
        comboBox_org->setFont(font1);
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(90, 155, 141, 21));
        QPalette palette1;
        QBrush brush2(QColor(0, 0, 0, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Button, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::Button, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::Button, brush2);
        label->setPalette(palette1);
        QFont font2;
        font2.setFamilies({QString::fromUtf8("UD Digi Kyokasho N-B")});
        font2.setPointSize(12);
        font2.setBold(true);
        label->setFont(font2);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(780, 155, 121, 21));
        label_2->setFont(font2);
        tableWidget = new QTableWidget(centralwidget);
        if (tableWidget->columnCount() < 3)
            tableWidget->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setEnabled(true);
        tableWidget->setGeometry(QRect(30, 150, 781, 139));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("UD Digi Kyokasho NK-B")});
        font3.setPointSize(12);
        font3.setBold(true);
        tableWidget->setFont(font3);
        tableWidget->setStyleSheet(QString::fromUtf8("QTableView {\n"
"  background-color: white;\n"
"  border: 2px solid black;\n"
"  padding: 10px;\n"
"  gridline-color: black;\n"
"}\n"
"\n"
"QTableView::item {\n"
"  padding: 15px;\n"
"}\n"
"\n"
"QHeaderView {\n"
"  font-family: UD Digi Kyokasho NK-B;\n"
"  font-size: 16px;\n"
"color: black; \n"
"}\n"
"\n"
"\n"
""));
        tableWidget->setSizeAdjustPolicy(QAbstractScrollArea::AdjustIgnored);
        tableWidget->setAutoScroll(true);
        tableWidget->setAlternatingRowColors(false);
        tableWidget->setHorizontalScrollMode(QAbstractItemView::ScrollPerPixel);
        tableWidget->setShowGrid(true);
        tableWidget->setWordWrap(false);
        tableWidget->setCornerButtonEnabled(true);
        tableWidget->horizontalHeader()->setVisible(true);
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(260, -10, 1191, 701));
        QPalette palette2;
        label_3->setPalette(palette2);
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(530, 550, 211, 121));
        label_4->setStyleSheet(QString::fromUtf8("image: url(:/res4/29999.png);"));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(1240, 0, 21, 20));
        QPalette palette3;
        QBrush brush3(QColor(255, 0, 0, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette3.setBrush(QPalette::Active, QPalette::WindowText, brush3);
        palette3.setBrush(QPalette::Active, QPalette::Text, brush3);
        palette3.setBrush(QPalette::Active, QPalette::ButtonText, brush3);
        QBrush brush4(QColor(255, 0, 0, 128));
        brush4.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette3.setBrush(QPalette::Active, QPalette::PlaceholderText, brush4);
#endif
        palette3.setBrush(QPalette::Inactive, QPalette::WindowText, brush3);
        palette3.setBrush(QPalette::Inactive, QPalette::Text, brush3);
        palette3.setBrush(QPalette::Inactive, QPalette::ButtonText, brush3);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette3.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush4);
#endif
        palette3.setBrush(QPalette::Disabled, QPalette::WindowText, brush3);
        palette3.setBrush(QPalette::Disabled, QPalette::Text, brush3);
        palette3.setBrush(QPalette::Disabled, QPalette::ButtonText, brush3);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette3.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush4);
#endif
        pushButton->setPalette(palette3);
        pushButton->setStyleSheet(QString::fromUtf8("color: red"));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(-50, -40, 1401, 761));
        label_5->setStyleSheet(QString::fromUtf8("background-image: url(:/res4/im5.png);"));
        MainWindow->setCentralWidget(centralwidget);
        label_5->raise();
        label_3->raise();
        comboBox_org->raise();
        label_2->raise();
        tableWidget->raise();
        pushButton_View->raise();
        label_4->raise();
        pushButton->raise();
        label->raise();
        comboBox_cate->raise();
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1354, 19));
        MainWindow->setMenuBar(menubar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        pushButton_View->setText(QCoreApplication::translate("MainWindow", "View Menu ", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Choose category", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Choose origin", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "Name", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "Price", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "Origins", nullptr));
        label_3->setText(QString());
        label_4->setText(QString());
        pushButton->setText(QCoreApplication::translate("MainWindow", "X", nullptr));
        label_5->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
