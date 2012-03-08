/*
 * Feld.cpp
 *
 *  Created on: 04.02.2012
 *      Author: julian
 */

#include "Feld.h"
#include <QPushButton>
#include <QWidget>
#include <QDebug>
#include <QObject>
Feld::Feld(QWidget *parent = 0) : QPushButton(parent){
	legen = false;
        Anzahl = 0;
	// TODO Auto-generated constructor stub

}
void Feld::klick(){
	if(legen){
		Mine = true;
		this->setText("M");
		this->setEnabled(false);
	}else{
		if(Mine){
			emit Explosion();
		}else{
                        this->setText(QString::number(Anzahl));
                        emit notExplosion();
		}
		this ->setEnabled(false);
	}
}

void Feld::deaktivieren(){
	this->setEnabled(false);
}

Feld::~Feld() {
	// TODO Auto-generated destructor stub

}
