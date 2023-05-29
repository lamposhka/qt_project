#ifndef BASICSTYLEDBUTTON_H
#define BASICSTYLEDBUTTON_H

#include <QPushButton>
#include <QSoundEffect>

class BasicStyledButton : public QPushButton
{
    Q_OBJECT
public:
    BasicStyledButton(const QString& text, QWidget *parent = nullptr);
    BasicStyledButton(QWidget *parent = nullptr);
private:
    void setStyle();
    QSoundEffect* effect;
};

#endif // BASICSTYLEDBUTTON_H
