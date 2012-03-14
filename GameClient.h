
#ifndef GAMECLIENT_H_
#define GAMECLIENT_H_

#include <QtNetwork>
#include <QUdpSocket>
#include <QHostAddress>

class GameClient : public QObject{
	Q_OBJECT
public:
	GameClient(QObject *parent = 0, QString ip = "", bool a = false);
	virtual ~GameClient();
	void write(QByteArray *msg);
	bool b;

public slots:
	void read();
private:
	QHostAddress *host;
	QUdpSocket *udpSocket;
        QHostAddress sender;
signals:
	void rec(QByteArray D);
};

#endif /* GAMECLIENT_H_ */
