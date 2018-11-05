#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QString>
#include <QScrollArea>
#include <QPushButton>
#include <vector>
using namespace std;

struct article
	{
		QString title;
		QString pic_url;
		QString content;
	};

namespace Ui {
	class Widget;
}
class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    int count=0;
	
	vector<struct article>passage;
	article temp;
    ~Widget();

private slots:
    void showTopArticle(int i);
    void showMidArticle(int i);
    void showBtmArticle(int i);
    void Renew();

    void on_backButton_5_clicked();

    void on_likeButton_5_clicked();

    void on_renew_clicked();

private:
    Ui::Widget *ui;

protected:
    void mouseMoveEvent(QMouseEvent *ev);

};

#endif // WIDGET_H
