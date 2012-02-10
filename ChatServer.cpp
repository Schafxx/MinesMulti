/*
 * ChatServer.cpp
 *
 *  Created on: 04.02.2012
 *      Author: julian
 */

#include "ChatServer.h"
#include <QObject>
#include <QtNetwork>
#include <QUdpSocket>
#include <QByteArray>
#include <QHostAddress>

ChatServer::ChatServer(QObject *parent) {
	udpSocket = new QUdpSocket(parent);
	udpSocket->bind(QHostAddress::LocalHost, 7755);

	parent->connect(udpSocket, SIGNAL(readyRead()), parent, SLOT(read()));
	
}
void ChatServer::read(){
	while (udpSocket->hasPendingDatagrams()){
		QByteArray datagram;
		datagram.resize(udpSocket->pendingDatagramSize());
		QHostAddress sender;
		quint16 senderPort;
		udpSocket->readDatagram(datagram.data(), datagram.size(), &sender, &senderPort);
		parent->nachricht(datagram);	
	}
	
}

ChatServer::~ChatServer() {
	// TODO Auto-generated destructor stub
}
