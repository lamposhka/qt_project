#ifndef LEVELWIDGET_H
#define LEVELWIDGET_H

#include <QWidget>
#include "mode.h"
#include "buttons/levelmodebutton.h"

class LevelWidget : public QWidget
{
    Q_OBJECT
public:
    explicit LevelWidget(QWidget *parent = nullptr);
    Mode getMode();
public slots:
    void onPick();
signals:
    void pickedLevel();
private:
    LevelModeButton* pickedButton_;
};

#endif // LEVELWIDGET_H
