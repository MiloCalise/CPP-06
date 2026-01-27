/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miltavar <miltavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 14:05:45 by miltavar          #+#    #+#             */
/*   Updated: 2026/01/27 15:06:07 by miltavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/C.hpp"

int	main(void)
{
	srand(time(NULL));

	Base	*p1 = generate();
	Base	*p2 = generate();

	identify(p1);
	identify(p2);

	identify(*p1);
	identify(*p2);

	delete p1;
	delete p2;
}
