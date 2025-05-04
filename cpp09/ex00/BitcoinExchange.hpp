/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 18:50:53 by tkeil             #+#    #+#             */
/*   Updated: 2025/05/04 19:06:32 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOIN_EXCHANGE_HPP
#define BITCOIN_EXCHANGE_HPP

#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <fstream>
#include <ctime>
#include <sstream>
#include <limits>

#define DATA "data.csv"

class BitcoinExchange
{
private:
    BitcoinExchange();
    std::string _data;
    std::string _input;
    std::map<std::string, float> _data_map;
    
public:
    BitcoinExchange(const char *file);
    BitcoinExchange(const BitcoinExchange &other);
    BitcoinExchange &operator=(const BitcoinExchange &other);
    ~BitcoinExchange();

    void run();
    void read_data();
    bool isValidDate(std::string const &str);
    void openFile(std::ifstream &stream, std::string &file);
    void printValues();
    float getRate(std::string const &date);
    bool extractNumber(std::string const &balance, float &val);

    class Open_File : public std::exception
    {
    public:
        const char *what() const throw();
    };
    class Invalid_Date : public std::exception
    {
    public:
        const char *what() const throw();
    };
    class Invalid_Rate : public std::exception
    {
    public:
        const char *what() const throw();
    };
};

#endif
