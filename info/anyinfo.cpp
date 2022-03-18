//
// Created by hamlet on 2021/12/7.
//

#include "anyinfo.h"
#include "../data/hexdisplayer.h"

QString AnyInfo::toString() const {
    QString text = QString("Any(%1)").arg(HexDisplayer::toString(DATA));
    return std::move(text);
}

AnyInfo::AnyInfo(QByteArray data)
        : DATA(std::move(data)) {
}
