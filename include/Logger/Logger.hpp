#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <ctime>


class Progress {
	public:
		Progress(int max, std::string title = "Progress", int stepSize = 1);
		void show();

		static std::string clearLine();
		static void moveLineHead();

	private:
		double maxValue;
		double progressValue;
		double percentValue;
		int step;
		std::string title;
};

class logbuff : public std::streambuf{
	public:
		int virtual overflow(int c){return c;};
};


class Logger {
	
	public:
		/**
		 * @brief If true, display. otherwise not display.
		 *
		 * You can switch easily whether display information or not.
		 *
		 * |ON|OFF|
		 * |--|---|
		 * |true|false|
		 *
		 */
		bool enabled = true;

		Logger(std::string loggerTitle);
		void changeStyle(int style = 0);

		static std::string info();
		static std::string warn();
		static std::string error();
		static std::string critical();

		static std::string bold();
		static std::string charColor(int color);
		static std::string remove();

		/**
		 * @brief Shift operater <<
		 * 
		 * This shift operater << allow the programer to std::cout easily.
		 *
		 * @param content The information which you want to display colorfully.
		 *
		 * @return 
		 */
		template<typename T_c>
		std::ostream& operator << (const T_c& content) {
			static logbuff lb;
			static std::ostream os(&lb);
		
			if(!this->enabled){
				return os;
			}
			std::cout << this->notify() << content;
			return std::cout;
		}

		/**
		 * @brief This StyleSet is Combined with function Logger::changeStyle()
		 * 
		 * ````
		 *	Logger::changeStyle(Logger::StyleSet::INFO);
		 * ````
		 */
		enum StyleSet {
				INFO = 0,
				WARN = 1,
				ERROR = 2,
				CRITICAL = 3,
		};

		/**
		 * @brief This charactorColor is combine with function Logger::charColor()
		 *
		 * ````
		 * Logger::charColor(Logger::ColorSet::black);
		 * ````
		 * |Member  | Color |
 		 * |:-----:|:------:|
 		 * |ColorSet::black |black       |
 		 * |ColorSet::red   |red         |
 		 * |ColorSet::green |green       |
 		 * |ColorSet::yellow|yellow      |
 		 * |ColorSet::blue  |blue        |
 		 * |ColorSet::perple|perple      |
 		 * |ColorSet::water |water       |
 		 * |ColorSet::white |white       |
		 */
		enum ColorSet : unsigned int{
			black = 30,
			red ,  
		    green, 
		    yellow,
		    blue , 
		    perple,
		    water ,
		    white ,
		};

	private:
		std::string notify();
		void getCurrentTime();
		static void getCurrentTime(int &hour, int &min, int &sec);
		int currentHour;
		int currentMin;
		int currentSec;
		std::string loggerTitle;
		int style = 0;
		//std::fstream logFile;
		//bool shouldWriteToFile = false;
};




