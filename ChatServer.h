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

class ChatServer : public QObject {
	Q_OBJECT
public:
	ChatServer(QObject *parent = 0,QString ip = "", bool a = false);
	virtual ~ChatServer();
	bool b;
	quint16 senderPort;
	QHostAddress sender;
	QHostAddress *addr;

public slots:
	void read();
	void write(QByteArray *msg);
private:
	QUdpSocket *udpSocket;
signals:
	void rec(QByteArray D);
};

#endif /* CHATSERVER_H_ */
