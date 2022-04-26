#include "translatormodel.h"

TranslatorModel::TranslatorModel(QObject *parent)
    : QObject(parent)
    ,m_enMode(false)
    ,m_vnMode(false)
    ,m_koMode(false)
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
    case TranslatorModel::VN :
        LOG_INFO <<  m_translator->load(":/localization/AppLanguage_vi.qm");
        QGuiApplication::installTranslator(m_translator);
        m_enMode = false;
        m_vnMode = true;
        m_koMode = false;
        emit languageChanged();
        break;
    case TranslatorModel::KO:
        LOG_INFO <<  m_translator->load(":/localization/AppLanguage_ko.qm");
        QGuiApplication::installTranslator(m_translator);
        emit languageChanged();
        m_enMode = false;
        m_vnMode = false;
        m_koMode = true;
        break;
    default:
        LOG_INFO <<   m_translator->load(":/localization/AppLanguage_en.qm");
        QGuiApplication::installTranslator(m_translator);
        m_enMode = true;
        m_vnMode = false;
        m_koMode = false;
        emit languageChanged();
        break;
    }
    LOG_INFO << "END";
}

bool TranslatorModel::checkModelLang(int lang)
{
    LOG_INFO << "START";
    bool checkMode = false;
    switch (lang)
    {
    case TranslatorModel::VN:
        checkMode =  m_vnMode;
        break;
    case TranslatorModel::KO:
        checkMode =  m_koMode;
        break;
    default:
        checkMode = m_enMode;
        break;
    }
    LOG_INFO << "END";
    return checkMode;

}
