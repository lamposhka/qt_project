#include "levelmodebutton.h"
#include <QStyle>

LevelModeButton::LevelModeButton(const QString &text, const Mode& mode,  QWidget *parent):
    QPushButton(text, parent), picked_(false), mode_(mode)
{
    connect(this, SIGNAL(clicked()), SLOT(invert()));
      setStyleSheet(
        " QPushButton {border-radius: 8px; padding: 6px;}"
        " QPushButton[picked=true] { background-color: green;}"
        " QPushButton[picked=false] { background-color: #222;}"
        " QPushButton {font-family: \"Farfetch Basis\",\"Helvetica Neue\",Arial,sans-serif; font-weight: 700; color: #fff;}"
                  );
    connect(this, SIGNAL(picked(bool)), this, SLOT(onPicked()));
    effect = new QSoundEffect(this);
    effect->setSource(QUrl("qrc:/music/playlist/button-50.wav"));
    connect(this, SIGNAL(clicked()), effect, SLOT(play()));
}

void LevelModeButton::pick(bool isPicked)
{
    if (picked_ == isPicked) {
        return;
    }
    picked_ = isPicked;
    style()->unpolish(this);
    style()->polish(this);

    emit picked(picked_);
}

void LevelModeButton::unpick()
{
    pick(false);
}

void LevelModeButton::onPicked()
{
    if(picked()) {
        emit picked_true();
    }
}

Mode LevelModeButton::mode()
{
    return mode_;
}

bool LevelModeButton::picked()
{
    return picked_;
}

void LevelModeButton::invert()
{
    pick(!picked_);
}

