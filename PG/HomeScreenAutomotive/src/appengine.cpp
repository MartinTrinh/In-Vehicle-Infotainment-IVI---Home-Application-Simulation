#include "appengine.h"
#include "appdefines.h"
#include "loghelper.h"

AppEngine* AppEngine::m_instance = nullptr;

AppEngine::AppEngine(QObject *parent)
    : QObject(parent)
    , m_initialized(false)
    , m_app(nullptr)
{
    LOG_INFO << "START";

    LOG_INFO << "END";
}

AppEngine::~AppEngine()
{
    LOG_INFO << "START";
    m_app = nullptr;
    LOG_INFO << "END";
}

AppEngine *AppEngine::getInstance()
{
    LOG_INFO << "START";
    if(m_instance == nullptr)
    {
        m_instance = new AppEngine();
    }
    LOG_INFO << "END";
    return m_instance;
}

void AppEngine::initialize(QGuiApplication *app)
{
    LOG_INFO << "START";
    LOG_INFO << m_initialized;
    if(!m_initialized)
    {
        m_initialized = true;
        m_app = app;
        // init home application
        registerQmlObjects();
        createControllers();
        initControllers();
        initScreens();
    }
    LOG_INFO << "END";
}

void AppEngine::registerQmlObjects()
{
    LOG_INFO << "START";

    qmlRegisterType<AppEnums>("AppEnums", 1, 0, "AppEnums");

    LOG_INFO << "END";
}

void AppEngine::createControllers()
{
    LOG_INFO << "START";
    ScreenController::getInstance();
    ApplicationController::getInstance();
    MediaController::getInstance();
    ClimateController::getInstance();
    TranslatorController::getInstance();
    LOG_INFO << "END";
}

void AppEngine::initControllers()
{
    LOG_INFO << "START";
    ScreenController::getInstance()->initialize(m_engine.rootContext());
    ApplicationController::getInstance()->initialize(m_engine.rootContext());
    MediaController::getInstance()->initialize(m_engine.rootContext());
    ClimateController::getInstance()->initialize(m_engine.rootContext());
    TranslatorController::getInstance()->initialize(m_engine.rootContext());
    LOG_INFO << "END";
}

void AppEngine::initScreens()
{
    LOG_INFO << "START";
    ScreenController::getInstance()->initializeScreen(&m_engine); // initialize screen root
    LOG_INFO << "END";
}
