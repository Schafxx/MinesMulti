
#include "ChatClient.h"
#include <QObject>
#include <QtNetwork>
#include <QUdpSocket>
#include <QByteArray>
#include <QHostAddress>
#include <QDebug>


ChatClient::ChatClient(QObject *parent, QString ip, bool a) {//ip, IP-Adresse, mit der sich verbunden werden soll
        b = a;                               //a gibt an ob es ausgeführt werden soll
	if (a){
		udpSocket = new QUdpSocket(parent);;       
		host = new QHostAddress(ip);
		udpSocket->bind(QHostAddress("0.0.0.0"), 7755); //Akzeptieren von Nachrichten von jeder beliebigen Adresse
		QObject::connect(udpSocket, SIGNAL(readyRead()), this, SLOT(read())); //verbinden vom Eingehen neuer Nachrichten und der read-Metjode

	}

}

void ChatClient::read(){

    while (udpSocket->hasPendingDatagrams()) {
         QByteArray datagram;
         datagram.resize(udpSocket->pendingDatagramSize());
         quint16 senderPort;
         udpSocket->readDatagram(datagram.data(), datagram.size(), //Auslesen des Datagrams
                                 &sender, &senderPort);

         emit rec(datagram); //Benachrichtigung über angekommende Nachricht
    }

}

void ChatClient::write(QByteArray *msg){

	udpSocket->writeDatagram(*msg, *host, 7755); //Verschicken eine rNachricht msg an host an Port 7755
}

ChatClient::~ChatClient() {
	// TODO Auto-generated destructor stub
}
