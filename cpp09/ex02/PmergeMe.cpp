/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 18:00:44 by tkeil             #+#    #+#             */
/*   Updated: 2025/05/05 20:29:03 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
}

PmergeMe::PmergeMe(int argc, char **arg)
{
    if (argc > 2)
    {
        for (int i = 0; i < argc; ++i)
            temp.push_back(extractNum(arg[i]));
    }
    else
    {
        std::string input(arg[0]);
        std::regex del("\\s+");
        std::sregex_token_iterator it(input.begin(), input.end(), del, -1);
        std::sregex_token_iterator end;
        while (it != end)
        {
            temp.push_back(extractNum(*it));
            ++it;
        }
    }
    run();
}

PmergeMe::PmergeMe(const PmergeMe &other) : temp(other.temp), main(other.main), pend(other.pend)
{
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
    if (this == &other)
        return *this;
    temp = other.temp;
    main = other.main;
    pend = other.pend;
    return *this;
}

PmergeMe::~PmergeMe()
{
}

int PmergeMe::extractNum(std::string const &str)
{
    size_t pos;

    try
    {
        int i = std::stoi(str, &pos);
        if (pos == str.length() && i >= 0)
            return (i);
    }
    catch (...)
    {
    }
    throw Error();
}

void PmergeMe::run()
{
    std::cout << "Before: ";
    for (size_t i = 0; i < temp.size(); i++)
        std::cout << temp[i] << " ";
    std::cout << std::endl;

    for (size_t i = 0; i < temp.size(); i += 2)
    {
        int first = temp[i];
        if (i < temp.size() - 1)
        {
            int second = temp[i + 1];
            pend.push_back(std::min(first, second));
            main.push_back(std::max(first, second));
        }
        else
            main.push_back(first);
    }
    pend.sort();
    std::sort(main.begin(), main.end());
    auto it = main.begin();
    for (int val : pend)
    {
        it = std::lower_bound(it, main.end(), val);
        main.insert(it, val);
    }

    std::cout << "After:  ";
    for (size_t i = 0; i < main.size(); i++)
        std::cout << main[i] << " ";
    std::cout << std::endl;
}

const char *PmergeMe::Error::what() const throw()
{
    return ("Error");
}
