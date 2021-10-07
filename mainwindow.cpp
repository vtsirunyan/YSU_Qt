#include "mainwindow.h"

#include <QTextEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QMessageBox>
#include <QEventLoop>
#include <QButtonGroup>
#include <QLabel>
#include <QObject>
#include <QMainWindow>
#include <QDebug>
mainWindow::mainWindow(QWidget* parent) : QMainWindow(parent)
{
    m_res = new QTextEdit(this);

    QPushButton* okCancel    = new QPushButton();
    QPushButton* yesNoCancel = new QPushButton();
    QPushButton* retryCancel = new QPushButton();
    QPushButton* yesNo = new QPushButton();
    QPushButton* exit  = new QPushButton();

    okCancel->setText   ("OK and Cancel");
    yesNoCancel->setText("Yes, No and Cancel");
    retryCancel->setText("Retry and Cancel");
    yesNo->setText      ("Yes and NO");

    exit->setText("Exit");

    QHBoxLayout* layout1 = new  QHBoxLayout();
    layout1->addWidget(okCancel);
    layout1->addWidget(yesNoCancel);
    QHBoxLayout* layout2 = new QHBoxLayout();
    layout2->addWidget(retryCancel);
    layout2->addWidget(yesNo);

    QLabel* label = new QLabel();
    label->setText("                           Results");

    m_res->setReadOnly(true); //read only

    QHBoxLayout* layout3 = new  QHBoxLayout();
    layout3->addWidget(exit);
    layout3->addWidget(m_res);

    QHBoxLayout* layout4 = new QHBoxLayout();
    layout4->addWidget(label);

    QVBoxLayout* layout = new QVBoxLayout();
    layout->addLayout(layout1);
    layout->addLayout(layout2);
    layout->addLayout(layout4);
    layout->addLayout(layout3);

    QWidget* widget = new QWidget(this);
    widget->setWindowTitle(QObject::tr("The MyMsg Program"));
    widget->setLayout(layout);

    QMessageBox* msgBox = new QMessageBox;
    msgBox->setText("You want OK and Cancel button");
    msgBox->setWindowTitle("OK and Cancel");
    QPushButton* Cancel  = new QPushButton();
    QPushButton* OK = new QPushButton();

    OK    ->setText("OK");
    Cancel->setText("Cancel");

    msgBox->addButton(OK,     QMessageBox::ButtonRole::AcceptRole);
    msgBox->addButton(Cancel, QMessageBox::ButtonRole::RejectRole);
    msgBox->setIcon(QMessageBox::Warning);
    msgBox->setDefaultButton(Cancel);

    QObject::connect(okCancel, SIGNAL(clicked()), msgBox, SLOT(show()));
    QObject::connect(OK, SIGNAL(clicked()), this, SLOT(onBtnClicked()));
    QObject::connect(Cancel, SIGNAL(clicked()), this, SLOT(onBtnClicked()));
    //QObject::connect(Cancel, SIGNAL(clicked()), Cancel, SLOT(when_Cancel_clicked(results)));

    setCentralWidget(widget);
    //widget.show();
}

void mainWindow::onBtnClicked()
{
    QPushButton* btn = qobject_cast<QPushButton*>(sender());
    //qDebug() << btn->text();
    if (btn->text() == "OK") {
        m_res->setText("You clicked Ok button");
    } else if (btn->text() == "Cancel") {
        m_res->setText("You clicked Cancel button");
    }
}
