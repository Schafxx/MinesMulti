#include "MinesMulti.h"
#include "GameServer.h"
#include "ChatServer.h"
#include "Feld.h"
#include <QPushButton>
#include <QTextBrowser>
#include <QTextEdit>
#include <QTextDocument>
#include <QLabel>


#include "osrng.h"
using CryptoPP::AutoSeededRandomPool;
#include "cryptlib.h"
#include "modes.h"
using CryptoPP::CFB_Mode;
#include "aes.h"
using CryptoPP::AES;

#include "filters.h"
using CryptoPP::StringSink;
using CryptoPP::StringSource;
using CryptoPP::StreamTransformationFilter;


#include <string>
using std::string;


MinesMulti::MinesMulti(QMainWindow *parent) : QMainWindow(parent){
    setupUi(this);

    lab = new QLabel(this);
    lab->move(10,10);
    lab->setVisible(true);

    bt = new QPushButton("Minenleger",this);
    bt2 = new QPushButton("Minensucher",this);
    bt->move(this->width()/2 - bt->width(), 10);
    bt2->move(this->width()/2, 10);

    tb = new QTextBrowser(this);
    tb->setVisible(false);
    tb->move(this->width()-400,0);
    tb->setFixedSize(300,400);

    te = new QTextEdit(this);
    te->setVisible(false);
    te->move(this->width()-400,410);
    te->setFixedSize(300,100);

    bt3 = new QPushButton("Senden",this);
    bt3->setVisible(false);
    bt3->move(this->width()-300,520);

    te2 = new QTextEdit(this);
    te2->setVisible(false);
    te2->move(this->width()/2-150,this->height()/2+200);
    te2->setFixedWidth(150);

    bt4 = new QPushButton("Verbinden",this);
    bt4->setVisible(false);
    bt4->move(this->width()/2+5,this->height()/2+200);

    for(int a = 0; a < 10; a++){
    	for(int b = 0; b < 10; b++){
    		Minen[a][b] = new Feld(this);
    		Minen[a][b]->setFixedSize(50,50);
    		Minen[a][b]->move(a*50+50,b*50+50);
    		Minen[a][b]->setVisible(false);
    		connect(Minen[a][b], SIGNAL(clicked()), Minen[a][b], SLOT(klick()));
    	}

    }

    connect(bt, SIGNAL(clicked()), this, SLOT(Server()));
    connect(bt2, SIGNAL(clicked()), this, SLOT(Client()));
    connect(bt3, SIGNAL(clicked()),this,SLOT(Senden()));
    connect(bt4, SIGNAL(clicked()),this,SLOT(Verbinden()));
    crypto = false;

    bt5 = new QPushButton("Crypto", this);
    bt5->move(this->width()/2+5,this->height()/2+230);
    bt5->setVisible(true);
    connect(bt5,SIGNAL(clicked()), this, SLOT(crypt()));

    le = new QLineEdit(this);
    le->move(this->width()/2-150,this->height()/2+230);
    le->setFixedWidth(150);
    le->setEchoMode(QLineEdit::Password);
}

void MinesMulti::Server(){
	bt->setVisible(false);
	bt2->setVisible(false);
	tb->setVisible(true);
	te->setVisible(true);
	bt3->setVisible(true);
	te2->setVisible(true);
	bt4->setVisible(true);
	//cs = new ChatServer(this,true);
	ServerClient = true;
	//cc = new ChatClient(this, te2->toPlainText(), false);
	//connect(cs, SIGNAL(rec(QByteArray)), this, SLOT(read(QByteArray)));
	FeldSichtbar();
	for (int a = 0; a < 10; a++){
		for (int b = 0; b < 10; b++){
			connect(Minen[a][b],SIGNAL(clicked()),this,SLOT(MineLegen()));
			Minen[a][b]->legen = true;
		}
	}
	Mines = 12;
}
void MinesMulti::Client(){
	bt->setVisible(false);
	bt2->setVisible(false);
	tb->setVisible(true);
	te->setVisible(true);
	bt3->setVisible(true);
	te2->setVisible(true);
	bt4->setVisible(true);
	ServerClient = false;
	//cs = new ChatServer(this,false);
}

void MinesMulti::Senden(){
	const char *text = te->toPlainText().toLatin1();
	if (crypto){
		char *textcrypto = const_cast<char*>(text);
		AutoSeededRandomPool rnd;
		byte iv[AES::BLOCKSIZE];
		rnd.GenerateBlock(iv, AES::BLOCKSIZE);
		int messageLen = (int)strlen(textcrypto) + 1;

                //char *key = "1234567812345678";
		CFB_Mode<AES>::Encryption cfbEncryption((byte*)key, 16, iv);
		cfbEncryption.ProcessData((byte*)textcrypto, (byte*)textcrypto, messageLen);

		QBA = new QByteArray(textcrypto);

	}else{
		QBA = new QByteArray(text);
	}
	if (cs->b){
		cs->write(QBA);
	}
	if (cc->b){
		cc->write(QBA);
	}
	te->clear();
}

