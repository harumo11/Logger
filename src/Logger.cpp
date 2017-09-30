#include <string>
#include <iostream>
#include <sstream>
#include "../include/Logger/Logger.hpp"


/**
 * @brief The constructor if custmised logger is used, make instance with this costructor.
 *
 * @param loggerTitle name of logger wiche is displaied in the messages.
 */
Logger::Logger(std::string loggerTitle)
{
	this->loggerTitle = loggerTitle;

	//this->logFile.open(this->loggerTitle);
	//if (this->logFile && shouldWriteToFile == true) {
	//	//When log file is opend and flag is true, this->shouldWriteToFile became true.

	//	this->shouldWriteToFile = true;

	//}
}


/**
 * @brief Display the message with custmised logger if you make custamised logger using the constructor.
 *
 * @return the message to be dressed up
 */
std::string Logger::notify()
{
	if (this->style == 0) {
		// When info type is specified
		int h,m,s;
		Logger::getCurrentTime(h, m, s);
		std::stringstream output;
		output << Logger::charColor(32) << Logger::bold() << "[ " << this->loggerTitle <<  " ]" << Logger::remove() << " [ " << h << " " << m << " " << s << " ] ";

		return output.str();
	}
	else if (this->style == 1) {
		// When warn type is spedified
		int h,m,s;
		Logger::getCurrentTime(h, m, s);
		std::stringstream output;
		output << Logger::charColor(33) << Logger::bold() << "[ " << this->loggerTitle <<  " ]" << Logger::remove() << " [ " << h << " " << m << " " << s << " ] " ;

		return output.str();
	}
	else if (this->style == 2) {
		// When error type is spedified
		int h,m,s;
		Logger::getCurrentTime(h, m, s);
		std::stringstream output;
		output << Logger::charColor(31) << Logger::bold() << "[ " << this->loggerTitle << " ]" << Logger::remove() << " [ " << h << " " << m << " " << s << " ] ";

		return output.str();
	}
	else if (this->style == 3) {
		// When critical type is spedified
		int h,m,s;
		Logger::getCurrentTime(h, m, s);
		std::stringstream output;
		output << Logger::charColor(33) << "\033[41m" << Logger::bold() << "[ " << this->loggerTitle <<  " ]"<< Logger::remove() << " [ " << h << " " << m << " " << s << " ] ";
	
		return output.str();
	}
	else {
	// When nothing valid type to be specified
		return "";
	}
}

/**
 * @brief Changing the notification style(info, warn, error, critical)
 *
 * @param style The notification styles
 *
 * |Style|Number|Enum|
 * |-----|------|----|
 * |Information|0|Logger::Style::INFO|
 * |Warning    |1|Logger::Style::WARN|
 * |Error      |2|Logger::Style::ERROR|
 * |Critical   |3|Logger::Style::CRITICAL|
 *
 */
void Logger::changeStyle(int style){

	if (0 <= style && style <= 3) {
		this->style = style;
	}
}

/**
 * @brief Set current hour, minute and second to member value.
 */
void Logger::getCurrentTime()
{
	std::time_t now = std::time(NULL);
	struct tm *pnow = std::localtime(&now);

	this->currentHour = pnow->tm_hour;
	this->currentMin  = pnow->tm_min;
	this->currentSec  = pnow->tm_sec;
}


/**
 * @brief Get current time ( hour, minute, second)
 *
 * @param hour hour
 * @param min  minute
 * @param sec  second
 */
void Logger::getCurrentTime(int &hour, int &min, int &sec)
{
	std::time_t now = std::time(NULL);
	struct tm *pnow = std::localtime(&now);
	hour = pnow->tm_hour;
	min  = pnow->tm_min;
	sec  = pnow->tm_sec;
}


/**
 * @brief Added colorfull time and kind of information.
 *
 * @return [ INFO ] [ hour munute second ] 
 */
std::string Logger::info()
{
	int h,m,s;
	Logger::getCurrentTime(h, m, s);
	std::stringstream output;
	output << Logger::charColor(32) << Logger::bold() << "[ INFO  ]" << Logger::remove() << " [ " << h << " " << m << " " << s << " ] ";

	return output.str();
}


/**
 * @brief Added colorful time and kind of information.
 *
 * @return [ WARN ] [ hour minute second ]
 */
std::string Logger::warn()
{
	int h,m,s;
	Logger::getCurrentTime(h, m, s);
	std::stringstream output;
	output << Logger::charColor(33) << Logger::bold() << "[ WARN  ]" << Logger::remove() << " [ " << h << " " << m << " " << s << " ] " ;

	return output.str();
}


/**
 * @brief Added colorful time and kind of information.
 *
 * @return [ ERROR ] [ hour minute second ]
 */
std::string Logger::error()
{
	int h,m,s;
	Logger::getCurrentTime(h, m, s);
	std::stringstream output;
	output << Logger::charColor(31) << Logger::bold() << "[ ERROR ]" << Logger::remove() << " [ " << h << " " << m << " " << s << " ] ";

	return output.str();
}


/**
 * @brief Added colorful time and kind of information.
 *
 * @return [ CRITICAL ] [ hour minute second ]
 */
std::string Logger::critical()
{
	int h,m,s;
	Logger::getCurrentTime(h, m, s);
	std::stringstream output;
	output << Logger::charColor(33) << "\033[41m" << Logger::bold() << "[ CRITICAL ]"<< Logger::remove() << " [ " << h << " " << m << " " << s << " ] ";

	return output.str();
}

/**
 * @brief Add bold effect.
 *
 * @return Escape sequence to add bold charactor effect.
 * 
 * ```
 * std::cout << Logger::bold() << "Good Morning" << std::endl;
 * ```
 * "Good Morning" will be bold.
 */
std::string Logger::bold()
{
	return std::string("\033[1m");
}


/**
 * @brief Remove all effect.
 *
 * @return Escape sequence to remove all effects.
 * 
 */
std::string Logger::remove()
{
	return std::string("\033[0m");
}

/**
 * @brief Add color to charactor or string.
 *
 * @param color A color which you want to effect is express a integer number as below table.
 *
 * @return Escape sequence to add color of charactor
 * 
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
 *
 */
std::string Logger::charColor(int color)
{
	std::stringstream ss;
	ss << "\033[" << color << "m";
	return ss.str();
}
