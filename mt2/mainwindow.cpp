#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QVBoxLayout>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    qDebug() << QSqlDatabase::drivers();

    DB_Connection = QSqlDatabase::addDatabase("QMYSQL");
    DB_Connection.setHostName("127.0.0.1");
    DB_Connection.setPort(3306);
    DB_Connection.setUserName("root");
    DB_Connection.setPassword("root");
    DB_Connection.setDatabaseName("test2");
    if (DB_Connection.open())
    {
        qDebug() << "Database is connected";
    }
    else
    {
        qDebug() << "Database is not connected";
    }

    // Create a QVBoxLayout for the main window layout
    QVBoxLayout* mainLayout = new QVBoxLayout(ui->centralwidget);


    // Create a QHBoxLayout for the table widget
    QHBoxLayout* tableLayout = new QHBoxLayout();
    tableLayout->addWidget(ui->tableWidget);
    tableLayout->setContentsMargins(0, 0, 0, 0);
    tableLayout->setSpacing(0);



    // Add the table layout to the main layout
    mainLayout->addLayout(tableLayout);

    // Set the main layout for the central widget
    ui->centralwidget->setLayout(mainLayout);

    ui->tableWidget->setVisible(false);



    ui->tableWidget->setVisible(false);



    populateCategories();
    ui->comboBox_cate->setCurrentIndex(-1);
    connect(ui->comboBox_cate, SIGNAL(currentTextChanged(const QString&)), this, SLOT(on_comboBox_cate_currentIndexChanged(const QString&)));

    populateOrigins();
    ui->comboBox_org->setCurrentIndex(-1);
    connect(ui->comboBox_org, SIGNAL(currentTextChanged(const QString&)), this, SLOT(on_comboBox_org_currentIndexChanged(const QString&)));
}




QString FormatMoney(int x);




MainWindow::~MainWindow()
{
    delete ui;
}




void MainWindow::on_comboBox_cate_currentIndexChanged(const QString& category)
{

    if (category.isEmpty()) {
        // Clear the table when no category is selected
        ui->tableWidget->clearContents();
        ui->tableWidget->setRowCount(0);
        ui->tableWidget->setVisible(false);
    } else {
        ui->comboBox_org->setCurrentIndex(-1);
        QString sqlQuery = "SELECT d.dish_id, d.dish_name, d.price, "
                           "c.category_name AS category, "
                           "GROUP_CONCAT(DISTINCT o.origin_name ORDER BY o.origin_name SEPARATOR ', ') AS origins "
                           "FROM dishes d "
                           "JOIN categories c ON d.category_id = c.category_id "
                           "JOIN dish_origins do ON d.dish_id = do.dish_id "
                           "JOIN origins o ON do.origin_id = o.origin_id "
                           "WHERE c.category_name = '" + category + "' "
                                        "   AND (d.unavailable_start_time IS NULL "
                                        "   OR NOW() < d.unavailable_start_time "
                                        "   OR NOW() > d.unavailable_end_time) "
                                        "GROUP BY d.dish_id, d.dish_name, d.price, c.category_name, c.category_id "
                                        "ORDER BY c.category_id";

        loadDishes(sqlQuery, false);
    }
}

void MainWindow::on_pushButton_View_clicked()
{
    ui->comboBox_cate->setCurrentIndex(-1);
    ui->comboBox_org->setCurrentIndex(-1);
    QString sqlQuery = "SELECT d.dish_id, d.dish_name, d.price, "
                       "c.category_name AS category, "
                       "GROUP_CONCAT(DISTINCT o.origin_name ORDER BY o.origin_name SEPARATOR ', ') AS origins "
                       "FROM dishes d "
                       "JOIN categories c ON d.category_id = c.category_id "
                       "JOIN dish_origins do ON d.dish_id = do.dish_id "
                       "JOIN origins o ON do.origin_id = o.origin_id "
                       "WHERE (d.unavailable_start_time IS NULL "
                       "   OR NOW() < d.unavailable_start_time "
                       "   OR NOW() > d.unavailable_end_time) "
                       "GROUP BY d.dish_id, d.dish_name, d.price, c.category_name, c.category_id "
                       "ORDER BY c.category_id";

    loadDishes(sqlQuery, true);
}





void MainWindow::populateCategories() {
    QSqlQuery query(DB_Connection);

    if (query.exec("SELECT category_id, category_name FROM categories")) {
        QStringList categories;
        while (query.next()) {
            QString category_name = query.value("category_name").toString();
            categories << category_name;
        }
        ui->comboBox_cate->addItems(categories);
        ui->comboBox_cate->setFixedWidth(200);  // Set the desired width
        ui->comboBox_cate->setFixedHeight(30);  // Set the desired height

    } else {
        qDebug() << "Error executing the query. Error message:" << query.lastError().text();
    }
}


