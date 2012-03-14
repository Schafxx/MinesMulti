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
#include <QLabel>
#include <QLineEdit>
#include <QPoint>



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
                void Minerhalten(QByteArray m);
		void LOSE();
                void WIN();
                void crypt();
                void finden(int c, QPoint p);


        private:
                //QByteArray *QBA;
                QPushButton *bt, *bt2, *bt3, *bt4, *bt5;
                QLabel *lab;
		QTextBrowser *tb;
                QTextEdit *te, *te2;
                QLineEdit *le;
		Feld *Minen[10][10];
		ChatServer *cs;
		ChatClient *cc;
		GameServer *gs;
		GameClient *gc;
                //QTextDocument *doc;	
                bool ServerClient;
		int Mines;
		bool crypto;
                char *key;
};
#endif //MINEN_H
