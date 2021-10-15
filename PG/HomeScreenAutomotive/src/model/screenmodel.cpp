#include "screenmodel.h"
#include "loghelper.h"
ScreenModel::ScreenModel(QObject *parent)
    : QObject(parent)
{
    LOG_INFO << "START";

    LOG_INFO << "END";
}

ScreenModel::~ScreenModel()
{
    LOG_INFO << "START";

    LOG_INFO << "END";
}

QString ScreenModel::currentScreen() const
{
    return m_currentScreen;
}

void ScreenModel::setCurrentScreen(const QString &currentScreen)
{
    if(m_currentScreen != currentScreen)
    {
        m_currentScreen = currentScreen;
        emit currentScreenChanged();
    }
}
