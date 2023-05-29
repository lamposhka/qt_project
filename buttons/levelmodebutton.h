#ifndef LEVELMODEBUTTON_H
#define LEVELMODEBUTTON_H

#include <QPushButton>
#include <QString>
#include <QWidget>
#include "../mode.h"
#include <QSoundEffect>


class LevelModeButton : public QPushButton
{
    Q_OBJECT
    Q_PROPERTY(bool picked READ picked WRITE pick NOTIFY picked)
public:
    LevelModeButton(const QString& text, const Mode& mode,  QWidget *parent = nullptr);
public slots:
  void pick(bool);
  void unpick();
  void onPicked();
  Mode mode();


  bool picked();
  void invert();
signals:
  void picked(bool);
  void picked_true();
private:
  bool picked_;
  Mode mode_;
  QSoundEffect* effect;
};

#endif // LEVELMODEBUTTON_H
