#include "mainmenu.h"
#include <QGridLayout>
#include <QPushButton>
#include "buttons/basicbutton.h"
#include <QColor>
#include <QPixmap>
#include <QLabel>
#include <QFontDatabase>

MainMenu::MainMenu(QWidget *parent) : QWidget(parent), levelWidget_(new LevelWidget(this))
{
//    render title
    QFontDatabase::addApplicationFont(":/fonts/ARCADECLASSIC.TTF");
    QFont font = QFont("ArcadeClassic", 150, 1);
    QLabel* title = new QLabel(this);
    title->setText("Maze!");
    QPalette p1 = title->palette();
    p1.setColor(QPalette::WindowText, Qt::white);
    title->setPalette(p1);
    title->setFont(font);
    title->setAlignment(Qt::AlignCenter);
    title->setFixedWidth (800);

//    background
    QPalette p2 = palette();
    p2.setColor(QPalette::Window, Qt::black);
    setAutoFillBackground(true);
    setPalette(p2);

//    layout
    QGridLayout *gridLayout = new QGridLayout(this);
    setLayout(gridLayout);
    BasicStyledButton *settings = new BasicStyledButton("settings", this);
    BasicStyledButton *help = new BasicStyledButton("help", this);

    settings->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    help->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    gridLayout->addWidget(settings, 0, 4, 1, 1);
    gridLayout->addWidget(help, 0, 0, 1, 1);
    gridLayout->addWidget(title, 1, 0, 1, 5);
    gridLayout->addWidget(levelWidget_, 10, 0, 4, 4);

    gridLayout->setSpacing(50);

    connect(settings, SIGNAL(clicked()), this, SIGNAL(settingsSelected()));
    connect(help, SIGNAL(clicked()), this, SIGNAL(helpSelected()));

    BasicStyledButton *start = new BasicStyledButton("start", this);
    gridLayout->addWidget(start, 11, 0, 1, 4);
    start->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    connect(start, SIGNAL(clicked()), this, SIGNAL(startSelected()));
//    setFixedSize(500, 500);
}
