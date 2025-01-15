#include <QCoreApplication>
#include <QHostInfo>

#include <QSqlDatabase>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QHostInfo info = QHostInfo::fromName("qt-project.org");

    QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL");
    db.setHostName("acidalia");
    db.setDatabaseName("customdb");
    db.setUserName("mojito");
    db.setPassword("J0a1m8");
    bool ok = db.open();

    return a.exec();
}
