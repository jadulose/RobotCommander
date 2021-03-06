//
// Created by hamlet on 2021/12/6.
//

#ifndef ROBOTCOMMANDER_SETTINGS_H
#define ROBOTCOMMANDER_SETTINGS_H

#include <QColor>
#include <QRect>
#include <QSerialPort>

class QSettings;

// 设置，包含所有需要保存的内容
class Settings {
public:
    // 表示在地图上所显示的标识点
    struct Mark {
        enum Shape {
            Square = 0, Triangle, Circular
        };

        bool    pic_or_shape;  // 图片：true，形状：false
        QString pic;
        int     pic_size;
        Shape   shape;
        int     shape_size;
        QColor  color;
    };

    enum Language {
        Chinese = 0, English = 1
    };

    enum ReleaseChannel {
        Main = 0, Dev = 1
    };

    struct Serial {
        QString name;
        qint32 baudRate;
        QString stringBaudRate;
        QSerialPort::DataBits dataBits;
        QString stringDataBits;
        QSerialPort::Parity parity;
        QString stringParity;
        QSerialPort::StopBits stopBits;
        QString stringStopBits;
        QSerialPort::FlowControl flowControl;
        QString stringFlowControl;
    };

    Settings();
    ~Settings();
    void save();

    // General
    QString map_pic;

    Mark mark_cur;  // Robot Current Position
    Mark mark_tar;  // Robot Target Position

    // Appearance
    Language language = Chinese;

    // Serial
    Serial serial;

    // Update
    ReleaseChannel channel = Main;
    bool auto_check_update = true;

    // Window
    QSize settingsDialog_size;

private:
    QSettings *m_settings;
};

QDataStream &operator<<(QDataStream &out, const Settings::Mark &mark);
QDataStream &operator>>(QDataStream &in, Settings::Mark &mark);

QDataStream &operator<<(QDataStream &out, const Settings::Serial &serial);
QDataStream &operator>>(QDataStream &in, Settings::Serial &serial);

#endif //ROBOTCOMMANDER_SETTINGS_H
