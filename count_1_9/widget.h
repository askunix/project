#ifndef WIDGET_H
#define WIDGET_H

#include<QWidget>
#include<QLabel>
#include<QLineEdit>
#include<QPushButton>
#include<QBoxLayout>
#include<QRadioButton>
#include<QVBoxLayout>

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private slots:
    void calc();

private:
    QLabel *label_ans;
    QLineEdit *num1, *num2;
    QPushButton *button_calc;
    QHBoxLayout *layout;
    QRadioButton *select[4];
    QVBoxLayout *select_layout;

};

#endif // WIDGET_H
