/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *lblUrlInput;
    QLineEdit *edit_UrlInput;
    QLineEdit *edit_CustomInput;
    QLabel *lblCustomInput;
    QPushButton *btnGenerate;
    QFrame *line;
    QFrame *line_3;
    QFrame *line_2;
    QTableWidget *URLTableWidget;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(466, 450);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName("verticalLayout");
        formLayout = new QFormLayout();
        formLayout->setObjectName("formLayout");
        lblUrlInput = new QLabel(centralwidget);
        lblUrlInput->setObjectName("lblUrlInput");

        formLayout->setWidget(0, QFormLayout::SpanningRole, lblUrlInput);

        edit_UrlInput = new QLineEdit(centralwidget);
        edit_UrlInput->setObjectName("edit_UrlInput");

        formLayout->setWidget(1, QFormLayout::SpanningRole, edit_UrlInput);

        edit_CustomInput = new QLineEdit(centralwidget);
        edit_CustomInput->setObjectName("edit_CustomInput");

        formLayout->setWidget(3, QFormLayout::SpanningRole, edit_CustomInput);

        lblCustomInput = new QLabel(centralwidget);
        lblCustomInput->setObjectName("lblCustomInput");

        formLayout->setWidget(2, QFormLayout::SpanningRole, lblCustomInput);

        btnGenerate = new QPushButton(centralwidget);
        btnGenerate->setObjectName("btnGenerate");

        formLayout->setWidget(5, QFormLayout::SpanningRole, btnGenerate);

        line = new QFrame(centralwidget);
        line->setObjectName("line");
        line->setFrameShape(QFrame::Shape::HLine);
        line->setFrameShadow(QFrame::Shadow::Sunken);

        formLayout->setWidget(4, QFormLayout::LabelRole, line);


        verticalLayout->addLayout(formLayout);

        line_3 = new QFrame(centralwidget);
        line_3->setObjectName("line_3");
        line_3->setFrameShape(QFrame::Shape::HLine);
        line_3->setFrameShadow(QFrame::Shadow::Sunken);

        verticalLayout->addWidget(line_3);

        line_2 = new QFrame(centralwidget);
        line_2->setObjectName("line_2");
        line_2->setFrameShape(QFrame::Shape::HLine);
        line_2->setFrameShadow(QFrame::Shadow::Sunken);

        verticalLayout->addWidget(line_2);

        URLTableWidget = new QTableWidget(centralwidget);
        URLTableWidget->setObjectName("URLTableWidget");

        verticalLayout->addWidget(URLTableWidget);

        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);
        QWidget::setTabOrder(edit_UrlInput, edit_CustomInput);
        QWidget::setTabOrder(edit_CustomInput, btnGenerate);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        lblUrlInput->setText(QCoreApplication::translate("MainWindow", "URL Input", nullptr));
        lblCustomInput->setText(QCoreApplication::translate("MainWindow", "Custom Input", nullptr));
        btnGenerate->setText(QCoreApplication::translate("MainWindow", "Generate", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
