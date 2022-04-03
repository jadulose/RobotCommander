//
// Created by hamlet on 2022/4/3.
//

#include "pid2command.h"
#include <QDoubleSpinBox>
#include <QHBoxLayout>
#include <QLabel>
#include <QString>

const QString PID2Command::NAME{"PID2"};

inline void appendFloat(QByteArray &code, float value) { // 在code末尾添加一个4位float值
    code.append(reinterpret_cast<const char *>(&value), sizeof(value));
}

QByteArray PID2Command::encode() const {
    QByteArray code{};
    code += static_cast<char>(getType());
    appendFloat(code, p);
    appendFloat(code, i);
    appendFloat(code, d);
    return std::move(code);
}

QString PID2Command::toString() const {
    return NAME + PID::toString();
}

Command *PID2Command::copy() const {
    return new PID2Command(p, i, d);
}

Form *PID2Command::createForm(QWidget *parent) const {
    return new PID2Form(this, parent);
}

PID2Form::PID2Form(const PID2Command *command, QWidget *parent) :
        Form(parent), spinBox_p(new QDoubleSpinBox(this)),
        spinBox_i(new QDoubleSpinBox(this)),
        spinBox_d(new QDoubleSpinBox(this)) {
    auto label_P = new QLabel(this), label_I = new QLabel(this), label_D = new QLabel(this);
    label_P->setText(tr("P:")), label_I->setText(tr("I:")), label_D->setText(tr("D:"));
    auto layout = new QHBoxLayout(this);
    layout->addWidget(label_P), layout->addWidget(spinBox_p);
    layout->addSpacerItem(new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum));
    layout->addWidget(label_I), layout->addWidget(spinBox_i);
    layout->addSpacerItem(new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum));
    layout->addWidget(label_D), layout->addWidget(spinBox_d);
    layout->addSpacerItem(new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum));
    layout->setStretch(2, 1);
    layout->setStretch(5, 1);
    layout->setStretch(8, 2);
}

std::shared_ptr<Command> PID2Form::getCommand() const {
    return std::make_shared<PID2Command>(spinBox_p->value(), spinBox_i->value(), spinBox_d->value());
}
