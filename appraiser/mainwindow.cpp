#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QWidget * wdg = new QWidget(this);
    QGridLayout *layout = new QGridLayout(wdg);

    train_button = new QPushButton(wdg);
    train_button->setText("something");
    connect(train_button, &QPushButton::released, this, &MainWindow::handleButton);

    add1 = new QLineEdit(wdg);
    add1->setPlaceholderText("add 1");;
    add2 = new QLineEdit(wdg);
    add2->setPlaceholderText("add 2");

    lable_sum = new QLabel(wdg);
    lable_sum->setText("sum result");

    layout->addWidget(train_button, 0, 0);
    layout->addWidget(add1, 0, 1);
    layout->addWidget(add2, 0, 2);
    layout->addWidget(lable_sum, 1, 0);


    setCentralWidget(wdg);
    wdg->setLayout(layout);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::handleButton()
{
    train_button->setText("Example");
    // resize button
    //train_button->resize(100,100);

    int a1 = add1->text().toInt();
    int a2 = add2->text().toInt();

    lable_sum->setText(std::to_string(a1+a2).c_str());
}

