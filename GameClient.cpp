/*
 * GameClient.cpp
 *
 *  Created on: 04.02.2012
 *      Author: julian
 */

#include "GameClient.h"

GameClient::GameClient(QObject *parent, QString ip, bool a) {
	// TODO Auto-generated constructor stub
	b = a;
	if (a){
		udpSocket = new QUdpSocket(parent);;
		host = new QHostAddress(ip);
		udpSocket->bind(QHostAddress("0.0.0.0"), 7756);
		QObject::connect(udpSocket, SIGNAL(readyRead()), this, SLOT(read()));
		//udpSocket->writeDatagram("",*host,7755);
	}


}

void GameClient::read(){
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

void GameClient::write(QByteArray *msg){
	qDebug() << "Client Write" << host;
	udpSocket->writeDatagram(*msg, *host, 7756);
}

GameClient::~GameClient() {
	// TODO Auto-generated destructor stub
}
