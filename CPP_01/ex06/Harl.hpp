/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauragm <lauragm@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 21:26:52 by lauragm           #+#    #+#             */
/*   Updated: 2026/01/01 21:30:59 by lauragm          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_HPP

#include <string>

class Harl{
private:
	void debug(void);
	void info(void);
	void warning(void);
	void error(void);
	
public:
	void complain(std::string level);
};

#endif

