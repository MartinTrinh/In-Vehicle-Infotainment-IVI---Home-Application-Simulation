#ifndef APPLICATIONCONTROLLER_H
#define APPLICATIONCONTROLLER_H

#include <QObject>
#include <QQmlContext>
#include "applicationsmodel.h"
#include "xmlreader.h"

class ApplicationController : public QObject
{
    Q_OBJECT
    explicit ApplicationController(QObject *parent = nullptr);
public:
    ~ApplicationController();
    // singleton pattern
    static ApplicationController *getInstance();

    //initialize controller
    void initialize(QQmlContext *context);
    void loadDataFromLocal();
   Q_INVOKABLE void updateDataFromQML(int from, int to);

signals:
   void modelChanged();
private:
    static ApplicationController *m_instance;
    bool m_initialize;
    ApplicationsModel m_model;
    XmlReader m_xmlReader;
};

#endif // APPLICATIONCONTROLLER_H
