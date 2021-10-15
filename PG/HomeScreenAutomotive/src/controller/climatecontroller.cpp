#include "climatecontroller.h"
#include "loghelper.h"

ClimateController *ClimateController::m_instance = nullptr;
ClimateController::ClimateController(QObject *parent) : QObject(parent), m_initialize(false)
{
    LOG_INFO << "START";

    LOG_INFO << "END";

}

ClimateController::~ClimateController()
{
    LOG_INFO << "START";
    m_instance = nullptr;
    LOG_INFO << "END";
}

ClimateController *ClimateController::getInstance()
{
    if(m_instance == nullptr)
    {
        m_instance = new ClimateController();
    }
    return m_instance;
}

void ClimateController::initialize(QQmlContext *context)
{
    if(!m_initialize)
    {
        m_initialize = true;
        context->setContextProperty("CLIMATE_CTRL", &m_model);
    }
}
