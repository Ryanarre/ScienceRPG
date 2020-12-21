#include "MainWindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{   
    ui->setupUi(this);

    connect(ui->fAnsBtn, SIGNAL (released()), this, SLOT (handleFButton()));
    connect(ui->sAnsBtn, SIGNAL (released()), this, SLOT (handleSButton()));
    connect(ui->tAnsBtn, SIGNAL (released()), this, SLOT (handleTButton()));
    connect(ui->foAnsBtn, SIGNAL (released()), this, SLOT (handleFoButton()));

    m_pButtons = {ui->fAnsBtn, ui->sAnsBtn, ui->tAnsBtn, ui->foAnsBtn};
    generate();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::handleButton(size_t index)
{
     if (index == m_index)
     {
        int enemyHp = ui->enemyHP->value() - 10;

        if (enemyHp > 0)
            ui->enemyHP->setValue(ui->enemyHP->value() - 10);
        else
        {
            ui->enemyHP->setValue(100);
            ui->heroEXP->setValue(ui->heroEXP->value() + 10);
        }
     }
    else
        ui->heroHP->setValue(ui->heroHP->value() - 10);

    generate();
}

void MainWindow::generate()
{
    m_index = rand() % 4;

    for (size_t i = 0; i < 4; ++i)
    {
        if (i == m_index)
            m_pButtons[i]->setText("True");
        else
            m_pButtons[i]->setText("False");
    }
}

void MainWindow::handleFButton()
{
    handleButton(0);
}

void MainWindow::handleSButton()
{
    handleButton(1);
}

void MainWindow::handleTButton()
{
    handleButton(2);
}

void MainWindow::handleFoButton()
{
    handleButton(3);
}
