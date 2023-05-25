#ifndef LEVELWIDGET_H
#define LEVELWIDGET_H

#include <QWidget>

enum Mode {
    EASY = 6,
    MEDIUM = 15,
    HARD = 30,
    RANDOM
};

class LevelWidget : public QWidget
{
    Q_OBJECT
public:
    explicit LevelWidget(QWidget *parent = nullptr);
    Mode getMode();
public slots:
    void onPick();
signals:
private:
    Mode mode_ = EASY;
};

#endif // LEVELWIDGET_H
