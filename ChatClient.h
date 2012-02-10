/*
 * ChatClient.h
 *
 *  Created on: 04.02.2012
 *      Author: julian
 */

#ifndef CHATCLIENT_H_
#define CHATCLIENT_H_

#include <QtNetwork>
#include <QUdpSocket>
#include <QHostAddress>

class ChatClient {
public:
	ChatClient(QObject *parent = 0, QString ip = "");
	virtual ~ChatClient();
	void read();
	void write(QByteArray msg);
private:
	QUdpSocket *udpSocket;
};

#endif /* CHATCLIENT_H_ */
