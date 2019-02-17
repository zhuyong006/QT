/********************************************************************************
** Form generated from reading UI file 'oneform.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ONEFORM_H
#define UI_ONEFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_OneForm
{
public:
    QLabel *label;
    QPushButton *btn_go2;
    QPushButton *btn_go3;

    void setupUi(QWidget *OneForm)
    {
        if (OneForm->objectName().isEmpty())
            OneForm->setObjectName(QStringLiteral("OneForm"));
        OneForm->resize(400, 300);
        label = new QLabel(OneForm);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(140, 100, 67, 17));
        btn_go2 = new QPushButton(OneForm);
        btn_go2->setObjectName(QStringLiteral("btn_go2"));
        btn_go2->setGeometry(QRect(50, 210, 89, 25));
        btn_go3 = new QPushButton(OneForm);
        btn_go3->setObjectName(QStringLiteral("btn_go3"));
        btn_go3->setGeometry(QRect(230, 210, 89, 25));

        retranslateUi(OneForm);

        QMetaObject::connectSlotsByName(OneForm);
    } // setupUi

    void retranslateUi(QWidget *OneForm)
    {
        OneForm->setWindowTitle(QApplication::translate("OneForm", "Form", Q_NULLPTR));
        label->setText(QApplication::translate("OneForm", "OneForm", Q_NULLPTR));
        btn_go2->setText(QApplication::translate("OneForm", "go2", Q_NULLPTR));
        btn_go3->setText(QApplication::translate("OneForm", "go3", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class OneForm: public Ui_OneForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ONEFORM_H
