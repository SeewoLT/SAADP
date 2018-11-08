#include "widget.h"
#include "ui_widget.h"
#include <QDesktopWidget>
#include <QScrollArea>
#include <QPushButton>
#include <QSignalMapper>
#include <QScrollBar>
#include <QMouseEvent>
#include <QPropertyAnimation>
#include <QString>
#include <QTimer>

#include <QDebug>

#include <iostream>

#include "common/example_utilities.h"
#include "..\Implement\Entities.cpp"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
	setFixedSize(680, 780);

    QTimer *time = new QTimer(this);
    connect(time, &QTimer::timeout, this, &Widget::Renew);
    time->start(1000);


    //窗体居中显示
    QDesktopWidget *desktop = QApplication::desktop();
    move((desktop->width() - this->width())/2, (desktop->height() - this->height())/4);

    ui->articlename->setAlignment(Qt::AlignCenter);

    QString scrollstyle1 = "QScrollBar"
                              "{"
                              "    width: 12px;"
                              "    border: none;"
                              "}"
                              "QScrollBar::handle"
                              "{"
                              "    width: 12px;"
                              "    background-color: rgba(0, 0, 0, 0.25);"
                              "    border-radius: 6px;"
                              "}"
                              "QScrollBar::handle:hover"
                              "{"
                              "    height: 12px;"
                              "    width: 12px;"
                              "    background-color: rgba(50, 50, 50, 0.5);"
                              "    border-radius: 6px;"
                              "}"
                              "QScrollBar::handle:pressed"
                              "{"
                              "    height: 12px;"
                              "    width: 12px;"
                              "    background-color: rgba(50, 50, 50, 0.7);"
                              "    border-radius: 6px;"
                              "}"
                              "QScrollBar::add-line"
                              "{"
                              "    width: 12px;"
                              "    background: transparent;"
                              "    subcontrol-position: right;"
                              "    subcontrol-origin: margin;"
                              "}"
                              "QScrollBar::sub-line"
                              "{"
                              "    width: 12px;"
                              "    background: transparent;"
                              "    subcontrol-position: left;"
                              "    subcontrol-origin: margin;"
                              "}"
                              "QScrollBar::add-page, QScrollBar::sub-page{background:none;}";

    ui->contentView->verticalScrollBar()->setStyleSheet(scrollstyle1);

    ui->likeButton_5->setStyleSheet("QPushButton{border-image:url(:/new/Image/xin.png);}");
    ui->backButton_5->setStyleSheet("QPushButton{border:none;}"
                                    "QPushButton:hover{font:bold; font-size:21pt;}");

    QPalette pl = ui->contentView->palette();
    pl.setBrush(QPalette::Base,QBrush(QColor(255,0,0,0)));
    ui->contentView->setPalette(pl);
    ui->contentView->setStyleSheet("border:none;");
    ui->contentView->setReadOnly(true);

    //这是示例
    QString address;
    address="C:\\Users\\evelyn\\Desktop\\111.jpg";
    ui->articlename->setText("这是标题");
    ui->contentView->setText("前几天，有间书店开业，邀请我去做了一场读书活动，为开业加点气氛，我去了，大言不惭地讲了些我的读书心得，怎么开始阅读的，怎样做笔记，哪些读书媒体值得注意，等等。讲话的过程中，我注意到第一排坐着一个年轻女孩，一直保持着一种不屑的目光，打量着我，使我非常心虚。到了交流环节，她开口提问了：我是理科生，你讲的这些书和作家我都没听过，也没兴趣知道，我不知道这些和我们的生活有什么关系，据我所知，很多人都和我一样，你怎么才能让这些人对这些内容感兴趣？我回答了些什么，我不大记得了，只记得一段：你不看这些书和电影，并不是我的损失。你对这些内容没有好奇心，我也觉得不要紧，不过，我倒很好奇，你都读些什么看些什么？哪怕是你专业领域的，能否给我们大家推荐一些？她没有回答。是啊，你不了解文学之美电影之美，不是别人的损失。你把文艺和生活理解为两个敌对的阵营，也不是别人的损失，文艺照样在自顾自发展着，能欣赏的人照样在欣赏，像《红楼梦》里黛玉对宝玉说的：咱们只管乐咱们的顾自发展着，能欣赏的人照样在欣赏，像《红楼梦》里黛玉对宝玉说的：咱们只管乐咱们的");
    QImage img(address);
    ui->articleImg->setScaledContents(true);
    ui->articleImg->setPixmap(QPixmap::fromImage(img));
    ui->articleImg->setText("Image");
    ui->renew->setStyleSheet("QPushButton{border-image:url(:/new/Image/new.png);}");



    //激活鼠标跟踪
    setMouseTracking(true);
    ui->mainpage->setMouseTracking(true);
    ui->stackedWidget->setMouseTracking(true);
    ui->topBg->setMouseTracking(true);
    ui->midBg->setMouseTracking(true);
    ui->btmBg->setMouseTracking(true);
    ui->topLabel->setMouseTracking(true);
    ui->midLabel->setMouseTracking(true);
    ui->btmLabel->setMouseTracking(true);
    ui->label->setMouseTracking(true);

    ui->topBg->setStyleSheet("background-color: #f8bd5f");
    ui->label_2->hide();
    ui->label_3->hide();


    QString scrollstyle = "QScrollBar"
                          "{"
                          "    height: 12px;"
                          "    background-color: transparent;"
                          "}"
                          "QScrollBar::handle"
                          "{"
                          "    height: 12px;"
                          "    background-color: rgba(0, 0, 0, 0.25);"
                          "    border-radius: 6px;"
                          "}"
                          "QScrollBar::handle:hover"
                          "{"
                          "    height: 12px;"
                          "    width: 12px;"
                          "    background-color: rgba(50, 50, 50, 0.5);"
                          "    border-radius: 6px;"
                          "}"
                          "QScrollBar::handle:pressed"
                          "{"
                          "    height: 12px;"
                          "    width: 12px;"
                          "    background-color: rgba(50, 50, 50, 0.7);"
                          "    border-radius: 6px;"
                          "}"
                          "QScrollBar::add-line"
                          "{"
                          "    width: 12px;"
                          "    background: transparent;"
                          "    subcontrol-position: right;"
                          "    subcontrol-origin: margin;"
                          "}"
                          "QScrollBar::sub-line"
                          "{"
                          "    width: 12px;"
                          "    background: transparent;"
                          "    subcontrol-position: left;"
                          "    subcontrol-origin: margin;"
                          "}"
                          "QScrollBar::add-page, QScrollBar::sub-page{background:none;}";



