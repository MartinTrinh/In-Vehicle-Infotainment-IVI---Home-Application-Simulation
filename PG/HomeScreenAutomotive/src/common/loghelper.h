#ifndef LOGHELPER_H
#define LOGHELPER_H

#include <QDebug>
#include <unistd.h>
#ifdef __linux
#include <sys/syscall.h>
#elif define(win32) || define(win64)
#include <window.h>
#endif
//#define LOG_INFO qDebug().nospace() << "[Thread #" << syscall(SYS_gettid) << "]" << Q_FUNC_INFO << " "
#define LOG_INFO qDebug() << __LINE__ << Q_FUNC_INFO << " "
#endif // LOGHELPER_H
