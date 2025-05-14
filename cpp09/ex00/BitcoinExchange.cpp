/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 18:49:37 by tkeil             #+#    #+#             */
/*   Updated: 2025/05/14 18:54:52 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(const char *file) : _data(DATA), _input(file)
{
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) : _data(other._data), _input(other._input), _data_map(other._data_map)
{
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
    if (this == &other)
        return (*this);
    _data = other._data;
    _input = other._input;
    _data_map = other._data_map;
    return (*this);
}

BitcoinExchange::~BitcoinExchange()
{
}

void BitcoinExchange::openFile(std::ifstream &stream, std::string &file)
{
    stream.open(file, std::ifstream::in);
    if (!stream.is_open())
        throw Open_File();
}

bool BitcoinExchange::extractNumber(std::string const &balance, float &val)
{
    size_t pos = 0;
    try
    {
        val = std::stof(balance, &pos);
        if (pos != balance.size())
            return false;
        return true;
    }
    catch (...)
    {
        return false;
    }
}

bool BitcoinExchange::isValidDate(std::string const &str)
{
    int y, m, d;
    char sep1, sep2;
    std::tm timeinfo =  {};
    std::istringstream ss(str);

    if (str.size() != 10)
        return (false);
    for (size_t i = 0; i < 10; i++)
    {
        if (i != 4 && i != 7 && !std::isdigit(str[i]))
            return (false);
    }
    if (!(ss >> y >> sep1 >> m >> sep2 >> d))
        return (false);
    if (sep1 != '-' || sep2 != '-')
        return (false);
    timeinfo.tm_year = y - 1900;
    timeinfo.tm_mon = m - 1;
    timeinfo.tm_mday = d;
    time_t rawtime = std::mktime(&timeinfo);
    if (rawtime == -1)
        return (false);
    return (timeinfo.tm_year == y - 1900 &&
            timeinfo.tm_mon == m - 1 &&
            timeinfo.tm_mday == d);
}

void BitcoinExchange::read_data()
{
    float val;
    std::ifstream data;
    std::string line, date, rate;
    size_t number_of_rates = 0;
    
    openFile(data, _data);
    std::getline(data, line);
    while (std::getline(data, line))
    {
        date.clear();
        rate.clear();
        std::istringstream ss(line);
        if (std::getline(ss, date, ',') && std::getline(ss, rate))
        {
            date.erase(date.find_last_not_of(" \t\r\f\v\n") + 1);
            date.erase(0, date.find_first_not_of(" \t\r\f\v\n"));
            rate.erase(rate.find_last_not_of(" \t\r\f\v\n") + 1);
            rate.erase(0, rate.find_first_not_of(" \t\r\f\v\n"));
        }
        if (!isValidDate(date))
        {
            data.close();
            throw Invalid_Date();
        }
        else if (rate.empty() || !rate.size() || !extractNumber(rate, val))
        {
            data.close();
            throw Invalid_Rate();
        }
        else
            number_of_rates++;
        _data_map[date] = val;
    }
    if (!number_of_rates)
    {
        data.close();
        throw No_Rates();
    }
    data.close();
}

float BitcoinExchange::getRate(std::string const &date)
{
    std::map<std::string, float>::iterator it = _data_map.lower_bound(date);
    if (it == _data_map.end() || it->first != date)
    {
        if (it != _data_map.begin())
            --it;
    }
    return (it->second);
}

void BitcoinExchange::printValues()
{
    std::ifstream input;
    std::string line, date, balance;
    
    openFile(input, _input);
    std::getline(input, line);
    while (std::getline(input, line))
    {
        float val;
        date.clear();
        balance.clear();
        std::istringstream ss(line);
        if (std::getline(ss, date, '|') && std::getline(ss, balance))
        {
            date.erase(date.find_last_not_of(" \t\r\f\v\n") + 1);
            date.erase(0, date.find_first_not_of(" \t\r\f\v\n"));
            balance.erase(balance.find_last_not_of(" \t\r\f\v\n") + 1);
            balance.erase(0, balance.find_first_not_of(" \t\r\f\v\n"));
        }
        if (!isValidDate(date))
        {
            std::cerr << "Error: bad input => " << date << std::endl;
            continue;
        }
        if (date < _data_map.begin()->first)
        {
            std::cerr << "Error: no exchange rate available before " << _data_map.begin()->first << std::endl;
            continue;
        }
        if (balance.empty() || !balance.size() || !extractNumber(balance, val))
        {
            std::cerr << "Error: not a number => " << balance << std::endl;
            continue;
        }
        if (val > 1000)
        {
            std::cerr << "Error: too large a number\n";
            continue;
        }
        if (val < 0)
        {
            std::cerr << "Error: not a positive number\n";
            continue;
        }
        float rate = getRate(date);
        if (val != 0 && rate > std::numeric_limits<float>::max() / val)
            std::cerr << "rate * val causes overflow\n";
        else
            std::cout << date << " => " << val << " = " << rate * val << std::endl;
    }
    input.close();
}

void BitcoinExchange::run()
{
    read_data();
    printValues();
}

const char *BitcoinExchange::Open_File::what() const throw()
{
    return ("Error: Couldn't open file!");
}

const char *BitcoinExchange::Invalid_Rate::what() const throw()
{
    return ("Error: Invalid exchange rate in btc_data!");
}

const char *BitcoinExchange::Invalid_Date::what() const throw()
{
    return ("Error: Invalid date format in btc_data!");
}

const char *BitcoinExchange::No_Rates::what() const throw()
{
    return ("Error: No available rates inside data.csv!");
}
