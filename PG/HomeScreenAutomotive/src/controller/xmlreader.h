#ifndef XMLREADER_H
#define XMLREADER_H
#include <QtXml>
#include <QFile>
#include <QList>
#include <QObject>
#include <QVariant>
#include "applicationsmodel.h"

class XmlReader : QObject
{
    Q_OBJECT
    QDomDocument m_xmlDoc;//The QDomDocument class represents an XML document.
public:
    explicit XmlReader(QObject *parent = nullptr);
    bool ReadXmlFile(QString filePath);    
    void ParserXml(ApplicationsModel &model);

};

#endif // XMLREADER_H
