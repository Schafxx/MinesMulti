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
		QHostAddress *addr = new QHostAddress("0.0.0.0");
		udpSocket = new QUdpSocket(parent);
		udpSocket->bind(*addr, 7755);

		QObject::connect(udpSocket, SIGNAL(readyRead()), this, SLOT(read()));

	}
}
void ChatServer::read(){
	qDebug() << "test";
	while (udpSocket->hasPendingDatagrams()){
		qDebug() << "yes";
		QByteArray datagram;
		datagram.resize(udpSocket->pendingDatagramSize());
		//sender;
		//senderPort;
		udpSocket->readDatagram(datagram.data(), datagram.size(), &sender, &senderPort);
		emit rec(datagram);//
	}
	
}

void ChatServer::write(QByteArray *msg){
	qDebug() << sender;
	QHostAddress *addr = new QHostAddress("192.168.2.102");
	udpSocket->writeDatagram(*msg, *addr, 7755);
}

ChatServer::~ChatServer() {
	// TODO Auto-generated destructor stub
}
