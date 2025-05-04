/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 18:50:53 by tkeil             #+#    #+#             */
/*   Updated: 2025/05/04 13:14:10 by tkeil            ###   ########.fr       */
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

#define DATA "account_data"

class BitcoinExchange
{
private:
    BitcoinExchange();
    std::string _data;
    std::string _input;
    std::map<std::string, float> _data_map;
    std::map<std::string, float> _input_map;
    
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

    class COULD_NOT_OPEN_FILE_EXCEPTION : public std::exception
    {
    public:
        const char *what() const throw();
    };
    
};

#endif
