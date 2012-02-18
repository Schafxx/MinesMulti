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
#include <QByteArray>

class ChatServer {
public:
	ChatServer(QObject *parent = 0, bool a = false);
	virtual ~ChatServer();
	bool b;

public slots:
	QByteArray read();
	void write(QByteArray *msg);
private:
	QUdpSocket *udpSocket;
};

#endif /* CHATSERVER_H_ */
