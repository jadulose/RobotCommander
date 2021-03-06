//
// Created by hamlet on 2021/12/7.
//

#include "position.h"
#include <QString>

int Position::X_RANGE{12000};
int Position::Y_RANGE{12000};

[[maybe_unused]] void Position::SET_RANGE(int x_range, int y_range) {
    X_RANGE = x_range;
    Y_RANGE = y_range;
}

Position::Position(int x, int y, float r) : x(x), y(y), r(r) {
}

QString Position::toString() const {
    return std::move(QString("Position(%1,%2,%3\317\200)").arg(x).arg(y).arg(r));
}
