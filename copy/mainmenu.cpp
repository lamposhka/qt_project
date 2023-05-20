#include "mainmenu.h"
#include <QGridLayout>
#include <QPushButton>

MainMenu::MainMenu(QWidget *parent) : QWidget(parent), levelWidget_(new LevelWidget(this))
{
    QGridLayout *gridLayout = new QGridLayout(this);
    setLayout(gridLayout);
    QPushButton *settings = new QPushButton("settings", this);
    QPushButton *help = new QPushButton("help", this);

    settings->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    help->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    gridLayout->addWidget(settings, 0, 2, 1, 2);
    gridLayout->addWidget(help, 0, 0, 1, 2);
    gridLayout->addWidget(levelWidget_, 1, 0, 1, 4);

    gridLayout->setSpacing(50);

    connect(settings, SIGNAL(clicked()), this, SIGNAL(settingsSelected()));
    connect(help, SIGNAL(clicked()), this, SIGNAL(helpSelected()));

    QPushButton *start = new QPushButton("start", this);
    gridLayout->addWidget(start, 3, 0, 1, 4);
    start->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    connect(start, SIGNAL(clicked()), this, SIGNAL(startSelected()));
}
