#include "translatorcontroller.h"
#include "loghelper.h"

TranslatorController* TranslatorController::m_instance = nullptr;

TranslatorController::TranslatorController(QObject *parent)
    : QObject(parent)
    , m_initialized(false)
{
    LOG_INFO;
}

TranslatorController::~TranslatorController()
{
    LOG_INFO;
}

TranslatorController *TranslatorController::getInstance()
{
    if(m_instance == nullptr)
    {
        m_instance = new TranslatorController();
    }

    return m_instance;
}

void TranslatorController::initialize(QQmlContext *context)
{
    LOG_INFO << "START";
    LOG_INFO << m_initialized;
    if(!m_initialized)
    {
        m_initialized = true;
        context->setContextProperty("TRANSLATOR_CTRL", this);
        context->setContextProperty("TRANSLATOR_MODEL", &m_model);
    }
    LOG_INFO << "START";
}
