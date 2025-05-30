/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 19:22:03 by tkeil             #+#    #+#             */
/*   Updated: 2025/05/14 19:22:17 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN()
{
}

RPN::RPN(const char *arg)
{
    run(arg);
}

RPN::RPN(const RPN &other) : stack(other.stack)
{
}

RPN &RPN::operator=(const RPN &other)
{
    if (this == &other)
        return *this;
    stack = other.stack;
    return *this;
}

RPN::~RPN()
{
}

int RPN::extractNum(std::string const &str)
{
    size_t pos;

    try
    {
        int i = std::stoi(str, &pos);
        if (pos == str.length())
            return (i);
    }
    catch (...)
    {
    }
    throw Error();
}

int RPN::add(const int &a, const int &b)
{
    if ((b > 0 && a > std::numeric_limits<int>::max() - b) ||
        (b < 0 && a < std::numeric_limits<int>::min() - b))
        throw Overflow();
    return (a + b);
}

int RPN::substract(const int &a, const int &b)
{
    if ((b < 0 && a > std::numeric_limits<int>::max() + b) ||
        (b > 0 && a < std::numeric_limits<int>::min() + b))
        throw Overflow();
    return (a - b);
}

int RPN::multiply(const int &a, const int &b)
{
    if (a > 0)
    {
        if (b > 0 && a > std::numeric_limits<int>::max() / b)
            throw Overflow();
        if (b < 0 && b < std::numeric_limits<int>::min() / a)
            throw Overflow();
    }
    else if (a < 0)
    {
        if (b > 0 && a < std::numeric_limits<int>::min() / b)
            throw Overflow();
        if (b < 0 && a < std::numeric_limits<int>::max() / b)
            throw Overflow();
    }
    return (a * b);
}

int RPN::divide(const int &a, const int &b)
{
    if (b == 0)
        throw Division();
    if (a == std::numeric_limits<int>::min() && b == -1)
        throw Overflow();
    return (a / b);
}

int RPN::switchIt(const char c, const int &a, const int &b)
{
    switch (c)
    {
    case '+':
        return (add(a, b));
    case '-':
        return (substract(a, b));
    case '*':
        return (multiply(a, b));
    case '/':
        return (divide(a, b));
    default:
        throw Error();
    }
}

void RPN::run(const char *arg)
{
    std::string str(arg);

    std::regex del("\\s+");
    std::sregex_token_iterator it(str.begin(), str.end(), del, -1);
    std::sregex_token_iterator end;
    while (it != end)
    {
        std::string tok = *it;
        if (tok.length() == 1 && tok.find_first_of("+-*/") != std::string::npos)
        {
            if (stack.size() < 2)
                throw Error();
            int top1 = stack.top();
            stack.pop();
            int top2 = stack.top();
            stack.pop();
            stack.push(switchIt(tok[0], top2, top1));
        }
        else
            stack.push(extractNum(tok));
        ++it;
    }
    if (stack.size() != 1)
        throw Error();
    std::cout << stack.top() << '\n';
}

const char *RPN::Error::what() const throw()
{
    return ("Error: Invalid input");
}

const char *RPN::Overflow::what() const throw()
{
    return ("Error: Overflow");
}

const char *RPN::Division::what() const throw()
{
    return ("Error: Division by zero");
}
