#include "screencontroller.h"
#include "appdefines.h"
#include "loghelper.h"

ScreenController* ScreenController::m_instance = nullptr;

ScreenController::ScreenController(QObject *parent)
    : QObject(parent)
    , m_initialized(false)
    , m_engine(nullptr)
{
    LOG_INFO << "START";

    LOG_INFO << "END";
}

ScreenController::~ScreenController()
{
    LOG_INFO << "START";
    m_engine = nullptr;
    LOG_INFO << "END";
}

ScreenController *ScreenController::getInstance()
{
    if(m_instance == nullptr)
    {
        m_instance = new ScreenController();
    }

    return m_instance;
}

void ScreenController::initialize(QQmlContext *context)
{
    LOG_INFO << m_initialized;
    if(!m_initialized)
    {
        m_initialized = true;
        context->setContextProperty("SCREEN_CTRL", this);
        context->setContextProperty("SCREEN_MODEL", &m_model);
    }
}

void ScreenController::initializeScreen(QQmlApplicationEngine *engine)
{
    LOG_INFO << "START";
    if(m_engine == nullptr)
    {
        m_engine = engine;

        // load main qml
        m_engine->load(QUrl(QStringLiteral(MAIN_QML)));

        //show home screen
        pushScreen("qrc:/qml/screens/HomeScreen.qml");
    }
    LOG_INFO << "END";
}

void ScreenController::pushScreen(QString url)
{
    LOG_INFO << "START";
    LOG_INFO << url;
    int screenId = ScreenNameMap.key(url);
    m_screenStack.push(screenId);
    reloadScreen();
    LOG_INFO << "END";
}

void ScreenController::replaceScreen(int screenId)
{
    LOG_INFO << "START";
    LOG_INFO << screenId;
    if(!m_screenStack.isEmpty())
    {
        m_screenStack.pop();
    }
    m_screenStack.push(screenId);
    reloadScreen();
    LOG_INFO << "END";
}

void ScreenController::popScreen()
{
    LOG_INFO << "START";
    LOG_INFO << m_screenStack.count();
    if(m_screenStack.count() > 1)
    {
        m_screenStack.pop();
        reloadScreen();
    }
    LOG_INFO << "END";
}

void ScreenController::popToRoot()
{
    LOG_INFO << "START";
    LOG_INFO << m_screenStack.count();
    while(m_screenStack.count() > 1)
    {
        m_screenStack.pop();
    }
    reloadScreen();
    LOG_INFO << "END";
}

void ScreenController::reloadScreen()
{
    LOG_INFO << "START";
    if(!m_screenStack.isEmpty())
    {
        QString screenName = ScreenNameMap.value(m_screenStack.top());
        //ScreenNameMap.key();
        LOG_INFO << screenName;

        // update to model
        m_model.setCurrentScreen(screenName);

        // reload screen on qml
        if((m_engine != nullptr) && (m_engine->rootObjects().count() > 0))
        {
            QMetaObject::invokeMethod(m_engine->rootObjects().at(0), "reloadScreen");
        }
    }
    LOG_INFO << "END";
}
