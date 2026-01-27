/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miltavar <miltavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 13:27:11 by miltavar          #+#    #+#             */
/*   Updated: 2026/01/27 13:30:06 by miltavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stdint.h>

struct Data
{
	int	value;
};

class Serializer
{
public:
	static uintptr_t	serialize(Data	*ptr);
	static	Data	*deserialize(uintptr_t	raw);
};
