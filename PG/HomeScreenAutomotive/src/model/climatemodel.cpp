#include "climatemodel.h"
#include "loghelper.h"
#include "loghelper.h"

ClimateModel::ClimateModel(QObject *parent) : QObject(parent)
{
    LOG_INFO << "START";
    m_climate = new local::Climate("mercedes.ivi","/Climate", QDBusConnection::sessionBus(), this);
    if (m_climate->isValid()){
        LOG_INFO << "Climate dbus connect success";
        QObject::connect(m_climate,&local::Climate::dataChanged,this,&ClimateModel::dataChanged);
    } else {
        LOG_INFO << "Climate dbus connect error";
    }
    LOG_INFO << "END";
}

double ClimateModel::GetDriverTemperature()
{
    LOG_INFO << "m_climate->getTemp_driver(): "<< m_climate->getTemp_driver();
    return m_climate->getTemp_driver();

}

double ClimateModel::GetPassengerTemperature()
{
    LOG_INFO << " m_climate->getTemp_passenger(): "<< m_climate->getTemp_passenger();
    return m_climate->getTemp_passenger();

}

int ClimateModel::GetFanLevel()
{
    LOG_INFO << "m_climate->getFan_speed(): "<< m_climate->getFan_speed();
    return m_climate->getFan_speed();

}

int ClimateModel::GetDriverWindMode()
{
    LOG_INFO << "m_climate->getDriverWind_mode(): "<< m_climate->getDriverWind_mode();
    return m_climate->getDriverWind_mode();

}

int ClimateModel::GetPassengerWindMode()
{
    LOG_INFO << "m_climate->getPassengerWind_mode(): "<< m_climate->getPassengerWind_mode();
    return m_climate->getPassengerWind_mode();

}

int ClimateModel::GetAutoMode()
{
    LOG_INFO << "m_climate->getAuto_mode(): " <<m_climate->getAuto_mode();
    return m_climate->getAuto_mode();
}

int ClimateModel::GetSyncMode()
{
    LOG_INFO  << "m_climate->getSync_mode(): " << m_climate->getSync_mode();
    return m_climate->getSync_mode();
}
