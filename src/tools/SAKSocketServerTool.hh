/******************************************************************************
 * Copyright 2023 Qsaker(wuuhaii@outlook.com). All rights reserved.
 *
 * The file is encoded using "utf8 with bom", it is a part
 * of QtSwissArmyKnife project.
 *
 * QtSwissArmyKnife is licensed according to the terms in
 * the file LICENCE in the root of the source code directory.
 *****************************************************************************/
#ifndef SAKSOCKETSERVERTOOL_HH
#define SAKSOCKETSERVERTOOL_HH

#include "SAKCommunicationTool.hh"

class SAKSocketServerTool : public SAKCommunicationTool
{
    Q_OBJECT
    Q_PROPERTY(QString serverIp READ serverIp WRITE setServerIp NOTIFY serverIpChanged)
    Q_PROPERTY(int serverPort READ serverPort WRITE setServerPort NOTIFY serverPortChanged)
    Q_PROPERTY(QStringList clients READ clients NOTIFY clientsChanged)
    Q_PROPERTY(int clientIndex READ clientIndex WRITE setClientIndex NOTIFY clientIndexChanged)
    // Just for web socket server.
    Q_PROPERTY(int messageType READ messageType WRITE setMessageType NOTIFY messageTypeChanged)

public:
    explicit SAKSocketServerTool(const char *log, QObject *parent = nullptr);

    QString serverIp();
    void setServerIp(const QString &ip);
    int serverPort();
    void setServerPort(int port);
    QStringList clients();
    int clientIndex();
    void setClientIndex(int index);
    int messageType();
    void setMessageType(int type);

protected:
    QString mServerIp;
    int mServerPort;
    QStringList mClients;
    int mClientIndex;
    std::atomic_int8_t mMessageType;

signals:
    void serverIpChanged();
    void serverPortChanged();
    void clientsChanged();
    void clientIndexChanged();
    void messageTypeChanged();
};

#endif // SAKSOCKETSERVERTOOL_HH