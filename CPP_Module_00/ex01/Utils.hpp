/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyocho <wonyocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 11:46:55 by wonyocho          #+#    #+#             */
/*   Updated: 2025/01/01 11:49:53 by wonyocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>
#include "PhoneBook.hpp"

bool isNumber(std::string s);
void show_pages(PhoneBook page[8]);
void show_privew(PhoneBook page[8]);
void select_index(PhoneBook page[8]);

#endif