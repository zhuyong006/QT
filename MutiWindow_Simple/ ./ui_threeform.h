/********************************************************************************
** Form generated from reading UI file 'threeform.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_THREEFORM_H
#define UI_THREEFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ThreeForm
{
public:
    QLabel *label;
    QPushButton *btn_go1;
    QPushButton *btn_go2;

    void setupUi(QWidget *ThreeForm)
    {
        if (ThreeForm->objectName().isEmpty())
            ThreeForm->setObjectName(QStringLiteral("ThreeForm"));
        ThreeForm->resize(400, 300);
        label = new QLabel(ThreeForm);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(140, 110, 67, 17));
        btn_go1 = new QPushButton(ThreeForm);
        btn_go1->setObjectName(QStringLiteral("btn_go1"));
        btn_go1->setGeometry(QRect(50, 220, 89, 25));
        btn_go2 = new QPushButton(ThreeForm);
        btn_go2->setObjectName(QStringLiteral("btn_go2"));
        btn_go2->setGeometry(QRect(200, 220, 89, 25));

        retranslateUi(ThreeForm);

        QMetaObject::connectSlotsByName(ThreeForm);
    } // setupUi

    void retranslateUi(QWidget *ThreeForm)
    {
        ThreeForm->setWindowTitle(QApplication::translate("ThreeForm", "Form", Q_NULLPTR));
        label->setText(QApplication::translate("ThreeForm", "Three", Q_NULLPTR));
        btn_go1->setText(QApplication::translate("ThreeForm", "go1", Q_NULLPTR));
        btn_go2->setText(QApplication::translate("ThreeForm", "go2", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ThreeForm: public Ui_ThreeForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_THREEFORM_H
