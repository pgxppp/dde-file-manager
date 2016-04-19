#include "app/global.h"
#include "app/logutil.h"
#include "app/filemanagerapp.h"
#include "app/singleapplication.h"

#include "widgets/commandlinemanager.h"

#include "../dialogs/dialogmanager.h"

#include "../shutil/mimesappsmanager.h"
#include "durl.h"
#include "../dialogs/openwithdialog.h"

#include <dthememanager.h>
#include <dwindow.h>

#include <QApplication>
#include <QDebug>
#include <QThreadPool>

DWIDGET_USE_NAMESPACE

int main(int argc, char *argv[])
{
    LogUtil::registerLogger();

    SingleApplication app(argc, argv);

    app.setOrganizationName("deepin");
    app.setApplicationName(QObject::tr("dde-file-manager"));
    app.setApplicationVersion("v1.0");


    CommandLineManager::instance()->process();

    DUrl commandlineUrl;

    if (CommandLineManager::instance()->positionalArguments().count() > 0){
        commandlineUrl = DUrl::fromUserInput(CommandLineManager::instance()->positionalArguments().at(0));
        qDebug() << commandlineUrl;
    } else {
        commandlineUrl = DUrl::fromLocalFile(QDir::homePath());
        qDebug() << commandlineUrl;
    }

    QThreadPool::globalInstance()->setMaxThreadCount(100);

    QString uniqueKey = "dde-file-manager";

    bool isSingleInstance  = app.setSingleInstance(uniqueKey);

    qDebug() << isSingleInstance << commandlineUrl;

    if (isSingleInstance){
        DThemeManager::instance()->setTheme("light");

        fileManagerApp->show(commandlineUrl);
        dialogManager;

        quick_exit(app.exec());
    }else{
        SingleApplication::newClientProcess(uniqueKey);
    }
}
