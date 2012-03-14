
#ifndef CHATSERVER_H_
#define CHATSERVER_H_

#include <QtNetwork>
#include <QUdpSocket>
#include <QHostAddress>
#include <QByteArray>

class ChatServer : public QObject {
	Q_OBJECT
public:
	ChatServer(QObject *parent = 0,QString ip = "", bool a = false);
	virtual ~ChatServer();
	bool b;


public slots:
	void read();
	void write(QByteArray *msg);
private:
	QUdpSocket *udpSocket;

        QHostAddress sender;
        QHostAddress *addr;
signals:
	void rec(QByteArray D);
};

#endif /* CHATSERVER_H_ */
