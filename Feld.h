
#ifndef FELD_H_
#define FELD_H_
#include <QPushButton>
#include <QWidget>
#include <QMainWindow>
#include <QObject>
#include <QPoint>
class Feld : public QPushButton {
	Q_OBJECT

public:
	Feld(QWidget *parent);
	virtual ~Feld();
	bool legen;
	bool Mine;
	int Anzahl;
        bool aktiv;
	
signals:
	void Explosion();
        void notExplosion(int Anzahl, QPoint p);
public slots:
	void klick();
	void deaktivieren();
};

#endif /* FELD_H_ */
