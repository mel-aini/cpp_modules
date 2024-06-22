#pragma once
#include <map>
#include <fstream>
#include <exception>
#include <iostream>
#include <sstream>
#include <climits>

#define	BTC_START	2009

enum {
	JANUARY = 1,
	FEBRUARY,
	MARCH,
	APRIL,
	MAY,
	JUNE,
	JULY,
	AUGUST,
	SEPTEMBER,
	OCTOBER,
	NOVEMBER,
	DECEMBER
};

class BitcoinExchange {
	private:
		std::map<std::string, std::string>	data;
		std::string							line;
		bool								isleap;
		int									month;
		long double							btc_value;

	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& B);
		BitcoinExchange& operator= (const BitcoinExchange& B);
		~BitcoinExchange();

		void	showDatabase();
		void	exchange(char	*file);

		void	parseline();

		void	parseDate(std::string& date);
		void	parseYear(std::string& year);
		void	parseMonth(std::string& month);
		void	parseDay(std::string& day);

		void	parseValue(std::string& value);

		bool	isdecimal(std::string& input);
		bool	is_a_leap_year(size_t year);
		bool	matchregex(char c);

		size_t	toNumber(std::string& input);
		void	checkSpaces();

		void	calculate(std::string& date);
};
