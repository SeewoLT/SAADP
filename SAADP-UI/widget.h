#pragma execution_character_set("utf-8")
#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QString>
#include <QScrollArea>
#include <QPushButton>
#include <vector>
using namespace std;

struct Article
	{
		QString title;
		QString pic_url;
		QString content;
		bool isLike = false;
		bool inlike = false;
		bool inRecent = false;
	};

namespace Ui {
	class Widget;
}
class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    int count = 0;
	int passagenum = 0;
	int nowpassage[3] = { 0 };

	vector<struct Article>passages;
	vector<struct Article>recentViews;
	vector<struct Article>likedPassages;

	Article tempArticle;
	void AddArticle();

	QWidget *topWidget, *midWidget, *btmWidget;
	QPushButton *topArticleBtn, *midArticleBtn, *btmArticleBtn;

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
