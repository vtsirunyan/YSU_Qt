#ifndef PUSHBUTTON_H
#define PUSHBUTTON_H
#include <QWidget>
#include <QMessageBox>
#include <QTextEdit>
#include <QPushButton>


class PushButton : public QPushButton
{
    Q_OBJECT
public:
     PushButton(QPushButton *Button = nullptr);

public slots:
    void when_Cancel_clicked(QTextEdit *textEdit);
    void when_OK_clicked();
signals:
    void okClicked();
    void cancelCliked();

private:
    QPushButton *button;
};
#endif // PUSHBUTTON_H
