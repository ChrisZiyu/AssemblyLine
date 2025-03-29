/*
*****************************************************************************

Full Name  : Christian Ziyu Ukiike
Student ID#: 139915219
Email      : czukiike-santos-delp@myseneca.ca
Date of completion    : 3/24/24

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*****************************************************************************
*/
#ifndef SENECA_STATION_H
#define SENECA_STATION_H
#include<string>
#include"Utilities.h"

namespace seneca {
	class Station {
		size_t m_id{};
		std::string m_item{};
		std::string m_desc{};
		size_t m_serial{};
		unsigned int m_qty{};
		static size_t m_widthField;
		static size_t id_generator;
	public:

		Station(const std::string& records);
		const std::string& getItemName() const { return m_item; }
		size_t getNextSerialNumber() { return m_serial++; }
		size_t getQuantity() const { return m_qty; }
		void updateQuantity();
		void display(std::ostream& os, bool full) const;
		std::string trim(const std::string str) const;
		void displayAvailableItems(std::ostream& os) const;
		size_t getId() const;
	};
}
#endif // !SENECA_STATION_H
