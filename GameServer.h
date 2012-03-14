

#ifndef GAMESERVER_H_
#define GAMESERVER_H_


#include <QtNetwork>
#include <QUdpSocket>
#include <QHostAddress>
#include <QByteArray>

class GameServer : public QObject{
	Q_OBJECT
public:
	GameServer(QObject *parent = 0, QString ip = "", bool a=false);
	virtual ~GameServer();
	bool b;
private:
	QHostAddress sender;
	QHostAddress *addr;
public slots:
	void read();
	void write(QByteArray *msg);
private:
	QUdpSocket *udpSocket;
signals:
	void rec(QByteArray D);

};

#endif /* GAMESERVER_H_ */