//top部分
{
    //定义滑动区域
    ui->topScrollArea->setMouseTracking(true); //激活鼠标跟踪
    ui->topScrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->topScrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    ui->topScrollArea->setFrameShape(QFrame::NoFrame);

    //滑动区设为透明
    ui->topScrollArea->setStyleSheet("QScrollArea {background-color:transparent};");
    ui->topScrollArea->viewport()->setStyleSheet("background-color: transparent;");

    //设置滚动条样式
    ui->topScrollArea->horizontalScrollBar()->setStyleSheet(scrollstyle);

    
}


//mid部分
{
    //定义滑动区域
    ui->midScrollArea->setMouseTracking(true); //激活鼠标跟踪
    ui->midScrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->midScrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    ui->midScrollArea->setFrameShape(QFrame::NoFrame);

    //滑动区设为透明
    ui->midScrollArea->setStyleSheet("QScrollArea {background-color:transparent;}");
    ui->midScrollArea->viewport()->setStyleSheet("background-color:transparent;");

    //设置滚动条样式
    ui->midScrollArea->horizontalScrollBar()->setStyleSheet(scrollstyle);

    //中部Widget,以topScrollArea为父窗口
    midWidget = new QWidget(ui->midScrollArea);
    ui->midScrollArea->setWidget(midWidget);
    midWidget->setMouseTracking(true); //激活鼠标跟踪
}


//btm部分
{
    //定义滑动区域
    ui->btmScrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->btmScrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    ui->btmScrollArea->setFrameShape(QFrame::NoFrame);
    ui->btmScrollArea->setMouseTracking(true); //激活鼠标跟踪

    //滑动区设为透明
    ui->btmScrollArea->setStyleSheet("QScrollArea {background-color:transparent;}");
    ui->btmScrollArea->viewport()->setStyleSheet("background-color:transparent;");

    //设置滚动条样式
    ui->btmScrollArea->horizontalScrollBar()->setStyleSheet(scrollstyle);

    //下部Widget,以topScrollArea为父窗口
    btmWidget = new QWidget(ui->btmScrollArea);
    ui->btmScrollArea->setWidget(btmWidget);
    btmWidget->setMouseTracking(true); //激活鼠标跟踪

    QString btmurl[3] = {"QPushButton{border-image: url(:/new/Image/movie.jpg)}",
                          "QPushButton{border-image: url(:/new/Image/design.jpg)}",
                          "QPushButton{border-image: url(:/new/Image/xing.jpg)}"};
}

}

Widget::~Widget()
{
    delete ui;
}


