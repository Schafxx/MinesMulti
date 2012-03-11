#include "MinesMulti.h"
#include "GameServer.h"
#include "ChatServer.h"
#include "Feld.h"
#include <QPushButton>
#include <QTextBrowser>
#include <QTextEdit>
#include <QTextDocument>
#include <QLabel>
#include <QFile>
#include <QTextStream>


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
    setupUi(this); //Erstellen des GUIs

    lab = new QLabel(this); //enthällt Nachricht über Ausstehende Minen/Felder ohne Mienen entdeckt und Sieg/Niederlage
    lab->move(10,10);
    lab->setVisible(true);

    bt = new QPushButton("Minenleger",this); //Auswahl des Spielermodus
    bt2 = new QPushButton("Minensucher",this);
    bt->move(this->width()/2 - bt->width(), 10);
    bt2->move(this->width()/2, 10);

    tb = new QTextBrowser(this); //Chat-Ausgabe
    tb->setVisible(false);
    tb->move(this->width()-400,0);
    tb->setFixedSize(300,400);

    te = new QTextEdit(this); //Chat-Eingabe
    te->setVisible(false);
    te->move(this->width()-400,410);
    te->setFixedSize(300,100);

    bt3 = new QPushButton("Senden",this); //Nachricht verschicken
    bt3->setVisible(false);
    bt3->move(this->width()-300,520);

    te2 = new QTextEdit(this); //Eingabefeld für die IP-Adresse
    te2->setVisible(false);
    te2->move(this->width()/2-150,this->height()/3);//+200
    te2->setFixedWidth(150);

    bt4 = new QPushButton("Verbinden",this); //Verbinden mit Rechner mit eingetragener IP-Adresse
    bt4->setVisible(false);
    bt4->move(this->width()/2+5,this->height()/3);//+200

    for(int a = 0; a < 10; a++){ //Erstellen des Minenfelds(Prototyp ohne Minen)
    	for(int b = 0; b < 10; b++){
    		Minen[a][b] = new Feld(this); 
    		Minen[a][b]->setFixedSize(50,50);
    		Minen[a][b]->move(a*50+50,b*50+50);
    		Minen[a][b]->setVisible(false);
    		connect(Minen[a][b], SIGNAL(clicked()), Minen[a][b], SLOT(klick())); // verbinden des clicked Signals und dem Slot klick des Feldes
    	}

    }

    connect(bt, SIGNAL(clicked()), this, SLOT(Server()));//Verbinden der Buttons mit den dazugehörigen Methoden(Slots)
    connect(bt2, SIGNAL(clicked()), this, SLOT(Client()));
    connect(bt3, SIGNAL(clicked()),this,SLOT(Senden()));
    connect(bt4, SIGNAL(clicked()),this,SLOT(Verbinden()));
    crypto = false; //Standartwert für verschlüsselten Chat (true=verschlüsselt)

    bt5 = new QPushButton("Crypto", this); //Anwenden des eingegebenen Passworts für Verschlüsselung des Textes
    bt5->move(this->width()/2+5,this->height()/2+230);
    bt5->setVisible(true);
    connect(bt5,SIGNAL(clicked()), this, SLOT(crypt()));

    le = new QLineEdit(this); //Eingabefeld für das Passwort
    le->move(this->width()/2-150,this->height()/2+230);
    le->setFixedWidth(150);
    le->setEchoMode(QLineEdit::Password);
}

