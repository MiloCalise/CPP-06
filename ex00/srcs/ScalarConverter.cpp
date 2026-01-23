/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miltavar <miltavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 17:41:00 by miltavar          #+#    #+#             */
/*   Updated: 2026/01/23 15:43:26 by miltavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScalarConverter.hpp"

static bool	isPseudo(const std::string& litteral)
{
	return (litteral == "nan" || litteral == "+inf" || litteral == "-inf" || litteral == "nanf" || litteral == "+inff" || litteral == "-inff");
}

static bool	isChar(const std::string& litteral)
{
	return (litteral.length() == 1 && isprint(litteral[0]) && !isdigit(litteral[0]));
}

static bool	isInt(const std::string& litteral)
{
	int	i = 0;
	int	len = litteral.length();

	if (litteral[i] == '-' || litteral[i] == '+')
		i++;
	if (len == i)
		return (0);
	while (i < len)
	{
		if (!isdigit(litteral[i]))
			return (0);
		i++;
	}
	return (1);
}

static bool	isFloat(const std::string& litteral)
{
	char	*end;

	if (litteral.empty() || litteral[litteral.length() - 1] != 'f')
		return (0);
	errno = 0;
	strtof(litteral.c_str(), &end);
	if (*end != 'f' || *(end + 1) != '\0')
		return (0);
	return (litteral.find('.') != std::string::npos);
}

static bool	isDouble(const std::string& litteral)
{
	char	*end;

	if (litteral.empty() || litteral[litteral.length() - 1] == 'f')
		return (0);
	errno = 0;
	strtod(litteral.c_str(), &end);
	if (*end != '\0')
		return (0);
	return (litteral.find('.') != std::string::npos);
}

static void	error()
{
	std::cerr << "Conversion is impossible" << std::endl;
}

static void	doublee(const std::string& litteral)
{
	char	*end;
	errno = 0;
	double	a = strtod(litteral.c_str(), &end);

	if (errno == ERANGE || a < 32 || a > 126)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: " << static_cast<char>(a) << std::endl;
	if (errno == ERANGE || a < std::numeric_limits<int>::min() || a > std::numeric_limits<int>::max())
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(a) << std::endl;
	std::cout << "float: " << static_cast<float>(a) << "f" << std::endl;
	std::cout << "double: " << a << std::endl;
}

static void	floatt(const std::string& litteral)
{
	char	*end;
	errno = 0;
	float	a = strtof(litteral.c_str(), &end);

	if (errno == ERANGE || a < 32 || a > 126)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: " << static_cast<char>(a) << std::endl;
	if (errno == ERANGE || a < std::numeric_limits<int>::min() || a > std::numeric_limits<int>::max())
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(a) << std::endl;
	std::cout << "float: " << a << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(a) << std::endl;
}

static void	integer(const std::string& litteral)
{
	char	*end;
	errno = 0;
	long	a = strtol(litteral.c_str(), &end, 10);

	if (errno == ERANGE || a < 32 || a > 126)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: " << static_cast<char>(a) << std::endl;
	if (errno == ERANGE || a < std::numeric_limits<int>::min() || a > std::numeric_limits<int>::max())
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << a << std::endl;
	std::cout << "float: " << static_cast<float>(a) << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(a) << std::endl;
}

static void	chara(const std::string& litteral)
{
	char	a = litteral[0];

	std::cout << "char: " << a << std::endl;
	std::cout << "int " << static_cast<int>(a) << std::endl;
	std::cout << "float: " << static_cast<float>(a) << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(a) << std::endl;
}

static void	pseudo(const std::string& litteral)
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	if (litteral[litteral.length() - 1] == 'f')
		std::cout << "float: " << litteral << std::endl;
	else
		std::cout << "float: " << litteral << "f" << std::endl;
	std::cout << "double: " << litteral << std::endl;
}

void	ScalarConverter::convert(const std::string& litteral)
{
	std::cout << std::fixed << std::setprecision(1);

	if (isPseudo(litteral))
		pseudo(litteral);
	else if (isChar(litteral))
		chara(litteral);
	else if (isInt(litteral))
		integer(litteral);
	else if (isFloat(litteral))
		floatt(litteral);
	else if (isDouble(litteral))
		doublee(litteral);
	else
		error();
}
