#pragma once
#include <QThread>

#include "widget.h"

class BoardThread :
	public QThread
{
public:
	BoardThread();
	~BoardThread();

	void run();
	void setWidget(Widget &w);

private:
	Widget *w;

};