void MinesMulti::Server(){
	bt->setVisible(false); //Auswahl der sichtbaren Module in dem Spielmodus
	bt2->setVisible(false);
	tb->setVisible(true);
	te->setVisible(true);
	bt3->setVisible(true);
	te2->setVisible(true);
	bt4->setVisible(true);
        ServerClient = true; //ServerClient = true bedeutet Server; ServerClient = false bedeutet Client
	FeldSichtbar();
	for (int a = 0; a < 10; a++){ //Verbinden des Klicks und der Methode MineLegen
		for (int b = 0; b < 10; b++){
			connect(Minen[a][b],SIGNAL(clicked()),this,SLOT(MineLegen()));
			Minen[a][b]->legen = true;
		}
	}
        Mines = 13; //13 Minen sind legbar
}
void MinesMulti::Client(){
	//Gestaltung des GUIS für den Minensucher
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
	const char *text = te->toPlainText().toLatin1(); //Konvertieren des zu sendenden textes für die Verschlüsselung
	if (crypto){
		char *textcrypto = const_cast<char*>(text); //deaktivieren der Konstanten-Eigenschaft
		AutoSeededRandomPool rnd;
		byte iv[AES::BLOCKSIZE];
		rnd.GenerateBlock(iv, AES::BLOCKSIZE);
		int messageLen = (int)strlen(textcrypto) + 1;

                //char *key = "1234567812345678";
		CFB_Mode<AES>::Encryption cfbEncryption((byte*)key, 16, iv);
		cfbEncryption.ProcessData((byte*)textcrypto, (byte*)textcrypto, messageLen); //AES-verschlüsselung anwenden

		QBA = new QByteArray(textcrypto);

	}else{
		QBA = new QByteArray(text);
	}
	if (cs->b){

		cs->write(QBA); //Verschicken des versclüsselten/unverschlüsselten Textes als Server(Minenleger)

	}
	if (cc->b){

		cc->write(QBA);//Verschicken des versclüsselten/unverschlüsselten Textes als Client(Minensucher)
	}
	te->clear();
}

void MinesMulti::Verbinden(){
	te2->setVisible(false);
	bt4->setVisible(false);
	if (!ServerClient){ //Client erstellen
		cc = new ChatClient(this, te2->toPlainText(), true);
		cs = new ChatServer(this, te2->toPlainText(), false);
		gc = new GameClient(this, te2->toPlainText(), true);
		gs = new GameServer(this, te2->toPlainText(), false);
                connect(cc, SIGNAL(rec(QByteArray)), this,SLOT(read(QByteArray))); //Verbinden des Erhaltens einer Nchricht und der Anzeige
                connect(gc, SIGNAL(rec(QByteArray)), this, SLOT(Minerhalten(QByteArray))); // Verbinden des Erhaltens einer Spielinformation und der Verarbeitung
	}else{ //Server ertsellen
		cc = new ChatClient(this, te2->toPlainText(), false);
		cs = new ChatServer(this, te2->toPlainText(), true);
		gc = new GameClient(this, te2->toPlainText(), false);
		gs = new GameServer(this, te2->toPlainText(), true);
                connect(cs, SIGNAL(rec(QByteArray)), this, SLOT(read(QByteArray)));//Verbinden des Erhaltens einer Nchricht und der Anzeige
                connect(gs,SIGNAL(rec(QByteArray)), this, SLOT(Minerhalten(QByteArray))); // Verbinden des Erhaltens einer Spielinformation und der Verarbeitung
	}
}

void MinesMulti::read(QByteArray D){ //Erhalten einer Nachricht
    QFile file("log");
    if (!file.open(QIODevice::Append | QIODevice::Text)) //Öffnen der Datei mit dem Modus "Append"
         return;

     QTextStream out(&file); //Textstream an Datei binden


    QString *t = new QString(D);
    const char* text = t->toLatin1();
        if(crypto){//Entschlüsseln der Nachricht
            char* textcrypto = const_cast<char*>(text); //Präparieren der Daten zum Entschlüsseln
            AutoSeededRandomPool rnd;
            byte iv[AES::BLOCKSIZE];
            rnd.GenerateBlock(iv, AES::BLOCKSIZE);
            int messageLen = (int)strlen(textcrypto)+1;


            CFB_Mode<AES>::Decryption cfbDecryption((byte*)key, 16, iv);
            cfbDecryption.ProcessData((byte*)textcrypto, (byte*)textcrypto, messageLen);

            tb->append(QString(textcrypto));
            out << QString(textcrypto) << "\n";
	}else{
		tb->append(D);
                out << QString(D) << "\n";
	}
        file.close();
}


void MinesMulti::FeldSichtbar(){//Spielfeld sichtbar machen
	for(int a = 0; a < 10; a++){
		for(int b = 0; b < 10; b++){
			Minen[a][b]->setVisible(true);
		}
	}
}


