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
		udpSocket->bind(QHostAddress("0.0.0.0"), 7755);
		QObject::connect(udpSocket, SIGNAL(readyRead()), this, SLOT(read()));
		//udpSocket->writeDatagram("",*host,7755);
	}

}

void ChatClient::read(){
	qDebug() << "Client Read";
    while (udpSocket->hasPendingDatagrams()) {
         QByteArray datagram;
         datagram.resize(udpSocket->pendingDatagramSize());
         quint16 senderPort;
         udpSocket->readDatagram(datagram.data(), datagram.size(),
                                 &sender, &senderPort);

         emit rec(datagram);
    }

}

void ChatClient::write(QByteArray *msg){
	qDebug() << "Client Write" << host;
	udpSocket->writeDatagram(*msg, *host, 7755);
}

ChatClient::~ChatClient() {
	// TODO Auto-generated destructor stub
}
