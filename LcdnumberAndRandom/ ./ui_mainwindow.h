/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLabel *label;
    QWidget *widget;
    QGridLayout *gridLayout;
    QLCDNumber *lcdNumber;
    QTextEdit *textEdit;
    QHBoxLayout *horizontalLayout;
    QPushButton *btn_1;
    QPushButton *btn_2;
    QPushButton *btn_3;
    QPushButton *btn_4;
    QPushButton *btn_5;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *btn_6;
    QPushButton *btn_7;
    QPushButton *btn_8;
    QPushButton *btn_9;
    QPushButton *btn_0;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(766, 529);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(270, 380, 271, 81));
        widget = new QWidget(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(0, 0, 731, 371));
        gridLayout = new QGridLayout(widget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        lcdNumber = new QLCDNumber(widget);
        lcdNumber->setObjectName(QStringLiteral("lcdNumber"));

        gridLayout->addWidget(lcdNumber, 0, 0, 1, 1);

        textEdit = new QTextEdit(widget);
        textEdit->setObjectName(QStringLiteral("textEdit"));

        gridLayout->addWidget(textEdit, 0, 1, 3, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        btn_1 = new QPushButton(widget);
        btn_1->setObjectName(QStringLiteral("btn_1"));

        horizontalLayout->addWidget(btn_1);

        btn_2 = new QPushButton(widget);
        btn_2->setObjectName(QStringLiteral("btn_2"));

        horizontalLayout->addWidget(btn_2);

        btn_3 = new QPushButton(widget);
        btn_3->setObjectName(QStringLiteral("btn_3"));

        horizontalLayout->addWidget(btn_3);

        btn_4 = new QPushButton(widget);
        btn_4->setObjectName(QStringLiteral("btn_4"));

        horizontalLayout->addWidget(btn_4);

        btn_5 = new QPushButton(widget);
        btn_5->setObjectName(QStringLiteral("btn_5"));

        horizontalLayout->addWidget(btn_5);


        gridLayout->addLayout(horizontalLayout, 1, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        btn_6 = new QPushButton(widget);
        btn_6->setObjectName(QStringLiteral("btn_6"));

        horizontalLayout_2->addWidget(btn_6);

        btn_7 = new QPushButton(widget);
        btn_7->setObjectName(QStringLiteral("btn_7"));

        horizontalLayout_2->addWidget(btn_7);

        btn_8 = new QPushButton(widget);
        btn_8->setObjectName(QStringLiteral("btn_8"));

        horizontalLayout_2->addWidget(btn_8);

        btn_9 = new QPushButton(widget);
        btn_9->setObjectName(QStringLiteral("btn_9"));

        horizontalLayout_2->addWidget(btn_9);

        btn_0 = new QPushButton(widget);
        btn_0->setObjectName(QStringLiteral("btn_0"));

        horizontalLayout_2->addWidget(btn_0);


        gridLayout->addLayout(horizontalLayout_2, 2, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 766, 28));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "\343\200\200\343\200\200\343\200\200\343\200\200\347\214\234\351\232\217\346\234\272\346\225\260\346\270\270\346\210\217", Q_NULLPTR));
        btn_1->setText(QApplication::translate("MainWindow", "1", Q_NULLPTR));
        btn_2->setText(QApplication::translate("MainWindow", "2", Q_NULLPTR));
        btn_3->setText(QApplication::translate("MainWindow", "3", Q_NULLPTR));
        btn_4->setText(QApplication::translate("MainWindow", "4", Q_NULLPTR));
        btn_5->setText(QApplication::translate("MainWindow", "5", Q_NULLPTR));
        btn_6->setText(QApplication::translate("MainWindow", "6", Q_NULLPTR));
        btn_7->setText(QApplication::translate("MainWindow", "7", Q_NULLPTR));
        btn_8->setText(QApplication::translate("MainWindow", "8", Q_NULLPTR));
        btn_9->setText(QApplication::translate("MainWindow", "9", Q_NULLPTR));
        btn_0->setText(QApplication::translate("MainWindow", "0", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
