/*
 * ChatServer.h
 *
 *  Created on: 04.02.2012
 *      Author: julian
 */

#ifndef CHATSERVER_H_
#define CHATSERVER_H_

#include <QtNetwork>
#include <QUdpSocket>
#include <QHostAddress>
class ChatServer {
public:
	ChatServer(QObject *parent = 0);
	virtual ~ChatServer();

public:
	void read();
private:
	QUdpSocket *udpSocket;
};

#endif /* CHATSERVER_H_ */
