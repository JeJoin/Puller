/********************************************************************************
** Form generated from reading UI file 'Puller.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PULLER_H
#define UI_PULLER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PullerClass
{
public:

    void setupUi(QWidget *PullerClass)
    {
        if (PullerClass->objectName().isEmpty())
            PullerClass->setObjectName(QStringLiteral("PullerClass"));
        PullerClass->resize(600, 400);

        retranslateUi(PullerClass);

        QMetaObject::connectSlotsByName(PullerClass);
    } // setupUi

    void retranslateUi(QWidget *PullerClass)
    {
        PullerClass->setWindowTitle(QApplication::translate("PullerClass", "Puller", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class PullerClass: public Ui_PullerClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PULLER_H
