#include "MinesMulti.h"
#include <QApplication>

int main(int argc, char* argv[]){
	QApplication a(argc, argv);
	MinesMulti w;
	w.show();
	return a.exec();
}
