#include <QCoreApplication>
#include <iostream>
#include <sstream>
//#include <QDebug>
#include "server.h"

int main(int argc, char *argv[])
{
    quint16 listenPort = 0;
    if (argc >= 2){
        std::istringstream ss(argv[1]);
        if (!(ss >> listenPort)){
            std::cerr << "Invalid listening port: " << argv[1] << '\n';
            //qWarning() << "Invalid listening port: " << argv[1] << '\n';
            return 1;
        }
    }

    QCoreApplication a(argc, argv);

    Server server_0(listenPort);

    return a.exec();
}
