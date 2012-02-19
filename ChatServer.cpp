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
#include <QDebug>

ChatServer::ChatServer(QObject *parent, bool a) {
	b = a;
	if (a){
		udpSocket = new QUdpSocket(parent);
		udpSocket->bind(QHostAddress("0.0.0.0"), 7755);
		QObject::connect(udpSocket, SIGNAL(readyRead()), this, SLOT(read()));

	}
}
void ChatServer::read(){
	qDebug() << "read";
	while (udpSocket->hasPendingDatagrams()){
		QByteArray datagram;
		datagram.resize(udpSocket->pendingDatagramSize());
		//sender;
		//senderPort;
		udpSocket->readDatagram(datagram.data(), datagram.size(), &sender, &senderPort);
		emit rec(datagram);//

	}
	
}

void ChatServer::write(QByteArray *msg){
	qDebug() << "write";
	QHostAddress *addr = new QHostAddress("192.168.2.102");
	qDebug() << sender;
	udpSocket->writeDatagram(*msg, sender, 7755);
}

ChatServer::~ChatServer() {
	// TODO Auto-generated destructor stub
}
