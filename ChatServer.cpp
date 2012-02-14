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

	parent->connect(udpSocket, SIGNAL(readyRead()), parent, SLOT(read(parent)));
	
}
QByteArray ChatServer::read(){
	while (udpSocket->hasPendingDatagrams()){
		QByteArray datagram;
		datagram.resize(udpSocket->pendingDatagramSize());
		QHostAddress sender;
		quint16 senderPort;
		udpSocket->readDatagram(datagram.data(), datagram.size(), &sender, &senderPort);
		return datagram;
	}
	
}

void ChatServer::write(QByteArray msg){
	udpSocket->write(msg);
}

ChatServer::~ChatServer() {
	// TODO Auto-generated destructor stub
}