void MainWindow::loadDishes(const QString& query, bool includeHeaders)
{
    //DB_Connection.open();

    QSqlQuery sqlQuery(DB_Connection);

    if (sqlQuery.exec(query)) {
        // Clear the table before populating new data
        ui->tableWidget->clearContents();
        ui->tableWidget->setRowCount(0);

        QString currentCategory;
        int rowCount = 0;

        while (sqlQuery.next()) {
            QString dishName = sqlQuery.value("dish_name").toString();
            int price = sqlQuery.value("price").toInt();
            QString category = sqlQuery.value("category").toString();
            QString origins = sqlQuery.value("origins").toString();

            // Print category header
            if (includeHeaders && currentCategory != category) {
                // Add a new row for the category header
                ui->tableWidget->insertRow(rowCount);
                QTableWidgetItem* categoryHeader = new QTableWidgetItem(category);
                categoryHeader->setTextAlignment(Qt::AlignCenter);
                ui->tableWidget->setItem(rowCount, 0, categoryHeader);

                currentCategory = category;
                rowCount++;
            }

            // Populate the data rows in the table
            ui->tableWidget->insertRow(rowCount);
            ui->tableWidget->setItem(rowCount, 0, new QTableWidgetItem(dishName));
            ui->tableWidget->setItem(rowCount, 1, new QTableWidgetItem(FormatMoney(price)));
            ui->tableWidget->setItem(rowCount, 2, new QTableWidgetItem(origins));

            rowCount++;
        }

        // Make table cells read-only
        for (int row = 0; row < ui->tableWidget->rowCount(); row++) {
            for (int column = 0; column < ui->tableWidget->columnCount(); column++) {
                QTableWidgetItem* item = ui->tableWidget->item(row, column);
                if (item) {
                    item->setFlags(item->flags() & ~Qt::ItemIsEditable);
                }
            }
        }

        ui->tableWidget->setVisible(true);

        // Disable numbering column
        ui->tableWidget->verticalHeader()->setVisible(false);

        // Set the size of the table widget
        ui->tableWidget->setFixedSize(1100, 350);

        // Set the size of the columns
        ui->tableWidget->setColumnWidth(0, 250);
        ui->tableWidget->setColumnWidth(1, 200);
        ui->tableWidget->setColumnWidth(2, 600);
    } else {
        qDebug() << "Error executing the query. Error message:" << sqlQuery.lastError().text();
    }

    //DB_Connection.close();
}



void MainWindow::populateOrigins() {
    QSqlQuery query(DB_Connection);

    if (query.exec("SELECT origin_id, origin_name FROM origins")) {
        QStringList origins;
        while (query.next()) {
            QString origin_name = query.value("origin_name").toString();
            origins << origin_name;
        }
        ui->comboBox_org->addItems(origins);
        ui->comboBox_org->setFixedWidth(200);  // Set the desired width
        ui->comboBox_org->setFixedHeight(30);  // Set the desired height

    } else {
        qDebug() << "Error executing the query. Error message:" << query.lastError().text();
    }
}




void MainWindow::on_comboBox_org_currentIndexChanged(const QString& origin)
{
    if (origin.isEmpty()) {
        // Clear the table when no origin is selected
        ui->tableWidget->clearContents();
        ui->tableWidget->setRowCount(0);
        ui->tableWidget->setVisible(false);
        //categoryLabel->show(); // Show the label when no category is selected
    } else {
        ui->comboBox_cate->setCurrentIndex(-1);
        QString sqlQuery = "SELECT d.dish_id, d.dish_name, d.price, "
                           "c.category_name AS category, "
                           "GROUP_CONCAT(DISTINCT o.origin_name ORDER BY o.origin_name SEPARATOR ', ') AS origins "
                           " FROM dishes d"
                           " JOIN categories c ON d.category_id = c.category_id"
                           " JOIN dish_origins do ON d.dish_id = do.dish_id"
                           " JOIN origins o ON do.origin_id = o.origin_id"
                           " JOIN ("
                           "    SELECT DISTINCT do.dish_id"
                           "    FROM dish_origins do"
                           "    JOIN origins o ON do.origin_id = o.origin_id"
                           "    WHERE o.origin_name = '" + origin + "' "
                           " ) AS subquery ON d.dish_id = subquery.dish_id"
                           " GROUP BY d.dish_id, d.dish_name, d.price, c.category_name";

        loadDishes(sqlQuery, true);
    }
}



QString FormatMoney(int x)
{
    QString result;
    int fthreeDigit;
    QVector<int> res;

    if (x > 1000) {
        while (x != 0) {
            fthreeDigit = x % 1000;
            res.push_back(fthreeDigit);
            x = x / 1000;
        }

        std::reverse(res.begin(), res.end());
        result += QString::number(res[0]) + ".";
        for (int i = 1; i < res.size() - 1; ++i) {
            if (res[i] == 0)
                result += "000.";
            else if (res[i] < 100 && res[i] > 9)
                result += "0" + QString::number(res[i]) + ".";
            else if (res[i] < 10 && res[i] > 0)
                result += "00" + QString::number(res[i]) + ".";
            else
                result += QString::number(res[i]) + ".";
        }

        if (res[res.size() - 1] == 0)
            result += "000 VND";
        else if (res[res.size() - 1] < 100 && res[res.size() - 1] > 9)
            result += "0" + QString::number(res[res.size() - 1]) + " VND";
        else if (res[res.size() - 1] < 10 && res[res.size() - 1] > 0)
            result += "00" + QString::number(res[res.size() - 1]) + " VND";
        else
            result += QString::number(res[res.size() - 1]) + " VND";
    } else {
        result += QString::number(x) + " VND";
    }

    return result;
}

void MainWindow::on_pushButton_clicked()
{
    QApplication::quit();
}

