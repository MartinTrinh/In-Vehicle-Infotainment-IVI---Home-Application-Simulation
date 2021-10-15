#ifndef CLIMATECONTROLLER_H
#define CLIMATECONTROLLER_H

#include <QObject>
#include <QQmlContext>
#include "climatemodel.h"

class ClimateController : public QObject
{
    Q_OBJECT
private:
    explicit ClimateController(QObject *parent = nullptr);
public:
    ~ClimateController();
    //singleton partern
    static ClimateController *getInstance();

    //intialize controller
    void initialize(QQmlContext *context);
private:
    static ClimateController *m_instance;
    bool m_initialize;
    ClimateModel m_model;
};

#endif // CLIMATECONTROLLER_H
