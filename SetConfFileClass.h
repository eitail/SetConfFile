#ifndef SETCONFFILECLASS_H
#define SETCONFFILECLASS_H

#include "setconffile_global.h"
#include <QSettings>
#include <QDebug>

class SETCONFFILESHARED_EXPORT SetConfFileClass
{
    public:
        static SetConfFileClass* getInstance();
        void SetconfValue(const QVariant &value,
                          const QString &key,
                          const QString &prefix,
                          QString file_name);

        QVariant ReadconfValue(const QString &key,
                           const QString &prefix,
                           QString file_name,
                           const QVariant &defaultValue = QVariant());

    private:
        SetConfFileClass();

    public:
        QString         m_Url;

    private:
        static  SetConfFileClass*   p;

    signals:

    public slots:

};

#endif // SETCONFFILECLASS_H
