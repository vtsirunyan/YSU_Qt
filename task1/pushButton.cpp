#include "pushButton.h"
#include <QPushButton>
#include <QTextEdit>

PushButton::PushButton(QPushButton *Button)
    : button(Button)
{ }

void PushButton::when_Cancel_clicked(QTextEdit *textEdit)
{
  textEdit->setText("You clciked Cancel button");
}

void PushButton::when_OK_clicked()
{
    results.setText("You clciked OK button");
}
