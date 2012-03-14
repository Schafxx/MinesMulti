
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
        bool b;

public slots:
	void read();
        void write(QByteArray *msg);
private:
	QHostAddress *host;
	QUdpSocket *udpSocket;
        QHostAddress sender;
signals:
	void rec(QByteArray D);
};

#endif /* CHATCLIENT_H_ */
