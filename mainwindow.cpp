#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Properties
    width =  ui->spinBox_width->value();
    height =  ui->spinBox_height->value();


    // Binding
    area.setBinding([&]() {
        return width.value() * height.value();
    });

    // Update width property when UI changes
    connect(ui->spinBox_width,
            &QSpinBox::valueChanged,
            this,
            [&](int value){
                width = value;
                ui->spinBox_area->setValue(area.value());

                qDebug() << "Width:" << width.value()
                         << "Height:" << height.value()
                         << "Area:" << area.value();
            });

    // Update height property when UI changes
    connect(ui->spinBox_height,
            &QSpinBox::valueChanged,
            this,
            [&](int value){
                height = value;
                ui->spinBox_area->setValue(area.value());

                qDebug() << "Width:" << width.value()
                         << "Height:" << height.value()
                         << "Area:" << area.value();
            });

    // Initial value
    ui->spinBox_area->setValue(area.value());

    qDebug()<<QT_VERSION_STR;
}

MainWindow::~MainWindow()
{
    delete ui;
}
