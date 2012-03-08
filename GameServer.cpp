/*
 * GameServer.cpp
 *
 *  Created on: 04.02.2012
 *      Author: julian
 */

#include "GameServer.h"

GameServer::GameServer(QObject *parent, QString ip, bool a) {
	b = a;
	if (a){
		udpSocket = new QUdpSocket(parent);
		addr = new QHostAddress(ip);
		udpSocket->bind(QHostAddress("0.0.0.0"), 7756);
		QObject::connect(udpSocket, SIGNAL(readyRead()), this, SLOT(read()));

	}

}

void GameServer::read(){
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

void GameServer::write(QByteArray *msg){
    qDebug() << "write" << addr;
	//QHostAddress *addr = new QHostAddress("192.168.2.102");
	//qDebug() << sender;
	udpSocket->writeDatagram(*msg, *addr, 7756);
}


GameServer::~GameServer() {
	// TODO Auto-generated destructor stub
}
