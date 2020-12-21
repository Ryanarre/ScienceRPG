#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>

#include "DatabaseManager.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    void handleButton(size_t index);

    void generate();

private slots:
    void handleFButton();
    void handleSButton();
    void handleTButton();
    void handleFoButton();

private:
    Ui::MainWindow *ui;

    size_t m_index;
    std::vector<QPushButton*> m_pButtons;
    DatabaseManager m_databaseManager;
};

#endif // MAINWINDOW_H
