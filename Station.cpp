/*
*****************************************************************************

Full Name  : Christian Ziyu Ukiike
Student ID#: 139915219
Email      : czukiike-santos-delp@myseneca.ca
Date of completion    : 3/14/24

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*****************************************************************************
*/
#include "Station.h"
#include<iostream>
#include<iomanip>
namespace seneca {
	char Utilities::m_delimiter = '\0';
	size_t Station::m_widthField = 0;
	size_t Station::id_generator = 0;
	Station::Station(const std::string& records)
	{
		Utilities utils;
		size_t next_pos = 0;
		bool more = true;
		m_id = ++id_generator;
		try {
			m_item = utils.trim(utils.extractToken(records, next_pos, more));
			m_serial = std::stoul(utils.extractToken(records, next_pos, more));
			m_qty = std::stoul(utils.extractToken(records, next_pos, more));
			m_desc = trim(utils.extractToken(records, next_pos, more));
			if (m_item.length() > m_widthField)
				m_widthField = m_item.length();
		}
		catch (const char* err) {
			std::cout << "   ERROR: " << err << std::endl;
		}





	}
	void Station::updateQuantity()
	{
		if (m_qty > 0)
		{
			--m_qty;
		}
	}
	void Station::display(std::ostream& os, bool full) const
	{
		os << "00" << m_id << " | "
			<< std::left << std::setw(15) << m_item << "| "
			<< std::right << std::setw(6) << std::setfill('0') << m_serial << std::setfill(' ')
			<< " | ";
		if (full)
			os << std::right << std::setw(4) << m_qty
			<< " | " << std::left << m_desc;
		os << std::endl;

	}
	std::string Station::trim(const std::string str) const
	{
		size_t
			first = str.find_first_not_of(" \t"),
			last = str.find_last_not_of(" \t") + 1;

		return str.substr(first, !first ? last : last - first);
	}
	void Station::displayAvailableItems(std::ostream& os) const
	{
		os << "Station ID: " << m_id << "\n";
		os << "Available Items: " << m_item << "\n";
	}
	size_t Station::getId() const
	{
		return m_id;
	}
}

