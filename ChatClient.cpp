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
	parent->connect(udpSocket, SIGNAL(readyRead()), this, SLOT(readC()));

}

void ChatClient::read(){
     while (udpSocket->hasPendingDatagrams()) {
         QByteArray datagram;
         datagram.resize(udpSocket->pendingDatagramSize());
         QHostAddress sender;
         quint16 senderPort;

         udpSocket->readDatagram(datagram.data(), datagram.size(),
                                 &sender, &senderPort);

         parent->nachricht(datagram);
     }

}

void ChatClient::write(QByteArray msg){
	udpSocket->write(msg);
}

ChatClient::~ChatClient() {
	// TODO Auto-generated destructor stub
}
