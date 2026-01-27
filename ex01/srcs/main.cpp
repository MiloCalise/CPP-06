/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miltavar <miltavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 13:22:21 by miltavar          #+#    #+#             */
/*   Updated: 2026/01/27 14:05:03 by miltavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Serializer.hpp"

int	main(void)
{
	Data		d;
	Data		*ptr;
	uintptr_t	raw;

	raw = Serializer::serialize(&d);
	ptr = Serializer::deserialize(raw);

	std::cout << "adresse de d = " << &d << std::endl;
	std::cout << "ptr = " << ptr << std::endl;
}
