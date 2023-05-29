#include "levelwidget.h"
#include "buttons/basicbutton.h"
#include <QGridLayout>
#include <vector>

LevelWidget::LevelWidget(QWidget *parent)
    : QWidget{parent}
{
    QGridLayout *layout = new QGridLayout(this);
    std::vector<LevelModeButton*> levels = {
        new LevelModeButton("Easy", EASY, this), new LevelModeButton("Normal", NORMAL, this),
        new LevelModeButton("Hard", HARD, this), new LevelModeButton("Random", RANDOM, this)
    };
    for (auto i = 0; i < levels.size(); ++i) {
        layout->addWidget(levels[i], 0, i);
        levels[i]->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        for (auto j  = 0; j < levels.size(); ++j) {
            if (i != j) {
                connect(levels[i], SIGNAL(picked_true()), levels[j], SLOT(unpick()));
            }
        }
        connect(levels[i], SIGNAL(clicked()), this, SLOT(onPick()));
    }
    pickedButton_= levels[3];
    pickedButton_->pick(true);
    emit pickedLevel();
}

Mode LevelWidget::getMode()
{
    return pickedButton_->mode();
}

void LevelWidget::onPick()
{
    pickedButton_ = static_cast<LevelModeButton*>(sender());
    emit pickedLevel();
}
