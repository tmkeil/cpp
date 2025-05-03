/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 17:19:26 by tkeil             #+#    #+#             */
/*   Updated: 2025/05/03 14:30:42 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

template <typename Iterator>
void stackIterator(Iterator it_start, Iterator it_end)
{
    for (; it_start != it_end; ++it_start)
    {
        std::cout << *it_start << " ";
    }
    std::cout << std::endl;
}

int main()
{
	MutantStack<int> mstack;

    std::cout << "is empty: " << std::boolalpha << mstack.empty() << std::endl;
    
    std::cout << "pushing 2 numbers...\n";
	mstack.push(5);
	mstack.push(17);
    
    std::cout << "Printing the stack...\n";
    stackIterator(mstack.begin(), mstack.end());
    std::cout << "mstack top: " << mstack.top() << std::endl;

    mstack.pop();
    std::cout << "Printing the stack after pop...\n";
    stackIterator(mstack.begin(), mstack.end());
	std::cout << "Stack size: " << mstack.size() << std::endl;
    std::cout << std::endl;
    
    std::cout << "Pushing some numbers...\n";
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
    std::cout << "Printing the stack in several ways...\n";
    std::cout << "Standard iterator..." << std::endl;
    stackIterator(mstack.begin(), mstack.end());
    
    std::cout << "Constant iterator...\n";
    const MutantStack<int> constStack = mstack;
    stackIterator(constStack.begin(), constStack.end());
    
    std::cout << "Reverse iterator...\n";
    stackIterator(mstack.rbegin(), mstack.rend());
    
    std::cout << "Testing the copy contructor...\n";
    MutantStack<int> copy(mstack);
    
    std::cout << "Printing the copied stack...\n";
    stackIterator(copy.begin(), copy.end());
    
    std::cout << "Testing the assignment operator...\n";
    MutantStack<int> assigned = mstack;
    
    std::cout << "Printing the assigned stack...\n";
    stackIterator(assigned.begin(), assigned.end());
    

    std::cout << "\nTesting the std::list...\n";
    std::list<int> lst;
    lst.push_back(10);
    lst.push_back(20);
    lst.push_back(30);
    stackIterator(lst.begin(), lst.end());

    std::cout << "\nTesting the std::deque...\n";
    std::deque<int> deq;
    deq.push_back(10);
    deq.push_back(20);
    deq.push_back(30);
    stackIterator(deq.begin(), deq.end());

    std::cout << "\nTesting the std::map...\n";
    std::map<std::string, int> map;
    map["red"] = 3;
    map["green"] = 5;
    map["blue"] = 2;
    for (std::map<std::string, int>::iterator it = map.begin(); it != map.end(); ++it)
    {
        std::cout << it->first << ": " << it->second << std::endl;
    }
	return 0;
}
