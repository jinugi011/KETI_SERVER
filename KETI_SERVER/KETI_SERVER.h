#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_KETI_SERVER.h"
#include "use_opencv.h"

class KETI_SERVER : public QMainWindow
{
    Q_OBJECT

public:
    KETI_SERVER(QWidget *parent = Q_NULLPTR);

	void InitMain();

	void ExitButtonClicked();

private:
    Ui::KETI_SERVERClass ui;
};
