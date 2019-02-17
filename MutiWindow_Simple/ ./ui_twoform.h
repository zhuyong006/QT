/********************************************************************************
** Form generated from reading UI file 'twoform.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TWOFORM_H
#define UI_TWOFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TwoForm
{
public:
    QLabel *label;
    QPushButton *btn_go1;
    QPushButton *btn_go3;

    void setupUi(QWidget *TwoForm)
    {
        if (TwoForm->objectName().isEmpty())
            TwoForm->setObjectName(QStringLiteral("TwoForm"));
        TwoForm->resize(400, 300);
        label = new QLabel(TwoForm);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(150, 90, 67, 17));
        btn_go1 = new QPushButton(TwoForm);
        btn_go1->setObjectName(QStringLiteral("btn_go1"));
        btn_go1->setGeometry(QRect(50, 210, 89, 25));
        btn_go3 = new QPushButton(TwoForm);
        btn_go3->setObjectName(QStringLiteral("btn_go3"));
        btn_go3->setGeometry(QRect(250, 210, 89, 25));

        retranslateUi(TwoForm);

        QMetaObject::connectSlotsByName(TwoForm);
    } // setupUi

    void retranslateUi(QWidget *TwoForm)
    {
        TwoForm->setWindowTitle(QApplication::translate("TwoForm", "Form", Q_NULLPTR));
        label->setText(QApplication::translate("TwoForm", "Two", Q_NULLPTR));
        btn_go1->setText(QApplication::translate("TwoForm", "go1", Q_NULLPTR));
        btn_go3->setText(QApplication::translate("TwoForm", "go3", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class TwoForm: public Ui_TwoForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TWOFORM_H
