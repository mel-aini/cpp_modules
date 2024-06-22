#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
	// store the database in the map
	std::ifstream db("./data.csv", std::ios::in);
	if (!db.is_open())
		throw "Invalid database file";

	std::string line;
	getline(db, line);

    while (!db.eof()) {
		std::string date, value;
		std::stringstream ss(line);
		getline(db, line);
        getline(ss, date, ',');
        getline(ss, value);
		this->data[date] = value;
    }
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& B) {
	*this = B;
}

BitcoinExchange& BitcoinExchange::operator= (const BitcoinExchange& B) {
	if (this != &B)
	{
		this->data = B.data;
		this->line = B.line;
		this->isleap = B.isleap;
		this->month = B.month;
		this->btc_value = B.btc_value;
	}
	return *this;
}

BitcoinExchange::~BitcoinExchange()
{
}

void	BitcoinExchange::showDatabase() {
	std::map<std::string, std::string>::iterator it = this->data.begin();

	std::cout << "date | exchange_rate" << std::endl;
	for (; it != this->data.end(); it++) {
		std::cout << it->first + " | " + it->second << std::endl;
	}
}

void	BitcoinExchange::exchange(char	*file)
{
	std::ifstream infile(file, std::ios::in);
	if (!infile.is_open())
		throw "could not open file";

	// std::string line;
	getline(infile, this->line);
	if (line != "date | value")
		throw "Missing or invalid header";

	while (!infile.eof()) {
		try {
			getline(infile, this->line);
			// std::cout << line << std::endl;
			parseline();
		}
		catch (const char *e) {
			std::cout << "Error: " << e << std::endl;
		} catch (std::string& e) {
			std::cout << "Error: " << e << std::endl;
		}
	}
}

void	BitcoinExchange::parseline()
{
	checkSpaces();
	std::string date, del, value, ofl;
	std::stringstream ss(this->line);
	ss >> date;
	if (date.empty()) throw "bad input => " + this->line;

	parseDate(date);

	ss >> del;
	if (del.empty()) throw ("bad input => " + this->line);
	if (del != "|") throw "bad input => " + this->line;

	ss >> value;
	if (value.empty()) throw "bad input => " + this->line;

	// check if there is another unacessary data
	ss >> ofl;
	if (!ofl.empty()) throw "bad input => " + this->line;

	parseValue(value);
	calculate(date);
	// std::cout << "related db date value: " << std::endl;
	// std::cout << this->data[date] << std::endl;

}

void	BitcoinExchange::calculate(std::string& date)
{
	long double price, result;
	std::map<std::string, std::string>::iterator itlow;
	// std::map<std::string, std::string>::iterator begin = data.begin();

	itlow = data.lower_bound(date);
	if (itlow->second != date && date != "2009-01-02")
		itlow--;
	
	// if (itlow < begin)
	// 	throw "invalid first line";

	std::stringstream ss(itlow->second);


	ss >> price;
	result = price * btc_value;
	std::cout << date + " => " << btc_value << " = " << result << std::endl;
}

void	BitcoinExchange::parseDate(std::string& date)
{
	std::stringstream ss(date);
	std::string	year, month, day;
	getline(ss, year, '-');
	parseYear(year);
	getline(ss, month, '-');
	parseMonth(month);
	getline(ss, day);
	parseDay(day);
}

void	BitcoinExchange::parseYear(std::string& year)
{
	if (year.length() != 4 || !isdecimal(year))
		throw "bad input => " + this->line;

	size_t	y = toNumber(year);

	if (y < 2009)
		throw "bad input => " + this->line;

	this->isleap = is_a_leap_year(y);
}

void	BitcoinExchange::parseMonth(std::string& month)
{
	if (month.length() != 2 || !isdecimal(month))
		throw "bad input => " + this->line;

	size_t	m = toNumber(month);

	if (m < JANUARY || m > DECEMBER)
		throw "bad input => " + this->line;

	this->month = m;
}

void	BitcoinExchange::parseDay(std::string& day)
{
	if (day.length() != 2 || !isdecimal(day))
		throw "bad input => " + this->line;

	size_t	d = toNumber(day);

	if (d < 1 || d > 31)
		throw "bad input => " + this->line;

	if (this->month == FEBRUARY) {
		if (isleap && d > 29) throw "bad input => " + this->line;
		else if (!isleap && d > 28) throw "bad input => " + this->line;
	}
	else if (this->month == APRIL || this->month == JUNE || this->month == SEPTEMBER || this->month == NOVEMBER) {
		if (d > 30) throw "bad input => " + this->line;
	}
}

void	BitcoinExchange::parseValue(std::string& value)
{
	if (value.empty())
		throw "bad input => " + this->line;

	int	dots = 0, numbers = 0;
	
	for (size_t i = 0; i < value.length(); i++) {
		// std::cout << "i: " << i << std::endl;

		if (!matchregex(value[i]))
			throw "bad input => " + this->line;

		if (value[i] == '-' && i != 0)
			throw "bad input => " + this->line;
		else if (value[i] == 'f') {
			if (i != value.length() - 1) throw "bad input => " + this->line;
			value.erase(i, 1);
		}
		else if (value[i] == '.')
			dots++;
		else
			numbers++;
	}

	if (numbers < 1 || dots > 1)
		throw "bad input => " + this->line;

	std::stringstream ss(value);
	ss >> this->btc_value;


	if (this->btc_value > 1000)
		throw "too large a number.";

	if (this->btc_value < 0)
		throw "not a positive number.";

	// std::cout << "btc_value: " << this->btc_value << std::endl;
}

bool	BitcoinExchange::isdecimal(std::string& input)
{
	for (size_t i = 0; i < input.length(); i++) {
		if (input[i] < '0' || input[i] > '9')
			return false;
	}
	return true;
}

bool	BitcoinExchange::is_a_leap_year(size_t year)
{
	double result = static_cast<double>(year) / 4;
	if (result == static_cast<int>(result)) {
		double check = static_cast<double>(year) / 100;
		if (check != static_cast<int>(check))
			return true;
		// std::cout << "is a leap year" << std::endl;
	}
	// std::cout << "is not a leap year" << std::endl;
	return false;
}

size_t	BitcoinExchange::toNumber(std::string& input)
{
	std::stringstream	ss(input);
	size_t	n = 0;
	ss >> n;
	return n;
}

void	BitcoinExchange::checkSpaces()
{
	int	n = 0;

	for (size_t i = 0; i < line.length(); i++) {
		if ((line[i] >= 9 && line[i] <= 13))
			throw "bad input => " + this->line;

		if (line[i] == ' ') n++;
		if (n > 2)
			throw "bad input => " + this->line;
	}
}

bool	BitcoinExchange::matchregex(char c)
{
	char	arr[13] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '-', '.', 'f' };

	for (size_t i = 0; i < sizeof(arr); i++) {
		if (c == arr[i])
			return true;
	}
	return false;
}