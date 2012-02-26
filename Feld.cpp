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

	// TODO Auto-generated constructor stub

}
void Feld::klick(){
	Mine = true;
	this->setText("M");
	this->setEnabled(false);
}

void Feld::deaktivieren(){
	this->setEnabled(false);
}

Feld::~Feld() {
	// TODO Auto-generated destructor stub

}
