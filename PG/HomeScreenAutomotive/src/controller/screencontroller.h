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
    Q_PROPERTY(QString itemFocus READ getItemFocus  NOTIFY focusChanged)
   // Q_PROPERTY(QString color READ getColor NOTIFY colorChanged)
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


    //controll focus
    QString getItemFocus() const;
    Q_INVOKABLE void setFocus(QString itemFocus);

signals:
    void focusChanged();
private:
    void reloadScreen();
private:
    static ScreenController *m_instance;
    bool m_initialized;
    QString m_itemFocus;
    ScreenModel m_model;
    QStack<int> m_screenStack;
    QQmlApplicationEngine *m_engine;
};

#endif // SCREENCONTROLLER_H
