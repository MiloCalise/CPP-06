/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miltavar <miltavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 14:09:13 by miltavar          #+#    #+#             */
/*   Updated: 2026/01/27 15:10:49 by miltavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/C.hpp"

Base::~Base()
{
}

Base	*generate(void)
{
	int rnbr = rand() % 3;

	if (rnbr == 0)
		return (new A);
	else if (rnbr == 1)
		return (new B);
	else if (rnbr == 2)
		return (new C);
	return (new A);
}

void	identify(Base *p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
}

void	identify(Base &r)
{
	try
	{
		(void)dynamic_cast<A&>(r);
		std::cout << "A" << std::endl;
		return ;
	}
	catch (...) {}
	try
	{
		(void)dynamic_cast<B&>(r);
		std::cout << "B" << std::endl;
		return ;
	}
	catch (...) {}
	try
	{
		(void)dynamic_cast<C&>(r);
		std::cout << "C" << std::endl;
		return ;
	}
	catch (...) {}
}
