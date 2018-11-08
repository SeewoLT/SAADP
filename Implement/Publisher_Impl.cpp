#include "Publisher_Impl.h"
#include "common/example_utilities.h"
#include "Entities.cpp"


namespace Passage {

	int Publisher(int argc, char *argv[]) {

		int result = 0;
		std::stringstream ss;
		try
		{
			/** Initialise entities */
			PubEntities e;

			int numMsg = 10;

			/**
			 * Get the user details from the program parameters and write them to the system
			 * Parameters: Chatter [userID] [userName] [numMsg]
			 */
			PassageData::NameService user;
			user.userID() = argc < 2 ? 1 : atoi(argv[1]);
			if (argc < 3)
			{
				ss << "PublisherID " << user.userID();
				user.name() = ss.str();
			}
			else
			{
				user.name() = argv[2];
			}
			/*if (argc == 4)
			{
				numMsg = atoi(argv[3]);
			}*/
			e.nameServiceWriter << user;

			/** Initialise the chat message */
			PassageData::PassageMessage msg;
			msg.userID() = user.userID();
			msg.index() = 0;
			if (user.userID() == TERMINATION_MESSAGE)
			{
				msg.content() = "Termination message.";

			}
			else if (user.userID() == 1) {
				msg.title() = "柠檬国际市场的扩张，如何导致西西里岛黑手党的崛起？";
				msg.pic_url() = "xxx1";
				msg.content() = "西西里岛黑手党（Sicilian mafia）大概是全世界最著名的犯罪组织。它最迟于 19 世纪 70 年代便已正式成立。当时，一位西西里岛的地主在文件中记载了一群本地黑手党成员如何威胁和骚扰他的生意，最终迫使他不得不离开西西里岛以图安宁和自保。多年以来，无数书籍、电影和流行文化作品都以黑手党和它在美国的分支为主题进行刻画描述。不过，黑手党的起源却始终是个谁也猜不透迷。1860-1861 年，意大利通过独立战争实现统一。在此期间，什么因素导致西西里岛的黑手党突然崛起？黑手党成员称自己是“君子”（men of honour），但他们真的会保护贫穷的普通百姓免受压迫政权的侵害吗？或者说黑手党是抵抗共产主义的堡垒，在此过程中实现发展壮大？";

			}
			else if (user.userID() == 2) {
				msg.title() = "流感季来临但疫苗供不应求，中国今年流感疫苗供应量只有去年一半";
				msg.pic_url() = "xxx2";
				msg.content() = "根据中国食品药品检定研究院（以下简称中检院）的数据，截至 2018 年 10 月 21 日该院流感疫苗的批签发数量仅为 1091 万份，远低于去年同期的 2000 万份左右的水平。而中检院发布的《2017 年生物制品批签发年报》显示，去年全年其签发的流感病毒裂解疫苗达到了 2530 万份。";

			}
			else if (user.userID() == 3) {
				msg.title() = "一位古典学教授 50 年训练和研究成果，讲述千年的罗马史";
				msg.pic_url() = "xxx3";
				msg.content() = "公元前44年，尤里乌斯·恺撒在被罗马人称作“3月望日”的那天遇刺，此事为后来的刺杀暴君行动提供了模板，有时还提供了不甚合适的理由。罗马帝国的疆域构成了现代欧洲和周边地区政治地理的基础。伦敦成为英国首都的主要理由在于，罗马人将其作为他们的不列颠行省——在他们看来，这是一片位于围绕文明世界的环洋彼岸的危险土地——的治所。罗马留给我们的不仅是帝国的剥削，还有自由和公民权的理念，以及从“ 参议员到“ 独裁者”等一系列现代政治词汇。“害怕希腊人送礼”“面包和竞技”“罗马着火时还在弹琴”，这些都是我们从罗马人那里借用的名言，连“活着就有希望”也是。它引发了差不多同等程度的笑声、惊愕和恐惧。和当时一样，角斗士今天仍然是票房明星。维吉尔描述罗马奠基的伟大史诗《埃涅阿斯纪》在20世纪的读者数量几乎肯定要超过 1 世纪时的。";

			}
			else if (user.userID() == 4) {
				msg.title() = "泉州泉港区“碳九”泄漏第五天，漏的到底是何物质尚无最终定论";
				msg.pic_url() = "xxx4";
				msg.content() = "肖历香还提到，她的一位亲戚 5 日在作业过程中头晕落水，被送入重症监护室。这则消息后来再自媒体文章中被大量提及，《新京报》 6 日的报道中官方称“正在核实”，医院的检查结果为“考虑双肺炎症”。她强调 ，村中养殖户都会游泳，不会是普通的失足溺水。为避免泄漏物对孩子的影响，肖历香目前正带着孩子在漳州暂住。她说当地的小学尚未停课，但是有许多家长已经向学校请假，带孩子转移。";

			}
			else if (user.userID() == 5) {
				msg.title() = "星巴克中国市场要涨价，会员权益中的免费咖啡券也减少了";
				msg.pic_url() = "xxx5";
				msg.content() = "上一次星巴克在中国市场涨价是在 2016 年 6 月，美式咖啡、摩卡、拿铁、卡布奇诺、焦糖玛奇朵都在原价基础上上涨了 1-2 元。星巴克也说涨价主要是因为成本上涨导致，但 2016 年涨价与再前一次涨价相隔了 4 年。";

			}
			else if (user.userID() == 6) {
				msg.title() = "平安 120 亿美元入股汇丰，成后者第一大股东";
				msg.pic_url() = "xxx6";
				msg.content() = "就目前而言，我们没有海外收购的抱负。马明哲接受英国《金融时报》采访时表示，“中国市场有最好的增长前景。”而就在该报道的前 3 天，央行发布的《中国金融稳定报告》称，一些企业投资动机不纯，在金融扩张中同时控制多类金融机构，形成跨区域、跨国境经营的金融控股集团，风险不断累积和暴露。报告指出，将提高对金融控股集团的监管力度，在防范系统性金融风险上提出了市场准入、资本充足率等 7 项监管制度。";

			}
			else if (user.userID() == 7) {
				msg.title() = "《重庆日报》说重庆高考要政审，但学校称没有收到通知";
				msg.pic_url() = "xxx7";
				msg.content() = "报道还称，普通高中毕业生（含应、往届和外地转回）的政审将以《重庆市普通高中毕业生综合素质评价报告》的形式呈现。目前的《重庆市普通高中毕业生综合素质评价报告》除了基本信息，评价报告部分包括各科目成绩和综合素质评价部分。后者“道德品质与公民素养”“学习与创新”“交流与合作”“运动与健康”“审美与表现”需要学校分项评价。";

			}
			else if (user.userID() == 8) {
				msg.title() = "研究发现手机辐射致使大鼠患癌，但相关结果不能推广到人类";
				msg.pic_url() = "xxx8";
				msg.content() = "当被问及自己的手机使用情况时，布赫尔博士说他从来都不是一个重度使用者，但鉴于这项研究，他现在在使用手机时会多一点意识。他表示，在长时间的通话中，他会依照向消费者发出的减少辐射暴露的建议，尝试使用耳机或寻找其他方式来“增加（身体与手机之间的）距离”。";

			}
			else if (user.userID() == 9) {
				msg.title() = "爱因斯坦关于世界观的文章结集出版，展现科学家的另一面";
				msg.pic_url() = "xxx9";
				msg.content() = "阿尔伯特•爱因斯坦（Albert Einstein）： 1879 年 3 月 14 日出生于德意志帝国符腾堡王国乌尔姆市， 1955 年 4 月 18 日在美国新泽西州普林斯顿去世，被认为是科学史上最重要的理论物理学家之一。他对物质结构、空间和时间以及引力性质的研究，彻底改变了牛顿时代以来人们的世界观。他最为人知的是其质能等价公式E=mc2（被称为“世界上最著名的方程”）。因“对理论物理学的贡献，尤其是他发现了光电效应的规律”而获得 1921 年度诺贝尔物理学奖。爱因斯坦发表了 300 多篇科学论文以及 150 多篇非科学论文，留下了 3 万多封信件。他的智力成就和独创性使得“爱因斯坦”成为“天才”的代名词。爱因斯坦利用自己非凡的社会名望，致力于国际理解与和平。他称自己为和平主义者、社会主义者和犹太复国主义者。";

			}

			/*else {
				ss.str("");
				ss << "Hi There, I will send you " << numMsg << " more messages.";
				msg.content() = ss.str();
			}*/

			/**
			 * Register a dds::core::InstanceHandle for the message, this causes resources
			 * to be preallocated for it
			 */
			dds::core::InstanceHandle userHandle = e.chatMessageWriter.register_instance(msg);

			/** Write the message */
			e.chatMessageWriter.write(msg, userHandle);
			std::cout << "Writing message: \t" << msg.userID() << std::endl << msg.title() << "\t" << msg.pic_url() << std::endl << msg.content() << "\t" << std::endl;

			/** Wait to ensure messages are sent */
			exampleSleepMilliseconds(1000);

			///** Write remaining messages */
			//for (int i = 1; i <= numMsg && user.userID() != TERMINATION_MESSAGE; i++)
			//{
			//	msg.index() = i;
			//	ss.str("");
			//	ss << "Message no. " << i;
			//	msg.content() = ss.str();
			//	/*!!!!!!!!!!!!*/
			//	msg.userID() = user.userID();
			//	msg.pic_url() = "Pic URL";
			//	/*!!!!!!!!!!!!*/
			//	e.chatMessageWriter.write(msg, userHandle);
			//	std::cout << "Writing message: \"" << msg.content() << "\"" << std::endl;

			//	/** Wait to ensure messages are sent */
			//	exampleSleepMilliseconds(1000);
			//}

			std::cout << "\n---完成了文章的发布！---" << std::endl;
		}
		catch (const dds::core::Exception& e)
		{
			std::cerr << "ERROR: Exception: " << e.what() << std::endl;
			result = 1;
		}
		return result;


		//int result = 0;
		//std::stringstream ss;

		//try
		//{
		//	/** Initialise entities */
		//	PubEntities pubEntities;

		//	int numMsg = 10;

		//	/**
		//	 * Get the user details from the program parameters and write them to the system
		//	 * Parameters: Chatter [userID] [userName] [numMsg]
		//	 */
		//	PassageData::NameService user;

		//	user.userID() = argc < 2 ? 1 : atoi(argv[1]);

		//	if (argc < 3)
		//	{
		//		ss << "Chatter " << user.userID();
		//		user.name() = ss.str();
		//	}
		//	else
		//	{
		//		user.name() = argv[2];
		//	}
		//	if (argc == 4)
		//	{
		//		numMsg = atoi(argv[3]);
		//	}
		//	pubEntities.nameServiceWriter << user;

		//	/** Initialise the Passage message */
		//	PassageData::PassageMessage msg;

		//	msg.userID() = user.userID();

		//	msg.index() = 0;

		//	if (user.userID() == TERMINATION_MESSAGE)
		//	{
		//		msg.content() = "Termination message.";
		//	}
		//	else
		//	{
		//		/*ss.str("");
		//		ss << "Hi There, I will send you " << numMsg << " more messages.";*/
		//		msg.title() = "标题一";
		//		msg.pic_url() = "C:\\Users\\91970\\Desktop\\Image\\AI.jpg";
		//		msg.content() = "花朵感恩雨露，因为露水给了它滋润；小草感恩阳光，因为阳光给了它们温暖；我们感恩父母，因为父母给了我们生命和爱；我们感恩老师，因为老师给我们传授了知识。感恩使这个世界变得更加和谐美好。";
		//		/*msg.content() = ss.str();*/
		//	}

		//	/**
		//	 * Register a dds::core::InstanceHandle for the message, this causes resources
		//	 * to be preallocated for it
		//	 */
		//	dds::core::InstanceHandle userHandle = pubEntities.chatMessageWriter.register_instance(msg);

		//	/** Write the message */
		//	pubEntities.chatMessageWriter.write(msg, userHandle);

		//	std::cout << "\nUserID: " << user.userID() << "的 " << user.name() << "传输了一篇文章！" << std::endl;
		//	std::cout << "Passage Index: " << msg.index() << "\t" << msg.title() << "\t" << msg.pic_url() << "\t" << msg.content() << "\t" << std::endl;

		//	/** Wait to ensure messages are sent */
		//	exampleSleepMilliseconds(1000);

		//	/** Write remaining messages */
		//	for (int i = 1; i <= 1 && user.userID() != TERMINATION_MESSAGE; i++)
		//	{
		//		//msg.index() = i;

		//		ss.str("");

		//		//ss << "Message no. " << i;
		//		msg.content() = ss.str();

		//		pubEntities.chatMessageWriter.write(msg, userHandle);

		//		std::cout << "Writing message: \"" << msg.content() << "\"" << std::endl;

		//		/** Wait to ensure messages are sent */
		//		exampleSleepMilliseconds(1000);
		//	}

		//	std::cout << "\n传输完成！\n" << std::endl;
		//}
		//catch (const dds::core::Exception& e)
		//{
		//	std::cerr << "ERROR: Exception: " << e.what() << std::endl;
		//	result = 1;
		//}
		//return result;
	}
}