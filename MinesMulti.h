#ifndef MINEN_H
#define MINEN_H

#include "ui_MinesMulti.h"
#include "ChatServer.h"
#include "ChatClient.h"
#include "GameServer.h"
#include "GameClient.h"
#include "Feld.h"
#include <QPushButton>
#include <QTextBrowser>
#include <QTextEdit>
#include <QTextDocument>

class MinesMulti : public QMainWindow, public Ui::MainWindow{
	Q_OBJECT

	public:
		MinesMulti(QMainWindow *parent = 0);
		~MinesMulti();
	private slots:
		void Server();
		void Client();
		void Senden();
		void FeldSichtbar();
		void Verbinden();
		void read(QByteArray D);
		void MineLegen();
		//void readC(QByteArray D);

	public:
		void nachricht(QByteArray msg);
		QByteArray *QBA;
		QPushButton *bt, *bt2, *bt3, *bt4;
		QTextBrowser *tb;
		QTextEdit *te, *te2;
		Feld *Minen[10][10];
		ChatServer *cs;
		ChatClient *cc;
		QTextDocument *doc;
		bool ServerClient;
};
#endif //MINEN_H
