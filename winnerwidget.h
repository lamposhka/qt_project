#ifndef WINNERWIDGET_H
#define WINNERWIDGET_H

#include <QWidget>

class WinnerWidget : public QWidget
{
    Q_OBJECT
public:
    explicit WinnerWidget(QString time, QWidget *parent = nullptr);

signals:
    void exit();
    void back();
};

#endif // WINNERWIDGET_H
