/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miltavar <miltavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 14:08:25 by miltavar          #+#    #+#             */
/*   Updated: 2026/01/27 15:00:41 by miltavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <time.h>
#include <stdlib.h>

class Base
{
public:
	virtual ~Base();
};

Base	*generate(void);

void	identify(Base *p);
void	identify(Base &p);
