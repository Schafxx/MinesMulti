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

class ChatClient : public QObject{
	Q_OBJECT
public:
	ChatClient(QObject *parent = 0, QString ip = "", bool a = false);
	virtual ~ChatClient();
	void write(QByteArray *msg);
	bool b;
public slots:
	void read();
private:
	QUdpSocket *udpSocket;
signals:
	void rec(QByteArray D);
};

#endif /* CHATCLIENT_H_ */
