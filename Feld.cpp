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
			this->setText(QString(Anzahl));
			//emit notExplosion(Anzahl);
		}
	}
}

void Feld::deaktivieren(){
	this->setEnabled(false);
}

Feld::~Feld() {
	// TODO Auto-generated destructor stub

}
