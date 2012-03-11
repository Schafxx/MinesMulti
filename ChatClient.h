
#ifndef CHATCLIENT_H_
#define CHATCLIENT_H_

#include <QtNetwork>
#include <QUdpSocket>
#include <QHostAddress>

class ChatClient : public QObject{
	Q_OBJECT
public:
	ChatClient(QObject *parent = 0, QString ip = "", bool a = false);
	virtual ~ChatClient();
	void write(QByteArray *msg);
	bool b;
	QHostAddress sender;
public slots:
	void read();
private:
	QHostAddress *host;
	QUdpSocket *udpSocket;
signals:
	void rec(QByteArray D);
};

#endif /* CHATCLIENT_H_ */
