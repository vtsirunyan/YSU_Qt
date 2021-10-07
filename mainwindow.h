#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>

class QTextEdit;

class mainWindow : public QMainWindow
{
   Q_OBJECT
public:
    mainWindow(QWidget* parent = nullptr);
public slots:
    void onBtnClicked();
private:
    QTextEdit* m_res;
};

#endif // MAINWINDOW_H
