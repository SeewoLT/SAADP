#pragma execution_character_set("utf-8")
#include <QApplication>
#include <QDebug>

#include "boardThread.h"
#include "widget.h"

int c = 0;

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

    Widget w;
	/*
	!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	*/
	BoardThread *passageBoard = new BoardThread();
	passageBoard->setWidget(w);
	passageBoard->start();
	/*
	!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	*/

    
    w.show();

	return a.exec();
}
