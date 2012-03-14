

#include "Feld.h"
#include <QPushButton>
#include <QWidget>
#include <QDebug>
#include <QObject>


Feld::Feld(QWidget *parent = 0) : QPushButton(parent){
	legen = false;
        Anzahl = 0;
        aktiv = true;
        Mine = false;
}
void Feld::klick(){
    if (this->isEnabled()){
	if(legen){
		Mine = true;
		this->setText("M");
		this->setEnabled(false);
	}else{
            this ->setEnabled(false);
            aktiv = false;
		if(Mine){
			emit Explosion();
                        this->setText("X");
		}else{
                        this->setText(QString::number(Anzahl));
                        emit notExplosion(Anzahl, this->pos());

		}

	}
    }
}

void Feld::deaktivieren(){
	this->setEnabled(false);
        aktiv = false;
}

Feld::~Feld() {


}
