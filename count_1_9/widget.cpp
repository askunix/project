#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    label_ans = new QLabel("0", this);
    select[0] = new QRadioButton("+", this);
    select[1] = new QRadioButton("-", this);
    select[2] = new QRadioButton("*", this);
    select[3] = new QRadioButton("/", this);
    num1 = new QLineEdit(this);
    num2 = new QLineEdit(this);
    button_calc = new QPushButton("=", this);

    layout = new QHBoxLayout;
    select_layout = new QVBoxLayout;
    select_layout->addWidget(select[0]);
    select_layout->addWidget(select[1]);
    select_layout->addWidget(select[2]);
    select_layout->addWidget(select[3]);

    layout->addWidget(num1);
    layout->addLayout(select_layout);
    layout->addWidget(num2);
    layout->addWidget(button_calc);
    layout->addWidget(label_ans);
    this->setLayout(layout);

    QObject::connect(button_calc, SIGNAL(clicked(bool)),this, SLOT(calc()));

}

Widget::~Widget()
{

}

void Widget::calc()
{
    double a = num1->text().toDouble();
    double b = num2->text().toDouble();

    if(select[0]->isChecked()){
        label_ans->setText(QString::number(a + b));

    }
    else if(select[1]->isChecked()){
        label_ans->setText(QString::number(a-b));
    }
    else if(select[2]->isChecked()){
        label_ans->setText(QString::number(a*b));
    }
    else if(select[3]->isChecked()){
        if(b == 0)
             label_ans->setText("Zero Error!!!");
        else
            label_ans->setText(QString::number(a / b) );
    }
    else{
        label_ans->setText("please choose a calc method");
    }

}

