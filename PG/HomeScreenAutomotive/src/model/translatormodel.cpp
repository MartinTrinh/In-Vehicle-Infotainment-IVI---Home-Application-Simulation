#include "translatormodel.h"

TranslatorModel::TranslatorModel(QObject *parent)
    : QObject(parent)
    ,enMode(false)
    ,vnMode(false)
    ,koMode(false)
{
    m_translator = new QTranslator();
    setLanguage(1);
}

TranslatorModel::~TranslatorModel()
{
    m_translator = nullptr;
}

void TranslatorModel::setLanguage(int lang)
{
    LOG_INFO << "START";
    LOG_INFO << lang;
    switch (lang)
    {
//    case TranslatorModel::EN :
//        LOG_INFO <<   m_translator->load(":/localization/AppLanguage_en.qm");
//        QGuiApplication::installTranslator(m_translator);
//        enMode = true;
//        vnMode = false;
//        koMode = false;
//        emit languageChanged();
//        break;
    case TranslatorModel::VN :
        LOG_INFO <<  m_translator->load(":/localization/AppLanguage_vi.qm");
        QGuiApplication::installTranslator(m_translator);
        enMode = false;
        vnMode = true;
        koMode = false;
        emit languageChanged();
        break;
    case TranslatorModel::KO:
        LOG_INFO <<  m_translator->load(":/localization/AppLanguage_ko.qm");
        QGuiApplication::installTranslator(m_translator);
        emit languageChanged();
        enMode = false;
        vnMode = false;
        koMode = true;
        break;
    default:
        LOG_INFO <<   m_translator->load(":/localization/AppLanguage_en.qm");
        QGuiApplication::installTranslator(m_translator);
        enMode = true;
        vnMode = false;
        koMode = false;
        emit languageChanged();
        break;
    }
    LOG_INFO << "END";
}

bool TranslatorModel::checkModeLang(int lang)
{
    LOG_INFO << "START";
    bool checkMode = false;
    switch (lang)
    {
    case TranslatorModel::VN:
        checkMode =  vnMode;
        break;
    case TranslatorModel::KO:
        checkMode =  koMode;
        break;
    default:
        checkMode = enMode;
        break;
    }
    LOG_INFO << "END";
    return checkMode;

}
