
#include "GameClient.h"

GameClient::GameClient(QObject *parent, QString ip, bool a) {//ip, IP-Adresse, mit der sich verbunden werden soll

	b = a;
	if (a){
		udpSocket = new QUdpSocket(parent);;
                host = new QHostAddress(ip);
                udpSocket->bind(QHostAddress("0.0.0.0"), 7756);//Akzeptieren neuer Nachrichten von allen Adressen an Port 7756
                QObject::connect(udpSocket, SIGNAL(readyRead()), this, SLOT(read()));//Verbinden von Ausstehenden Nachrichten und der read-Methode
	}


}

void GameClient::read(){

    while (udpSocket->hasPendingDatagrams()) {
         QByteArray datagram;
         datagram.resize(udpSocket->pendingDatagramSize());
         quint16 senderPort;
         udpSocket->readDatagram(datagram.data(), datagram.size(),//Auslesen des Datagrams
                                 &sender, &senderPort);

         emit rec(datagram);//Benachrichtigen über neue Nachricht
    }

}

void GameClient::write(QByteArray *msg){
	udpSocket->writeDatagram(*msg, *host, 7756);
}

GameClient::~GameClient() {

}
