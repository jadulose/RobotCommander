//
// Created by hamlet on 2021/12/5.
//

#ifndef ROBOTCOMMANDER_COMMAND_H
#define ROBOTCOMMANDER_COMMAND_H

#include <QByteArray>

class Command {
public:
    virtual ~Command() = 0;
    [[nodiscard]] virtual const QByteArray &encode() const = 0;
    [[nodiscard]] virtual const QString &toString() const = 0;
};


#endif //ROBOTCOMMANDER_COMMAND_H