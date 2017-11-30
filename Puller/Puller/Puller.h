#pragma once

#include <QtWidgets/QWidget>
#include "ui_Puller.h"

class Puller : public QWidget
{
    Q_OBJECT

public:
    Puller(QWidget *parent = Q_NULLPTR);

private:
    Ui::PullerClass ui;
};
