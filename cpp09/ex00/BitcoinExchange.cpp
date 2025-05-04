/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 18:49:37 by tkeil             #+#    #+#             */
/*   Updated: 2025/05/04 13:16:21 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(const char *file) : _input(file), _data(DATA)
{
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) : _input(other._input), _data(other._data), _input_map(other._input_map), _data_map(other._data_map)
{
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
    if (this == &other)
        return (*this);
    _data = other._data;
    _input = other._input;
    _data_map = other._data_map;
    _input_map = other._input_map;
    return (*this);
}

BitcoinExchange::~BitcoinExchange()
{
}

void BitcoinExchange::openFile(std::ifstream &stream, std::string &file)
{
    stream.open(file, std::ifstream::in);
    if (!stream.is_open())
        throw COULD_NOT_OPEN_FILE_EXCEPTION();
}

bool BitcoinExchange::isValidDate(std::string const &str)
{
    int y, m, d;
    char sep1, sep2;
    struct tm * timeinfo;
    std::stringstream ss(str);

    if (!(ss >> y >> sep1 >> m >> sep2 >> d))
        return (false);
    if (sep1 != '-' || sep2 != '-')
        return (false);
    timeinfo->tm_year = y - 1900;
    timeinfo->tm_mon = m - 1;
    timeinfo->tm_mday = d;
    time_t rawtime = std::mktime(timeinfo);
    if (rawtime == -1)
        return (false);
    return (timeinfo->tm_year == y - 1900 &&
            timeinfo->tm_mon == m - 1 &&
            timeinfo->tm_mday == d);
}

void BitcoinExchange::read_data()
{
    float val;
    std::ifstream data;
    std::string line, date, rate;
    
    openFile(data, _data);
    while (std::getline(data, line))
    {
        std::stringstream ss(line);
        if (std::getline(ss, date, ',') && std::getline(ss, rate))
        {
            date.erase(0, date.find_last_not_of(" \t\r\f\v\n"));
            date.erase(0, date.find_first_not_of(" \t\r\f\v\n"));
            rate.erase(0, rate.find_last_not_of(" \t\r\f\v\n"));
            rate.erase(0, rate.find_first_not_of(" \t\r\f\v\n"));
        }
        if (date.empty() || !isValidDate(date))
        {
            data.close();
            throw Invalid_Date();
        }
        std::stringstream ps(rate);
        if (!(ps >> val))
        {
            data.close();
            throw Invalid_Rate();
        }
        _data_map[date] = val;
    }
    data.close();
}

void BitcoinExchange::printValues()
{
    float val;
    std::ifstream input;
    std::string line, date, balance;
    
    openFile(input, _input);
    while (std::getline(input, line))
    {
        std::stringstream ss(line);
        if (std::getline(ss, date, ',') && std::getline(ss, balance))
        {
            date.erase(0, date.find_last_not_of(" \t\r\f\v\n"));
            date.erase(0, date.find_first_not_of(" \t\r\f\v\n"));
            balance.erase(0, balance.find_last_not_of(" \t\r\f\v\n"));
            balance.erase(0, balance.find_first_not_of(" \t\r\f\v\n"));
        }
        if (date.empty() || !isValidDate(date))
        {
            input.close();
            throw Invalid_Date();
        }
        std::stringstream ps(balance);
        if (!(ps >> val))
        {
            input.close();
            throw Invalid_Rate();
        }
        _data_map[date] = val;
    }
}

void BitcoinExchange::run()
{
    read_data();
    printValues();
}

const char *BitcoinExchange::COULD_NOT_OPEN_FILE_EXCEPTION::what() const throw()
{
    return ("Error: Couldn't open file\n");
}
