#include "winnerwidget.h"
#include <QLabel>
#include <QVBoxLayout>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QFontDatabase>
#include <QPalette>
#include "buttons/basicbutton.h"


WinnerWidget::WinnerWidget(QString time, QWidget *parent)
    : QWidget{parent}
{
    auto* layout = new QVBoxLayout(this);
    QFontDatabase::addApplicationFont(":/fonts/ARCADECLASSIC.TTF");
    QFont font = QFont("ArcadeClassic", 100, 1);

    QLabel *congratulations = new QLabel("Congratulations!");
    QPalette p1 = congratulations->palette();
    p1.setColor(QPalette::WindowText, Qt::white);
    congratulations->setFont(font);
    congratulations->setPalette(p1);
    congratulations->setAlignment(Qt::AlignCenter);
    layout->addWidget(congratulations);

    QPalette p2 = palette();
    p2.setColor(QPalette::Window, Qt::black);
    setAutoFillBackground(true);
    setPalette(p2);

    QLabel *info = new QLabel(this);
    layout->addWidget(info);
    info->setAlignment(Qt::AlignCenter);
    info->setStyleSheet("QLabel{ font-family: \"Farfetch Basis\",\"Helvetica Neue\",Arial,sans-serif;"
                                                           "font-size: 30px;"
                                                           "font-weight: 200;"
                                                            "color: white;}");
    time.remove(time.size() - 4, 4);
//    time.remove(time.size() - 1, 1);
//    time.remove(time.size() - 1, 1);
//    time.remove(time.size() - 1, 1);
    info->setText(QString("You managed to solve the maze in %1 seconds").arg(time));

    BasicStyledButton *back = new BasicStyledButton("back", this);
    connect(back, SIGNAL(clicked(bool)), this, SIGNAL(back()));
    layout->addWidget(back);
    layout->setAlignment(Qt::AlignHCenter);

    BasicStyledButton *exit = new BasicStyledButton("exit", this);
    connect(exit, SIGNAL(clicked(bool)), this, SIGNAL(exit()));


}
