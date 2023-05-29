#include "mainmenu.h"
#include <QPushButton>
#include "buttons/basicbutton.h"
#include <QColor>
#include <QPixmap>
#include <QLabel>
#include <QFontDatabase>
#include <QHBoxLayout>
#include <QVBoxLayout>


MainMenu::MainMenu(QWidget *parent) : QWidget(parent), levelWidget_(new LevelWidget(this))
{
//    render title
    QFontDatabase::addApplicationFont(":/fonts/ARCADECLASSIC.TTF");
    QFont font = QFont("ArcadeClassic", 160, 1);
    QLabel* title = new QLabel(this);
    title->setText("Maze!");
    QPalette p1 = title->palette();
    p1.setColor(QPalette::WindowText, Qt::white);
    title->setPalette(p1);
    title->setFont(font);
    title->setAlignment(Qt::AlignHCenter);
//    title->setFixedWidth (800);

//    background
    QPalette p2 = palette();
    p2.setColor(QPalette::Window, Qt::black);
    setAutoFillBackground(true);
    setPalette(p2);

//    layout
    QVBoxLayout *verticalLayout = new QVBoxLayout(this);
//    BasicStyledButton *settings = new BasicStyledButton("settings", this);
//    BasicStyledButton *help = new BasicStyledButton("help", this);

//    QHBoxLayout *horizontalLayout = new QHBoxLayout(this);
//    horizontalLayout->addWidget(settings);
//    horizontalLayout->addWidget(help);

    verticalLayout->addWidget(title);
    verticalLayout->addWidget(levelWidget_);

    verticalLayout->setSpacing(50);
    verticalLayout->setAlignment(Qt::AlignHCenter);

//    connect(settings, SIGNAL(clicked()), this, SIGNAL(settingsSelected()));
//    connect(help, SIGNAL(clicked()), this, SIGNAL(helpSelected()));

    QHBoxLayout* horizontalEmpty = new QHBoxLayout(this);
    horizontalEmpty->setAlignment(Qt::AlignCenter);
    BasicStyledButton *start = new BasicStyledButton("start", this);
    horizontalEmpty->addWidget(start);
    start->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
//    verticalLayout->addWidget(start);
    verticalLayout->addLayout(horizontalEmpty);

    BasicStyledButton *exit = new BasicStyledButton("exit", this);
    connect(start, SIGNAL(clicked()), this, SIGNAL(startSelected()));
    connect(exit, SIGNAL(clicked(bool)), this, SIGNAL(exitSelected()));
    connect(levelWidget_, SIGNAL(pickedLevel()), this, SLOT(changeMode()));

}

void MainMenu::changeMode()
{
    mode = levelWidget_->getMode();

}
