#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QRegularExpression>
#include <QDebug>
#include <QRandomGenerator>
#include <QDesktopServices>
#include <QPoint>
#include <QModelIndex>
#include <QMenu>
#include <QAction>
#include <QClipboard>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QMap<QString, QString> urlMap;  // Maps short URLs -> original URLs
    QMap<QString, QString> aliseMap; // Maps original URL -> custom alias
    const QString chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
private:
    bool bFormAndValidateUrl(const QString &sUrlInput);
    QString GenerateRandomKey(int nLength = 6);
    QString ShortenURL(const QString &sOriginalURL, const QString &sCustomAlise = "");
    void openUrl(int row, int column);
    void showContextMenu(const QPoint &pos);
    void removeUrl(const QString &key);
    QMap<QString, QString> getUrlMap() const;
private slots:
    void btn_GenerateURL();
};
#endif // MAINWINDOW_H
