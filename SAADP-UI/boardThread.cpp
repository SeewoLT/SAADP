#pragma execution_character_set("utf-8")
#include "boardThread.h"

#include <iostream>

#include "../Implement/Entities.cpp"
#include "common/example_utilities.h"

BoardThread::BoardThread()
{
}


BoardThread::~BoardThread()
{
}


void BoardThread::run()
{
	int result = 0;
	try
	{
		/** Initialise entities */
		Passage::SubEntities e;

		/** Get the userID to ignore from the program parameters */
		/** Parameters: MessageBoard [ignoreUserID] */
		int ignoreUserID = 0;
		//if (argc > 1)
		//{
		//	ignoreUserID = atoi(argv[1]);
		//}

		/** Create a DataState which will ensure the take onlys take alive messages */
		dds::sub::status::DataState aliveDataState;
		aliveDataState << dds::sub::status::SampleState::any()
			<< dds::sub::status::ViewState::any()
			<< dds::sub::status::InstanceState::alive();

		/**
		 * Create a Query to ignore messages from the userID taken from the program
		 * parameters
		 */
		std::stringstream queryString;
		queryString << "userID<>" << ignoreUserID;
		dds::sub::Query ignoreUserIDQuery(e.chatMessageReader, queryString.str());


		std::cout
			<< "MessageBoard has opened: send a PassageMessage with userID = -1 to close it....\n"
			<< std::endl;

		bool terminated = false;
		while (!terminated)
		{
			/**
			 * Take messages. Using take instead of read removes the messages from
			 * the system, preventing resources from being saturated due to a build
			 * up of messages
			 */
			dds::sub::LoanedSamples<PassageData::PassageMessage> messages
				= e.chatMessageReader.select().content(ignoreUserIDQuery)
				.state(aliveDataState).take();

			/** Output the username and content for each message */
			for (dds::sub::LoanedSamples<PassageData::PassageMessage>::const_iterator message
				= messages.begin(); message < messages.end(); ++message)
			{
				if (message->info().valid())
				{
					/** Terminate if termination message is received */
					if (message->data().userID() == TERMINATION_MESSAGE)
					{
						std::cout << "Termination message received: exiting..." << std::endl;
						terminated = true;
					}
					else
					{
						/** Create a Query to get the user with the userID from the message */
						std::stringstream queryString;
						queryString << "userID=" << message->data().userID();
						dds::sub::Query userIDQuery(e.nameServiceReader, queryString.str());

						/** Get the user */
						dds::sub::LoanedSamples<PassageData::NameService> users
							= e.nameServiceReader.select().content(userIDQuery)
							.state(aliveDataState).read();

						/** Output the username and content */
						for (dds::sub::LoanedSamples<PassageData::NameService>::const_iterator user
							= users.begin(); user < users.end(); ++user)
						{
							if (user->info().valid())
							{
								std::cout << "Here receive a passage!" << std::endl;
								//std::cout << user->data().name() << ": " << "\t" << user->data().userID() << std::endl 
									//<< "\t" << message->data().pic_url() << "\t" << message->data().content() << std::endl;
								w->tempArticle.title = QString::fromStdString(message->data().title());
								w->tempArticle.pic_url = QString::fromStdString(message->data().pic_url());
								w->tempArticle.content = QString::fromStdString(message->data().content());
								w->tempArticle.isLike = false;
								w->tempArticle.inlike = false;
								w->passages.insert(w->passages.begin(), w->tempArticle);
							}
						}
					}
				}
			}
			/** Sleep to avoid utilising too much CPU */
			exampleSleepMilliseconds(100);
		}
	}
	catch (const dds::core::Exception& e)
	{
		std::cerr << "ERROR: Exception: " << e.what() << std::endl;
		result = 1;
	}
}

void BoardThread::setWidget(Widget &w)
{
	this->w = &w;
}
