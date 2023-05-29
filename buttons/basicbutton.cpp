#include "basicbutton.h"
#include <QSoundEffect>

BasicStyledButton::BasicStyledButton(const QString &text, QWidget *parent):
    QPushButton(text, parent)
{
    setStyle();
}

BasicStyledButton::BasicStyledButton(QWidget *parent): QPushButton(parent)
{
    setStyle();
}

void BasicStyledButton::setStyle()
{
    QString style = "QPushButton {background-color: #222;"
            "border-radius: 4px;"
            "border-style: none;"
            "color: #fff;"
            "font-family: \"Farfetch Basis\",\"Helvetica Neue\",Arial,sans-serif;"
            "font-size: 30px;"
            "font-weight: 700;"
            "line-height: 1.5;"
            "text-align: center;"
            "text-transform: none;"
            "width: 100%;}"
            "QPushButton:hover{"
            "background-color: green;}";
    this->setStyleSheet(style);
    setFixedSize(300, 100);
    effect = new QSoundEffect(this);
    effect->setSource(QUrl("qrc:/music/playlist/button-46.wav"));
    connect(this, SIGNAL(clicked()), effect, SLOT(play()));
}
