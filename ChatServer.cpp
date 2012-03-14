
#include "ChatServer.h"
#include <QObject>
#include <QtNetwork>
#include <QUdpSocket>
#include <QByteArray>
#include <QHostAddress>
#include <QDebug>

ChatServer::ChatServer(QObject *parent, QString ip, bool a) {//ip enthällt die IP-Adreses des Chatpartners
        b = a;
	if (a){
		udpSocket = new QUdpSocket(parent);
		addr = new QHostAddress(ip);
		udpSocket->bind(QHostAddress("0.0.0.0"), 7755); //Akzeptieren neuer Nachrichten von allen Adressen an Port 7755
		QObject::connect(udpSocket, SIGNAL(readyRead()), this, SLOT(read())); //Verbinden von Ausstehenden Nachrichten und der read-Methode

	}
}
void ChatServer::read(){

	while (udpSocket->hasPendingDatagrams()){
		QByteArray datagram;
		datagram.resize(udpSocket->pendingDatagramSize());
                quint16 senderPort;
                udpSocket->readDatagram(datagram.data(), datagram.size(), &sender, &senderPort);//Auslesen der Nachricht
		emit rec(datagram);//Benachrichtigen über neue Nachricht

	}
	
}

void ChatServer::write(QByteArray *msg){
	udpSocket->writeDatagram(*msg, *addr, 7755); //Schreiben der Nachricht msg an addr an Port 7755
}

ChatServer::~ChatServer() {

}
