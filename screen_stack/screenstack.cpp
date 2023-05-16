#include "screenstack.h"

ScreenStack::ScreenStack(QWidget *parent) :
    QWidget(parent), layout_(this)
{
    setLayout(&layout_);
    layout_.setMargin(0);
}

void ScreenStack::push(QWidget *widget)
{
    if (!widgets_.empty()) {
        widgets_.front()->hide();
    }
    widget->show();
    layout_.addWidget(widget);
    widgets_.push_front(widget);
}

void ScreenStack::pop()
{
    if (!widgets_.length()) {
        return;
    }
    widgets_.front()->hide();
    widgets_.pop_front();
    if (widgets_.length()) {
        widgets_.front()->show();
    }
}

int ScreenStack::lenghth()
{
    return widgets_.length();
}

QWidget &ScreenStack::front()
{
    return *widgets_.front();
}