void Widget::mouseMoveEvent(QMouseEvent *ev)
{
    int posx = ev->pos().x();
    int posy = ev->pos().y();

    if((0<=posx&&posx<=680) && (0<=posy&&posy<=300))
    {
        ui->topBg->setStyleSheet("background-color: #f8bd5f");
        ui->midBg->setStyleSheet("background-color: #f7d8a7");
        ui->btmBg->setStyleSheet("background-color: #f7d8a7");
        ui->label_2->hide();
        ui->label_3->show();
    }

    else if((0<=posx&&posx<=680) && (300<posy&&posy<=540))
    {
        ui->midBg->setStyleSheet("background-color: #74b4b3");
        ui->topBg->setStyleSheet("background-color: #bacaca");
        ui->btmBg->setStyleSheet("background-color: #bacaca");
        ui->label_2->hide();
        ui->label_3->hide();
    }
    else if((0<=posx&&posx<=680) && (540<posy&&posy<=780))
    {
        ui->btmBg->setStyleSheet("background-color: #8391a3");
        ui->topBg->setStyleSheet("background-color: #c6c8cb");
        ui->midBg->setStyleSheet("background-color: #c6c8cb");
        ui->label_2->show();
        ui->label_3->hide();
    }

}

void Widget::AddArticle()
{
	int topBtnNum = passage.size(); //记录top中按钮个数
	int midBtnNum = recentview.size(); //记录mid中按钮个数
	int btmBtnNum = likepassage.size(); //记录btm中按钮的个数
	
	
	//上部Widget,以topScrollArea为父窗口
	QWidget *topWidget = new QWidget(ui->topScrollArea);
	ui->topScrollArea->setWidget(topWidget);
	topWidget->setMouseTracking(true); //激活鼠标跟踪

	//top部分增加按钮
	int topwidth = topBtnNum * 270 + (topBtnNum - 1) * 40;
	topWidget->setMinimumSize(topwidth, 180);
	
	//定义多个按钮
	QSignalMapper *topSignalMapper = new QSignalMapper;
	QPushButton *topArticleBtn = new QPushButton[topBtnNum];
	for (int i = 0; i < topBtnNum; i++)
	{
		topArticleBtn[i].setParent(topWidget);
		topArticleBtn[i].setGeometry(310 * i, 0, 270, 180);
		/*QIcon icon("C:\\Users\\91970\\Desktop\\dog.jpg");
		topArticleBtn[i].setIcon(icon);
		topArticleBtn[i].setIconSize(topArticleBtn[i].rect().size());*/
		topArticleBtn[i].setStyleSheet("background-color: black;");
		topArticleBtn[i].setMouseTracking(true); //激活鼠标跟踪
		topSignalMapper->setMapping(&topArticleBtn[i], i);
		connect(&topArticleBtn[i], SIGNAL(clicked()), topSignalMapper, SLOT(map()));
	}
	connect(topSignalMapper, SIGNAL(mapped(int)), this, SLOT(showTopArticle(int)));

	//mid部分增加按钮
	int midwidth = midBtnNum * 150 + (midBtnNum - 1) * 20;
	midWidget->setMinimumSize(midwidth, 150);
	//定义多个按钮
	QSignalMapper *midSignalMapper = new QSignalMapper;
	QPushButton *midArticleBtn = new QPushButton[midBtnNum];
	for (int i = 0; i < midBtnNum; i++)
	{
		midArticleBtn[i].setGeometry(170 * i, 0, 150, 150);
		midArticleBtn[i].setParent(midWidget);
		QIcon icon(recentview[i].pic_url);
		midArticleBtn[i].setIcon(icon);
		midArticleBtn[i].setIconSize(midArticleBtn[i].rect().size());
		midArticleBtn[i].setMouseTracking(true); //激活鼠标跟踪
		midSignalMapper->setMapping(&midArticleBtn[i], i);
		connect(&midArticleBtn[i], SIGNAL(clicked()), midSignalMapper, SLOT(map()));
	}
	connect(midSignalMapper, SIGNAL(mapped(int)), this, SLOT(showMidArticle(int)));

	//btm部分增加按钮
	int btmwidth = btmBtnNum * 150 + (btmBtnNum - 1) * 20;
	btmWidget->setMinimumSize(btmwidth, 150);
	//定义多个按钮
	QSignalMapper *btmSignalMapper = new QSignalMapper;
	QPushButton *btmArticleBtn = new QPushButton[btmBtnNum];
	for (int i = 0; i < btmBtnNum; i++)
	{
		btmArticleBtn[i].setGeometry(170 * i, 0, 150, 150);
		btmArticleBtn[i].setParent(btmWidget);
		QIcon icon(likepassage[i].pic_url);
		btmArticleBtn[i].setIcon(icon);
		btmArticleBtn[i].setIconSize(btmArticleBtn[i].rect().size());
		btmWidget->setMouseTracking(true); //激活鼠标跟踪
		btmSignalMapper->setMapping(&btmArticleBtn[i], i);
		connect(&btmArticleBtn[i], SIGNAL(clicked()), btmSignalMapper, SLOT(map()));
	}
	connect(btmSignalMapper, SIGNAL(mapped(int)), this, SLOT(showBtmArticle(int)));
}