void MinesMulti::Verbinden(){
	te2->setVisible(false);
	bt4->setVisible(false);
	if (!ServerClient){
		cc = new ChatClient(this, te2->toPlainText(), true);
		cs = new ChatServer(this, te2->toPlainText(), false);
		gc = new GameClient(this, te2->toPlainText(), true);
		gs = new GameServer(this, te2->toPlainText(), false);
		connect(cc, SIGNAL(rec(QByteArray)), this,SLOT(read(QByteArray)));
                connect(gc, SIGNAL(rec(QByteArray)), this, SLOT(Minerhalten(QByteArray)));
	}else{
		cc = new ChatClient(this, te2->toPlainText(), false);
		cs = new ChatServer(this, te2->toPlainText(), true);
		gc = new GameClient(this, te2->toPlainText(), false);
		gs = new GameServer(this, te2->toPlainText(), true);
		connect(cs, SIGNAL(rec(QByteArray)), this, SLOT(read(QByteArray)));
                connect(gs,SIGNAL(rec(QByteArray)), this, SLOT(Minerhalten(QByteArray)));
	}
}

void MinesMulti::read(QByteArray D){
    QString *t = new QString(D);
    const char* text = t->toLatin1();
        if(crypto){
            char* textcrypto = const_cast<char*>(text);
            AutoSeededRandomPool rnd;
            byte iv[AES::BLOCKSIZE];
            rnd.GenerateBlock(iv, AES::BLOCKSIZE);
            int messageLen = (int)strlen(textcrypto)+1;


            CFB_Mode<AES>::Decryption cfbDecryption((byte*)key, 16, iv);
            cfbDecryption.ProcessData((byte*)textcrypto, (byte*)textcrypto, messageLen);
            tb->append(QString(textcrypto));
	}else{
		tb->append(D);
	}
}


void MinesMulti::FeldSichtbar(){
	for(int a = 0; a < 10; a++){
		for(int b = 0; b < 10; b++){
			Minen[a][b]->setVisible(true);
		}
	}
}

void MinesMulti::nachricht(QByteArray msg){
	tb->append(QString(msg));
}

void MinesMulti::MineLegen(){
	if (Mines > 0){
                lab->setText(QString::number(Mines));
		Mines--;
	}else{
		QByteArray *Q = new QByteArray();
		for (int a = 0; a < 10; a++){
			for (int b = 0; b < 10; b++){
				if(!Minen[a][b]->isEnabled()){
					Q->append("b");
				}else{
					Q->append("n");
				}
				Minen[a][b]->deaktivieren();
			}
		}
		gs->write(Q);
		
		
	}
}

void MinesMulti::Minerhalten(QByteArray m){
    qDebug() << m;
    int test;
    if(m == QByteArray("WIN")){
        test = 1;
    }
    if(m == QByteArray("LOSE")){
        test = 2;
    }


    switch(test){
    case 1:
        this->WIN();
        break;
    case 2:
        this->LOSE();
        break;
    default:
        FeldSichtbar();
        Mines = (11*11)-12;
        lab->setText(QString::number(Mines));
	QString m2 = QString(m);
	int c = 0;
	for(int a = 0; a < 10; a++){
		for(int b = 0; b < 10; b++){
			if(m2[c] == QChar(98)){
				Minen[a][b]->Mine = true;
				connect(Minen[a][b], SIGNAL(Explosion()), this, SLOT(LOSE()));
			}else{
				try{
					if(m2.at(c+1) == QChar(98)){
						Minen[a][b]->Anzahl++;
					}
				}catch(...){

				}try{
					if(m2.at(c+11) == QChar(98)){
						Minen[a][b]->Anzahl++;
					}
				}catch(...){

				}try{
					if(m2.at(c+10) == QChar(98)){
						Minen[a][b]->Anzahl++;
					}
				}catch(...){

				}try{
					if(m2.at(c+9) == QChar(98)){
						Minen[a][b]->Anzahl++;
					}
				}catch(...){

				}try{
					if(m2.at(c-1) == QChar(98)){
						Minen[a][b]->Anzahl++;
					}
				}catch(...){

				}try{
					if(m2.at(c-11) == QChar(98)){
						Minen[a][b]->Anzahl++;
					}
				}catch(...){

				}try{
					if(m2.at(c-10) == QChar(98)){
						Minen[a][b]->Anzahl++;
					}
				}catch(...){

				}try{
					if(m2.at(c-9) == QChar(98)){
						Minen[a][b]->Anzahl++;
					}
				}catch(...){

				}
                            connect(Minen[a][b],SIGNAL(notExplosion()),this,SLOT(finden()));

			}
			c++;
		}
	}
        break;
    }
}

void MinesMulti::finden(){
    Mines--;
    lab->setText(QString::number(Mines));

}

void MinesMulti::LOSE(){
    lab->setText("You have lost the game!");
}

void MinesMulti::WIN(){
    lab->setText("You have won the game!");
}

void MinesMulti::crypt(){
    if(le->text().length()%8 == 0 && le->text().length() >7){
        crypto = true;
        const char* key_const;
        QString q = le->text();
        key_const = (const char*) q.toAscii();
        key = const_cast<char*>(key_const);
        le->setVisible(false);
        bt5->setVisible(false);
    }
}

MinesMulti::~MinesMulti(){

}
