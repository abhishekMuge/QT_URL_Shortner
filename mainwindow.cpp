#include "mainwindow.h"
#include "ui_mainwindow.h"

#define VALUE_ZERO          0
#define VALUE_ONE           1
#define FAILURE             1
#define SUCCESS             0
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("URLShortener");
    ui->URLTableWidget->setColumnCount(3);
    ui->URLTableWidget->setHorizontalHeaderLabels({"Original URL", "Shorten URL", "Custom Alise"});
    ui->URLTableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->URLTableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->URLTableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->URLTableWidget->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel); // Enable vertical scrolling
    ui->URLTableWidget->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(ui->btnGenerate, &QPushButton::clicked, this, &MainWindow::btn_GenerateURL);
    connect(ui->URLTableWidget, &QTableWidget::cellClicked, this, &MainWindow::openUrl);
    connect(ui->URLTableWidget, &QTableWidget::customContextMenuRequested, this, MainWindow::showContextMenu);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::btn_GenerateURL()
{
    QString sUrlInput = ui->edit_UrlInput->text();
    QString sCustomInput = ui->edit_CustomInput->text();

    if(sUrlInput.length() < VALUE_ONE)
    {
        QMessageBox::critical(nullptr, "Error", "Something went wrong!");
        return;
    }
    else
    {
        bool isValidUrl = bFormAndValidateUrl(sUrlInput);
        if(isValidUrl)
        {
            QString lsShortenUrl = ShortenURL(sUrlInput, sCustomInput);
            qDebug() << lsShortenUrl;
            if (!lsShortenUrl.isEmpty()) {
                int rowCount = ui->URLTableWidget->rowCount();
                ui->URLTableWidget->insertRow(rowCount);

                ui->URLTableWidget->setItem(rowCount, 0, new QTableWidgetItem(sUrlInput));
                ui->URLTableWidget->setItem(rowCount, 1, new QTableWidgetItem(lsShortenUrl));
                ui->URLTableWidget->setItem(rowCount, 2, new QTableWidgetItem(sCustomInput.isEmpty() ? "N/A" : sCustomInput));
            }
            ui->edit_UrlInput->clear();
            ui->edit_CustomInput->clear();
        }
        else
        {
            QMessageBox::critical(nullptr, "Error", "URL is not valid. Try Again");
            qDebug() << "btn_GenerateURL():: URL is not valid.";
        }
    }
}

bool MainWindow::bFormAndValidateUrl(const QString &sUrlInput)
{
    QRegularExpression regex(R"(^(https?|ftp)://[^\s/$.?#].[^\s]*$)");
    return regex.match(sUrlInput).hasMatch();
}
QString MainWindow::GenerateRandomKey(int nLength)
{
    QString key = "";
    for(int idx = 0; idx < nLength; idx++)
    {
        key.append(chars.at(QRandomGenerator::global()->bounded(chars.length())));
    }
    return key;
}
QString MainWindow::ShortenURL(const QString &sOriginalURL, const QString &sCustomAlise)
{
    QString lsShortenKey = sCustomAlise;
    if(!lsShortenKey.isEmpty())
    {
        if(urlMap.contains(lsShortenKey))
        {
            qDebug() << "Custom Alise already exists";
        }
    }
    else
    {
        do
        {
            lsShortenKey = GenerateRandomKey();
        }while(urlMap.contains(lsShortenKey));
    }
    urlMap[lsShortenKey] = sOriginalURL;
    if(!sCustomAlise.isEmpty())
    {
        aliseMap[sOriginalURL] = sCustomAlise;
    }
    return "https://short.ly/" + lsShortenKey;
}

void MainWindow::openUrl(int row, int column)
{
    Q_UNUSED(column);
    QString originalUrl = ui->URLTableWidget->item(row, 0)->text();
    if (!originalUrl.isEmpty())
    {
        QDesktopServices::openUrl(QUrl(originalUrl));
    }
}
void MainWindow::showContextMenu(const QPoint &pos)
{
    QModelIndex index = ui->URLTableWidget->indexAt(pos);
    if(!index.isValid())return; // Allow only to click on shorten url

    QMenu contextMenu;
    QAction copyAction("Copy Shortened URL", this);
    QAction deleteAction("Delete URL", this);

    contextMenu.addAction(&copyAction);
    connect(&copyAction, &QAction::triggered, [=]() {
        QString shortUrl = ui->URLTableWidget->item(index.row(), 1)->text();
        QApplication::clipboard()->setText(shortUrl);
        qDebug() << "Copied to clipboard via context menu:" << shortUrl;
    });
    contextMenu.addAction(&deleteAction);
    connect(&deleteAction, &QAction::triggered, [=]() {
        QString shortUrl = ui->URLTableWidget->item(index.row(), 1)->text();
        QString keyToRemove;
        for (auto it = getUrlMap().begin(); it != getUrlMap().end(); ++it) {
            if ("https://short.ly/" + it.key() == shortUrl) {
                keyToRemove = it.key();
                break;
            }
        }

        if (!keyToRemove.isEmpty()) {
            removeUrl(keyToRemove);
            qDebug() << "Removed from hash: " << keyToRemove;
        }
        ui->URLTableWidget->removeRow(index.row());
        qDebug() << "Deleted row:" << index.row();
    });
    contextMenu.exec(ui->URLTableWidget->viewport()->mapToGlobal(pos)); // Show menu at cursor position
}
void MainWindow::removeUrl(const QString &key) {
    urlMap.remove(key);
}
QMap<QString, QString> MainWindow::getUrlMap() const {
    return urlMap;
}












