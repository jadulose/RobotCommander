//
// Created by hamlet on 2021/12/7.
//

#include "positioninfo.h"

std::unique_ptr<PositionInfo> PositionInfo::decode(const QByteArray &data) {  // 送出所有权
    if (data.length() != DATA_LENGTH) return std::make_unique<PositionInfo>(-1, -1, 0.0f);
    int x = (((int) ((char8_t) data.at(0))) << 8) + (int) ((char8_t) data.at(1));
    int y = (((int) ((char8_t) data.at(2))) << 8) + (int) ((char8_t) data.at(3));
    char p[4];
    for (int i = 0; i < 4; ++i)
        p[i] = data.at(4 + i);
    float r = *((float *) p);
    return std::make_unique<PositionInfo>(x, y, r);
}

QString PositionInfo::toString() const {
    return Position::toString();
}