void MinesMulti::MineLegen(){
	if (Mines > 0){
                lab->setText(QString::number(Mines)); //Anzeige verbleibender Minen
                Mines--;
	}else{
		QByteArray *Q = new QByteArray();
                for (int a = 0; a < 10; a++){ //Erstellen der Spielinformation, welche angibt, wo Minen liegen
			for (int b = 0; b < 10; b++){
				if(!Minen[a][b]->isEnabled()){
					Q->append("b");
				}else{
					Q->append("n");
				}
				Minen[a][b]->deaktivieren();
			}
		}
                gs->write(Q); //Verschicken des Spielfeldes
		
		
	}
}

void MinesMulti::Minerhalten(QByteArray m){
    qDebug() << m;
    int test = 0;
    if(m == QByteArray("WIN")){ //Präparieren der Spielinformation für die Verarbeitung
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
    default: //Feldinformationen auf Spielfeld übertragen
        FeldSichtbar();
        Mines = (11*11)-13;
        lab->setText(QString::number(Mines)); //Anzeige verbleibender freier Felder
	QString m2 = QString(m);
	int c = 0;

	for(int a = 0; a < 10; a++){
		for(int b = 0; b < 10; b++){
			if(m2[c] == QChar(98)){
				Minen[a][b]->Mine = true;
                                connect(Minen[a][b], SIGNAL(Explosion()), this, SLOT(LOSE())); // Klick auf Mine führt zur Niederlage
                        }else{ //Anzahl benachbarter Minen erkennen; Auffalngen der Exceptions, die durch fehlende Felder (außerhalb des Spielfeldes) ausgelöst werden
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
                            connect(Minen[a][b],SIGNAL(notExplosion(int, QPoint)),this,SLOT(finden(int, QPoint)));

			}
			c++;
		}
	}
        break;
    }
}

void MinesMulti::finden(int c, QPoint p){
    Mines--;//verbleibende freie Felder werden runtergezählt
    lab->setText(QString::number(Mines));
    if (Mines == 0){
        this->WIN();
    }
    int a = 0;
    int b = 0;
    if (c == 0){
        a = (p.x()-50)/50;
        b = (p.y()-50)/50;
        qDebug() << a << b;
        if(a>=-1 && b >= 0 && (a+1)<10 && b <10){
            if(Minen[a+1][b]->isEnabled())
            Minen[a+1][b]->klick();
        }
        if(a>0 && b > 0 && (a-1)<10 && (b-1) <10){
            if(Minen[a-1][b-1]->isEnabled())
            Minen[a-1][b-1]->klick();
        }
        if(a >0 && b >= 0 && (a-1)<10 && b <10){
            if(Minen[a-1][b]->isEnabled())
            Minen[a-1][b]->klick();
        }
        if(a > 0 && b >= -1 && (a-1)<10 && (b+1) <10){
            if(Minen[a-1][b+1]->isEnabled())
            Minen[a-1][b+1]->klick();
        }
        if(a >= -1 && b > 0 && (a+1)<10 && (b-1) <10){
            if(Minen[a+1][b-1]->isEnabled())
            Minen[a+1][b-1]->klick();
        }
        if(a >= 0 && b >= -1 && (a)<10 && (b+1) <10){
            if(Minen[a][b+1]->isEnabled())
            Minen[a][b+1]->klick();
        }
        if(a >=-1 && b >= 0 && (a+1)<10 && b <10){
            if(Minen[a+1][b]->isEnabled())
            Minen[a+1][b]->klick();
        }

        if(a >= -1 && b>=-1){
            if(Minen[a+1][b+1]->isEnabled())
            Minen[a+1][b+1]->klick();
        }
    }

}

void MinesMulti::LOSE(){
    lab->setText("You have lost the game!");
    QByteArray *w = new QByteArray("WIN");
    if (ServerClient){ //Senden der Information des eigenen Verlierens an den anderen Spieler
        gs->write(w);
    } else {
        gc->write(w);
    }
}

void MinesMulti::WIN(){
    lab->setText("You have won the game!");
    QByteArray *l = new QByteArray("LOSE");
    if(ServerClient){ //Senden der Information des eigenen Gewinnens an den anderen Spieler
        gs->write(l);
    }else{
        gc->write(l);
    }
}

void MinesMulti::crypt(){ //Passworteingabe auslesen
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