void Widget::showTopArticle(int i)
{
    ui->btmWidget->setStyleSheet("border-image:url(:/new/Image/bg.png); background-color:#f7d8a7");
    ui->topWidget->setStyleSheet("background-color:#f8bd5f");

	ui->articlename->setText(passage[i].title);
	QImage newimg(passage[i].pic_url);
	ui->articleImg->setPixmap(QPixmap::fromImage(newimg));
	ui->contentView->setText(passage[i].content);
	recentview.insert(recentview.begin(), passage[i]);
	if(passage[i].isLike) ui->likeButton_5->setStyleSheet("QPushButton{border-image:url(:/new/Image/newxin.png);}");
	else ui->likeButton_5->setStyleSheet("QPushButton{border-image:url(:/new/Image/xin.png);}");
	nowpassage[0] = i+1;
    ui->stackedWidget->setCurrentIndex(1);
}

void Widget::showMidArticle(int i)
{
    ui->btmWidget->setStyleSheet("border-image:url(:/new/Image/bg.png); background-color:#bacaca");
    ui->topWidget->setStyleSheet("background-color:#74b4b3");

	ui->articlename->setText(recentview[i].title);
	QImage newimg(recentview[i].pic_url);
	ui->articleImg->setPixmap(QPixmap::fromImage(newimg));
	ui->contentView->setText(recentview[i].content);
	if(recentview[i].isLike)
		ui->likeButton_5->setStyleSheet("QPushButton{border-image:url(:/new/Image/newxin.png);}");
	else ui->likeButton_5->setStyleSheet("QPushButton{border-image:url(:/new/Image/xin.png);}");
	nowpassage[1] = i + 1;
    ui->stackedWidget->setCurrentIndex(1);
}

void Widget::showBtmArticle(int i)
{
    ui->btmWidget->setStyleSheet("border-image:url(:/new/Image/bg.png); background-color:#c6c8cb");
    ui->topWidget->setStyleSheet("background-color:#8391a3");

    ui->articlename->setText(likepassage[i].title);
	QImage newimg(likepassage[i].pic_url);
	ui->articleImg->setPixmap(QPixmap::fromImage(newimg));
	ui->contentView->setText(likepassage[i].content);
	ui->likeButton_5->setStyleSheet("QPushButton{border-image:url(:/new/Image/newxin.png);}");
	nowpassage[2] = i + 1;

    ui->stackedWidget->setCurrentIndex(1);
}


void Widget::on_backButton_5_clicked()
{
    ui->topScrollArea->horizontalScrollBar()->setValue(0);
    ui->midScrollArea->horizontalScrollBar()->setValue(0);
    ui->btmScrollArea->horizontalScrollBar()->setValue(0);
	if (passage[nowpassage[0]].isLike&&!passage[nowpassage[0]].inlike) {
		likepassage.insert(likepassage.begin(), passage[nowpassage[0]]);
		passage[nowpassage[0]].inlike = true;
	}
	count = 0;
	AddArticle();
    ui->stackedWidget->setCurrentIndex(0);
}

void Widget::on_likeButton_5_clicked()
{
	int now;
	if (!nowpassage[0]) {
		now = nowpassage[0] - 1;
		if (passage[now].isLike) count = 1;
	}
	else if (!nowpassage[1]) {
		now = nowpassage[1] - 1;
		if (recentview[now].isLike) count = 1;
	}
	else if (!nowpassage[2]) {
		now = nowpassage[2] - 1;
		if (likepassage[now].isLike) count = 1;
	}
	count++;
    if(count%2==1){
        ui->likeButton_5->setStyleSheet("QPushButton{border-image:url(:/new/Image/newxin.png);}");
		passage[now].isLike = true;
    }
    else{
        ui->likeButton_5->setStyleSheet("QPushButton{border-image:url(:/new/Image/xin.png);}");
		passage[now].isLike = false;
    }
}

//time的槽函数,随着时间的刷新判断是否有新的文章接收进来
void Widget::Renew()
{
    if(passagenum!=passage.size())//如果接收到新的文章
        ui->renew->setStyleSheet("QPushButton{border-image:url(:/new/Image/new1.png);}");
}

//点击刷新按钮之后红点消失
void Widget::on_renew_clicked()
{
    ui->renew->setStyleSheet("QPushButton{border-image:url(:/new/Image/new.png);}");
	passagenum = passage.size();
	AddArticle();
	qDebug() << passage[0].pic_url;
}
