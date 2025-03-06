#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <fstream>
# include <sstream>
# include <cstdlib>
# include <map>

class BitcoinExchange
{
	private:
		std::map<std::string, double> exchangeRates;

		bool isNumber(const std::string& value);
		bool isValidDate(const std::string& date);
		double getExchangeRate(const std::string& date);

	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& rhs);
		BitcoinExchange& operator=(const BitcoinExchange& rhs);
		~BitcoinExchange();

		void parseDB(const std::string& dataFile);
		void exchangeBTC(const std::string& inputFile);
};

#endif