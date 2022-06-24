#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_qtgeometryshapes.h"
#include<qpainter.h>

class QtGeometryShapes : public QMainWindow
{
    Q_OBJECT

public:
    QtGeometryShapes(QWidget *parent = nullptr);
    ~QtGeometryShapes();

private:
    Ui::QtGeometryShapesClass ui;
protected:
    void paintEvent(QPaintEvent*) override;
};
