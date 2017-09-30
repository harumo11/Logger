#include "../include/Logger/Logger.hpp"

/**
 * @brief A constructor showing progress bar
 *
 * @param max Maximum value. Maybe counts of for-syntax 
 * @param title Title of progress bar.
 * @param stepSize Step size of progress. For example, you set max=100, stepSize=10, the progress bar process 10/100 = 10 percents per each cicle.
 */
Progress::Progress(int max, std::string title, int stepSize)
{
	this->maxValue = (double)max;
	this->step = stepSize;
	this->progressValue = 0;
	this->percentValue = 0;
	this->title = title;
}


/**
 * @brief Clearing a line which cirsol exists.
 *
 * @return Escape sequence which is used with std::cout.
 */
std::string Progress::clearLine()
{
	std::cout << std::string("\033[2K") << std::flush;
	return std::string("\033[2K");
}



/**
 * @brief showing progress bar. This is called in for-syntax.
 */
void Progress::show()
{
	this->clearLine();
	this->moveLineHead();

	this->progressValue += this->step;;

	// ％を計算する
	this->percentValue = (this->progressValue / this->maxValue) * 100;

	std::cout << this->title << " [" << std::flush;

	for (int i = 0; i * 10 < (int)this->percentValue; i++) {
		std::cout << "." << std::flush;
		//std::cout << "\033[107m" << std::flush;
	}
	std::cout << "] " << this->percentValue << " %"<< std::flush;

	if (this->progressValue >= this->maxValue) {
		std::cout << std::endl;
	}
}


/**
 * @brief Move cirsol to head of line.
 */
void Progress::moveLineHead()
{
	std::cout << std::string("\033[G") << std::flush;
}


