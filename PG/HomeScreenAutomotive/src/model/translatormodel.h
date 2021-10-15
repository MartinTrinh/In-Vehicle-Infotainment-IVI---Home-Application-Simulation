#ifndef TRANSLATORMODEL_H
#define TRANSLATORMODEL_H

#include <QObject>
#include <QVariant>
#include <QTranslator>
#include <QFile>
#include <QGuiApplication>
#include "loghelper.h"
#define ADD_GETTER(Type, Name, Value) \
    Q_PROPERTY(QString Name READ Name NOTIFY languageChanged)\
    public:\
    Type Name() const { return (Value); }

class TranslatorModel : public QObject
{
    Q_OBJECT
    ADD_GETTER(QString, STR_APP_MAP, tr("STR_APP_MAP"))
    ADD_GETTER(QString, STR_APP_VIDEO, tr("STR_APP_VIDEO"))
    ADD_GETTER(QString, STR_APP_MEDIA, tr("STR_APP_MEDIA"))
    ADD_GETTER(QString, STR_APP_PHONE, tr("STR_APP_PHONE"))
    ADD_GETTER(QString, STR_APP_RADIO, tr("STR_APP_RADIO"))
    ADD_GETTER(QString, STR_APP_SETTING, tr("STR_APP_SETTING"))
    ADD_GETTER(QString, STR_WIDGET_CLIMATE, tr("STR_WIDGET_CLIMATE"))
    ADD_GETTER(QString, STR_WIDGET_DRIVER, tr("STR_WIDGET_DRIVER"))
    ADD_GETTER(QString, STR_WIDGET_PASSENDER, tr("STR_WIDGET_PASSENDER"))
    ADD_GETTER(QString, STR_WIDGET_OUTSIDE, tr("STR_WIDGET_OUTSIDE"))
    ADD_GETTER(QString, STR_WIDGET_AUTOMODE, tr("STR_WIDGET_AUTOMODE"))
    ADD_GETTER(QString, STR_WIDGET_SYNCMODE, tr("STR_WIDGET_SYNCMODE"))
    ADD_GETTER(QString, STR_WIDGET_USBMUSIC, tr("STR_WIDGET_USBMUSIC"))
    ADD_GETTER(QString, STR_MEDIA_TITLE, tr("STR_MEDIA_TITLE"))
    ADD_GETTER(QString, STR_MEDIA_PLAYLIST, tr("STR_MEDIA_PLAYLIST"))
    ADD_GETTER(QString, STR_SETTING_SERVICE_MODE, tr("STR_SETTING_SERVICE_MODE"))
    ADD_GETTER(QString, STR_SETTING_LANGUAGE, tr("STR_SETTING_LANGUAGE"))
    ADD_GETTER(QString, STR_SETTING_LANGUAGE_VIETNAMESE, tr("STR_SETTING_LANGUAGE_VIETNAMESE"))
    ADD_GETTER(QString, STR_SETTING_LANGUAGE_ENGLISH, tr("STR_SETTING_LANGUAGE_ENGLISH"))
    ADD_GETTER(QString, STR_SETTING_LANGUAGE_KOREA, tr("STR_SETTING_LANGUAGE_KOREA"))
    ADD_GETTER(QString, STR_SETTING_LANGUAGE_VOLUME, tr("STR_SETTING_LANGUAGE_VOLUME"))

    Q_PROPERTY(QString emptyString READ emptyString NOTIFY languageChanged)
    Q_ENUMS(LANGUAGE)
public:
        explicit TranslatorModel(QObject *parent = nullptr);
    ~TranslatorModel();
    enum LANGUAGE{ EN = 1, VN, KO };
    QString emptyString() const {
        return ""; // notify signal to QML
    }
    Q_INVOKABLE void setLanguage(int lang);
    Q_INVOKABLE bool checkModeLang(int lang);
signals:
    void languageChanged();
private:
    QTranslator*  m_translator;
    bool enMode;
    bool vnMode;
    bool koMode;
};

#endif // TRANSLATORMODEL_H
