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
#include <QDebug>

ChatClient::ChatClient(QObject *parent, QString ip, bool a) {
	b = a;
	if (a){
		udpSocket = new QUdpSocket(parent);;
		host = new QHostAddress(ip);
		udpSocket->bind(*host, 7755);
		QObject::connect(udpSocket, SIGNAL(readyRead()), this, SLOT(read()));
		udpSocket->writeDatagram("",*host,5577);
	}

}

void ChatClient::read(){
	qDebug() << "test";
     while (udpSocket->hasPendingDatagrams()) {
         QByteArray datagram;
         datagram.resize(udpSocket->pendingDatagramSize());
         QHostAddress sender;
         quint16 senderPort;
         udpSocket->readDatagram(datagram.data(), datagram.size(),
                                 &sender, &senderPort);

         emit rec(datagram);
     }

}

void ChatClient::write(QByteArray *msg){

	udpSocket->writeDatagram(msg->data(), *host, 5577);
}

ChatClient::~ChatClient() {
	// TODO Auto-generated destructor stub
}
