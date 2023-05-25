#include "levelwidget.h"
#include "buttons/basicbutton.h"
#include <QGridLayout>
#include <vector>

LevelWidget::LevelWidget(QWidget *parent)
    : QWidget{parent}
{
    QGridLayout *layout = new QGridLayout(this);
    std::vector<QPushButton*> levels = {
        new BasicStyledButton(this), new BasicStyledButton(this), new BasicStyledButton(this)
    };
    for (auto i = 0; i < levels.size(); ++i) {
        layout->addWidget(levels[i], 0, i);
        levels[i]->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    }
    for (auto i = 0; i < levels.size(); ++i) {
        connect(levels[i], SIGNAL(clicked()), this, SLOT(onPick()));
    }
}

Mode LevelWidget::getMode()
{
    return mode_;
}

void LevelWidget::onPick()
{

}
