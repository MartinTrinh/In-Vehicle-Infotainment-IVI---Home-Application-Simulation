#ifndef SCREENCONTROLLER_H
#define SCREENCONTROLLER_H

#include <QStack>
#include <QObject>
#include <QQmlContext>
#include <QQmlApplicationEngine>
#include "screenmodel.h"

class ScreenController : public QObject
{
    Q_OBJECT
private:
    explicit ScreenController(QObject *parent = nullptr);
public:
    ~ScreenController();

    // singleton pattern
    static ScreenController *getInstance();

    // initialize controller
    void initialize(QQmlContext *context);
    void initializeScreen(QQmlApplicationEngine *engine);

    // screen transition
    //Q_INVOKABLE void pushScreen(int screenId);
    Q_INVOKABLE void pushScreen(QString url);
    Q_INVOKABLE void replaceScreen(int screenId);
    Q_INVOKABLE void popScreen();
    Q_INVOKABLE void popToRoot();
private:
    void reloadScreen();
private:
    static ScreenController *m_instance;
    bool m_initialized;

    ScreenModel m_model;
    QStack<int> m_screenStack;
    QQmlApplicationEngine *m_engine;
};

#endif // SCREENCONTROLLER_H
