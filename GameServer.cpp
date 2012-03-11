

#include "GameServer.h"

GameServer::GameServer(QObject *parent, QString ip, bool a) {//ip, IP-Adresse, mit der sich verbunden werden soll
	b = a;
	if (a){
		udpSocket = new QUdpSocket(parent);
		addr = new QHostAddress(ip);
                udpSocket->bind(QHostAddress("0.0.0.0"), 7756);//Akzeptieren neuer Nachrichten von allen Adressen an Port 7756
                QObject::connect(udpSocket, SIGNAL(readyRead()), this, SLOT(read()));//Verbinden von Ausstehenden Nachrichten und der read-Methode

	}

}

void GameServer::read(){
	qDebug() << "read";
	while (udpSocket->hasPendingDatagrams()){
		QByteArray datagram;
		datagram.resize(udpSocket->pendingDatagramSize());

                udpSocket->readDatagram(datagram.data(), datagram.size(), &sender, &senderPort);//Auslesen des Datagrams
                emit rec(datagram);//Benachrichtigen über neue Nachricht

	}

}

void GameServer::write(QByteArray *msg){

        udpSocket->writeDatagram(*msg, *addr, 7756);//Schreiben der Nachricht msg an addr an Port 7756
}


GameServer::~GameServer() {
}
