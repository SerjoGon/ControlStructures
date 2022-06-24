#include "qtgeometryshapes.h"

QtGeometryShapes::QtGeometryShapes(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
}

QtGeometryShapes::~QtGeometryShapes()
{}
void QtGeometryShapes::paintEvent(QPaintEvent*)
{
    QPainter painter;
    painter.begin(this);
    
    //painter.drawLine(0, 0, width(), height());
    QPen pen,pen2,pen3;
    pen.setColor(Qt::red);
    pen.setStyle(Qt::DashLine);
    pen.setWidth(5);
    pen2.setColor(Qt::green);
    pen2.setStyle(Qt::DashDotLine);
    pen2.setWidth(3);
    pen3.setColor(Qt::black);
    pen3.setStyle(Qt::SolidLine);
    pen3.setWidth(4);
    QBrush brush,brush2;
    brush.setColor(Qt::yellow);
    brush.setStyle(Qt::SolidPattern);
    brush2.setColor(Qt::gray);
    brush2.setStyle(Qt::HorPattern);
    painter.setPen(pen);
    painter.setBrush(brush);
    painter.drawRect(10, 10, 200, 300);

    painter.setPen(pen2);
    painter.drawEllipse(310, 310, 200, 200);
    painter.setPen(pen3);
    painter.setBrush(brush2);
    QPolygon pol;
    pol << QPoint(100, 150) << QPoint(300, 200);
    pol << QPoint(200, 250) << QPoint(100, 300);
    painter.drawPolygon(pol);

    painter.end();
}
