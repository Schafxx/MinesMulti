/*
 * ChatClient.cpp
 *
 *  Created on: 04.02.2012
 *      Author: julian
 */

#include "ChatClient.h"
#include <QObject>
#include <QtNetwork>
#include <QUdpSocket>
#include <QByteArray>
#include <QHostAddress>

ChatClient::ChatClient(QObject *parent, QString ip) {
	udpSocket = new QUdpSocket(parent);;
	QHostAddress *host = new QHostAddress(ip);
	udpSocket->bind(*host, 7755);

}

ChatClient::~ChatClient() {
	// TODO Auto-generated destructor stub
}
