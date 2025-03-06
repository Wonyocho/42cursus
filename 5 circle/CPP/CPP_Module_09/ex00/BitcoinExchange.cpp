#include "BitcoinExchange.hpp"
#include <sstream>
#include <stdexcept>
#include <iomanip>

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& rhs) { *this = rhs; }

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& rhs)
{
    if (this != &rhs)
    exchangeRates = rhs.exchangeRates;
	return (*this);
}

BitcoinExchange::~BitcoinExchange() {}




bool BitcoinExchange::isNumber(const std::string &value)
{
    char *endptr; // 엔드포인터: 변환되지 않은 문자열을 가리킨다. 끝까지 변환 완료시 NULL.
    double val = strtod(value.c_str(), &endptr); // 변환된 값.

    return (endptr != value.c_str() && *endptr == '\0' && val >= 0);    
}

bool BitcoinExchange::isValidDate(const std::string &date)
{
    // 에러 처리
    // ex) 2021-01-01
    if (date.size() != 10 || date[4] != '-' || date[7] != '-')
        return (false);
    int year = atoi(date.substr(0, 4).c_str());
    int month = atoi(date.substr(5, 2).c_str());
    int day = atoi(date.substr(8, 2).c_str());
    if (month < 1 || month > 12 || day < 1)
        return (false);

    // 윤년
    if (month == 2 && day == 29)
    {
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
            return (true);
        else
            return (false);
    }

    int max_day[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    return (day <= max_day[month - 1]);
}

// 특정 date의 비트코인 환율 리턴.
double BitcoinExchange::getExchangeRate(const std::string &date)
{
    std::map<std::string, double>::iterator it = exchangeRates.lower_bound(date); // lower_bound: std::map에서 특정 키 이상의 가장 가까운 키를 찾는 함수.

    // date보다 작은 값이 존재하지 않으면
    if (it == exchangeRates.begin() && it->first != date)
        throw std::logic_error("Error: no exchange rate available for date => " + date);

    // date보다 큰값이 존재하지 않으면
    if (it == exchangeRates.end() || it->first != date)
        --it;

    return it->second;
}





void BitcoinExchange::parseDB(const std::string& dataFile)
{
    std::ifstream DB(dataFile.c_str());
    if (!DB.is_open())
    {
        throw std::logic_error("Error: could not open data file.");
    }

    std::string line;
    std::getline(DB, line); // 첫줄은 스킵

    while (std::getline(DB, line))
    {
        std::istringstream lineStream(line);
        std::string date, value;

        // ',' 기준으로 date, value
        if (!std::getline(lineStream, date, ',') || !std::getline(lineStream, value))
        {
            continue;
        }
        if (!isValidDate(date))
        {
            throw std::logic_error("Error: incorrect date => " + date);
        }
        if (!isNumber(value))
        {
            throw std::logic_error("Error: incorrect value => " + value);
        }

        exchangeRates[date] = strtod(value.c_str(), NULL); // 
    }
    DB.close();
}




void BitcoinExchange::exchangeBTC(const std::string &inputFile)
{
    std::ifstream input(inputFile.c_str());
    if (!input.is_open())
    {
        throw std::logic_error("Error: could not open file.");
    }

    std::string line;
    std::getline(input, line); // 첫줄 스킵

    while (std::getline(input, line))
    {
        try {
            std::istringstream lineStream(line);
            std::string date, valueStr;

            // '|' 기준으로 date, value
            if (!std::getline(lineStream, date, '|') || !std::getline(lineStream, valueStr))
                throw std::logic_error("Error: bad input => " + line);

            date = date.substr(0, date.size() - 1); // date 뒤에 공백 제거
            valueStr = valueStr.substr(1); // value 앞 공백 제거

            // 에러 처리
            if (!isValidDate(date)) throw std::logic_error("Error: incorrect date => " + date);
            if (!isNumber(valueStr)) throw std::logic_error("Error: not a positive number.");

            // exchange
            double value = strtod(valueStr.c_str(), NULL);
            if (value < 0)
                throw std::logic_error("Error: not a positive number.");
            if (value > 1000)
                throw std::logic_error("Error: too large a number.");

			double exchangeRate = getExchangeRate(date);
            double result = value * exchangeRate;

            std::cout << date << " => " << valueStr << " = " << result << std::endl;
        }
        catch (const std::exception &e) {
            std::cerr << e.what() << std::endl;
        }
    }
    input.close();
}
