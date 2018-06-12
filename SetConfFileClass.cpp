#include "SetConfFileClass.h"

/*****************************************************************
 *
 * ------ how to use ------
 *
 * m_pSetConfFileClass = SetConfFileClass::getInstance();
 * m_pSetConfFileClass->m_Url = "/root/Demo/so/file/";
 *
 * m_pSetConfFileClass->SetconfValue("aaabbb","leo_type","leo_group","control");
 * m_pSetConfFileClass->ReadconfValue("leo_type","leo_group","control");
 *
 *****************************************************************/

SetConfFileClass::SetConfFileClass()
{
    m_Url == "";
}

SetConfFileClass* SetConfFileClass::p = NULL;
SetConfFileClass* SetConfFileClass::getInstance()
{
    if( p == NULL )
    {
        p = new SetConfFileClass();
    }
    return p;
}

/*****************************************************************
 *
 * Write configuration file
 *
 * example:
 * [prefix]
 * key=value
 *
 *****************************************************************/
void SetConfFileClass::SetconfValue(const QVariant &value,const QString &key,const QString &prefix,QString file_name)
{
    if( m_Url != "" )
    {
        QString url = m_Url + file_name + ".ini";
        QSettings settings(url, QSettings::IniFormat);
        settings.beginGroup(prefix);
        settings.setValue(key, value);
        settings.endGroup();
    }
}

/*****************************************************************
 *
 * Read configuration file
 *
 *****************************************************************/
QVariant SetConfFileClass::ReadconfValue(const QString &key, const QString &prefix, QString file_name, const QVariant &defaultValue)
{
    if( m_Url != "" )
    {
        QString url = m_Url + file_name + ".ini";
        QSettings settings(url, QSettings::IniFormat);
        settings.beginGroup(prefix);
        QVariant value = settings.value(key, defaultValue);
        settings.endGroup();
        return value;
    }
    return QVariant();
}
