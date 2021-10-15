#ifndef SCREENMODEL_H
#define SCREENMODEL_H

#include <QObject>

class ScreenModel : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString currentScreen READ currentScreen NOTIFY currentScreenChanged)
public:
    explicit ScreenModel(QObject *parent = nullptr);
    ~ScreenModel();

    QString currentScreen() const;
    void setCurrentScreen(const QString &currentScreen);

signals:
    void currentScreenChanged();

private:
    QString m_currentScreen;
};

#endif // SCREENMODEL_H
