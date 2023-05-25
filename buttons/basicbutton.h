#ifndef BASICSTYLEDBUTTON_H
#define BASICSTYLEDBUTTON_H

#include <QPushButton>

class BasicStyledButton : public QPushButton
{
    Q_OBJECT
public:
    BasicStyledButton(const QString& text, QWidget *parent = nullptr);
    BasicStyledButton(QWidget *parent = nullptr);
private:
    void setStyle();
};

#endif // BASICSTYLEDBUTTON_H
