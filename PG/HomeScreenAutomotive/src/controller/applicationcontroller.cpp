#include "applicationcontroller.h"
#include "loghelper.h"

ApplicationController* ApplicationController::m_instance = nullptr;
ApplicationController::ApplicationController(QObject *parent)
    : QObject(parent )
    ,m_initialize(false)
{
    LOG_INFO << "START";
    loadDataFromLocal();
    LOG_INFO << "END";
}

ApplicationController::~ApplicationController()
{
    LOG_INFO << "START";
    m_instance = nullptr;
    LOG_INFO << "END";
}

ApplicationController *ApplicationController::getInstance()
{
    if( m_instance == nullptr)
    {
        m_instance = new ApplicationController();
    }
    return m_instance;
}

void ApplicationController::initialize(QQmlContext *context)
{
    LOG_INFO << "START";
    LOG_INFO << m_initialize;
    if(!m_initialize)
    {
        m_initialize = true;
        context->setContextProperty("APP_CTRL", this);
        context->setContextProperty("APP_MODEL", &m_model);
    }
    LOG_INFO << "END";
}

void ApplicationController::loadDataFromLocal()
{
    LOG_INFO << "START";
    m_xmlReader.ReadXmlFile(QString(PROJECT_PATH)+ "applications.xml");
    m_xmlReader.ParserXml(m_model);
    LOG_INFO << "END";
}



void ApplicationController::updateDataFromQML(int to, int from)
{
    LOG_INFO << "START";
    LOG_INFO << "from: " << from << " to: " << to;
    m_model.moveItem(from, to);
    m_xmlReader.XmlUpdateData(m_model.getListApp());
    LOG_INFO << "END";
}

