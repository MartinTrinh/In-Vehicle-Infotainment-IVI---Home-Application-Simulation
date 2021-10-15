#ifndef TRANSLATORCONTROLLER_H
#define TRANSLATORCONTROLLER_H

#include <QObject>
#include <QQmlContext>
#include "translatormodel.h"

class TranslatorController : public QObject
{
    Q_OBJECT

private:
    explicit TranslatorController(QObject *parent = nullptr);
public:
    ~TranslatorController();

    // singleton pattern
    static TranslatorController *getInstance();

    // initialize controller
    void initialize(QQmlContext *context);

private:
    static TranslatorController *m_instance;
    bool m_initialized;

    TranslatorModel m_model;
};

#endif // TRANSLATORCONTROLLER_H
