/*
 * Feld.h
 *
 *  Created on: 04.02.2012
 *      Author: julian
 */

#ifndef FELD_H_
#define FELD_H_
#include <QPushButton>
#include <QWidget>
#include <QMainWindow>
#include <QObject>
class Feld : public QPushButton {
	Q_OBJECT

public:
	Feld(QWidget *parent);
	virtual ~Feld();
	bool legen;
	bool Mine;
	int Anzahl;
	
signals:
	void Explosion();
        void notExplosion();
public slots:
	void klick();
	void deaktivieren();
};

#endif /* FELD_H_ */
