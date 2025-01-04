#include "Utils.h"

QString Utils::intToString(int number) {
    return QString("%1").arg(number, 3, 10, QChar('0'));
}

int Utils::stringToInt(const QString& string) {
    bool ok = false;
    int number = string.toInt(&ok);

    if (!ok) {
        throw std::invalid_argument("Invalid string for conversion to int");
    }

    return number;
}
