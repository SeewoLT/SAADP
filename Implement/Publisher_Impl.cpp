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
				ss << "Chatter " << user.userID();
				user.name() = ss.str();
			}
			else
			{
				user.name() = argv[2];
			}
			if (argc == 4)
			{
				numMsg = atoi(argv[3]);
			}
			e.nameServiceWriter << user;

			/** Initialise the chat message */
			PassageData::PassageMessage msg;
			msg.userID() = user.userID();
			msg.index() = 0;
			if (user.userID() == TERMINATION_MESSAGE)
			{
				msg.content() = "Termination message.";
			}
			else
			{
				ss.str("");
				ss << "Hi There, I will send you " << numMsg << " more messages.";
				msg.content() = ss.str();
			}

			/**
			 * Register a dds::core::InstanceHandle for the message, this causes resources
			 * to be preallocated for it
			 */
			dds::core::InstanceHandle userHandle = e.chatMessageWriter.register_instance(msg);

			/** Write the message */
			e.chatMessageWriter.write(msg, userHandle);
			std::cout << "Writing message: \"" << msg.content() << "\"" << std::endl;

			/** Wait to ensure messages are sent */
			exampleSleepMilliseconds(1000);

			/** Write remaining messages */
			for (int i = 1; i <= numMsg && user.userID() != TERMINATION_MESSAGE; i++)
			{
				msg.index() = i;
				ss.str("");
				ss << "Message no. " << i;
				msg.content() = ss.str();
				/*!!!!!!!!!!!!*/
				msg.userID() = user.userID();
				msg.pic_url() = "Pic URL";
				/*!!!!!!!!!!!!*/
				e.chatMessageWriter.write(msg, userHandle);
				std::cout << "Writing message: \"" << msg.content() << "\"" << std::endl;

				/** Wait to ensure messages are sent */
				exampleSleepMilliseconds(1000);
			}

			std::cout << "Completed Chatter example." << std::endl;
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
		//		msg.title() = "����һ";
		//		msg.pic_url() = "C:\\Users\\91970\\Desktop\\Image\\AI.jpg";
		//		msg.content() = "����ж���¶����Ϊ¶ˮ����������С�ݸж����⣬��Ϊ�������������ů�����Ǹж���ĸ����Ϊ��ĸ�������������Ͱ������Ǹж���ʦ����Ϊ��ʦ�����Ǵ�����֪ʶ���ж�ʹ��������ø��Ӻ�г���á�";
		//		/*msg.content() = ss.str();*/
		//	}

		//	/**
		//	 * Register a dds::core::InstanceHandle for the message, this causes resources
		//	 * to be preallocated for it
		//	 */
		//	dds::core::InstanceHandle userHandle = pubEntities.chatMessageWriter.register_instance(msg);

		//	/** Write the message */
		//	pubEntities.chatMessageWriter.write(msg, userHandle);

		//	std::cout << "\nUserID: " << user.userID() << "�� " << user.name() << "������һƪ���£�" << std::endl;
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

		//	std::cout << "\n������ɣ�\n" << std::endl;
		//}
		//catch (const dds::core::Exception& e)
		//{
		//	std::cerr << "ERROR: Exception: " << e.what() << std::endl;
		//	result = 1;
		//}
		//return result;
	}
}