#include "MinesMulti.h"
#include "GameServer.h"
#include "ChatServer.h"
#include <QPushButton>
#include <QTextBrowser>
#include <QTextEdit>
#include <QTextDocument>


MinesMulti::MinesMulti(QMainWindow *parent) : QMainWindow(parent){
    setupUi(this);
    bt = new QPushButton("Minenleger",this);
    bt2 = new QPushButton("Minensucher",this);
    bt->move(this->width()/2 - bt->width(), 10);
    bt2->move(this->width()/2, 10);

    tb = new QTextBrowser(this);
    tb->setVisible(false);
    tb->move(this->width()-300,0);
    tb->setFixedSize(300,800);

    te = new QTextEdit(this);
    te->setVisible(false);
    te->move(this->width()-300,810);
    te->setFixedSize(300,100);

    bt3 = new QPushButton("Senden",this);
    bt3->setVisible(false);
    bt3->move(this->width()-200,920);

    te2 = new QTextEdit(this);
    te2->setVisible(false);
    te2->move(this->width()/2-150,this->height()/2);
    te2->setFixedWidth(150);

    bt4 = new QPushButton("Verbinden",this);
    bt4->setVisible(false);
    bt4->move(this->width()/2+5,this->height()/2);

    for(int a = 0; a < 10; a++){
    	for(int b = 0; b < 10; b++){
    		Minen[a][b] = new QPushButton("",this);
    		Minen[a][b]->setFixedSize(50,50);
    		Minen[a][b]->move(a*50+50,b*50+50);
    		Minen[a][b]->setVisible(false);
    	}

    }

    connect(bt, SIGNAL(clicked()), this, SLOT(Server()));
    connect(bt2, SIGNAL(clicked()), this, SLOT(Client()));
    connect(bt3, SIGNAL(clicked()),this,SLOT(Senden()));
    connect(bt4, SIGNAL(clicked()),this,SLOT(Verbinden()));
}

void MinesMulti::Server(){
	bt->setVisible(false);
	bt2->setVisible(false);
	tb->setVisible(true);
	te->setVisible(true);
	bt3->setVisible(true);
	cs = new ChatServer(this);
}
void MinesMulti::Client(){
	bt->setVisible(false);
	bt2->setVisible(false);
	tb->setVisible(true);
	te->setVisible(true);
	bt3->setVisible(true);
	te2->setVisible(true);
	bt4->setVisible(true);
}

void MinesMulti::Senden(){

}

void MinesMulti::Verbinden(){

}

void MinesMulti::read(){
	cs->read();
}

void MinesMulti::FeldSichtbar(){
	for(int a = 0; a < 10; a++){
		for(int b = 0; b < 10; a++){
			Minen[a][b]->setVisible(true);
		}
	}
}

MinesMulti::~MinesMulti(){

}