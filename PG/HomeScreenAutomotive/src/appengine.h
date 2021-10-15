#ifndef APPENGINE_H
#define APPENGINE_H

#include <QObject>
#include <QGuiApplication>
#include "screencontroller.h"
#include "translatorcontroller.h"
#include "applicationcontroller.h"
#include "mediacontroller.h"
#include "climatecontroller.h"
class AppEngine : public QObject
{
    Q_OBJECT

private:
    explicit AppEngine(QObject *parent = nullptr);

public:
    ~AppEngine();

    // singleton pattern
    static AppEngine *getInstance();

    // initialize app
    void initialize(QGuiApplication *app);

private:
    void registerQmlObjects();
    void createControllers();
    void initControllers();
    void initScreens();

private:
    static AppEngine* m_instance;
    bool m_initialized;
    QGuiApplication* m_app; // init GUI engine
    QQmlApplicationEngine m_engine; // registes QML type
};

#endif // APPENGINE_H
