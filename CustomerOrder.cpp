/*
*****************************************************************************

Full Name  : Christian Ziyu Ukiike
Student ID#: 139915219
Email      : czukiike-santos-delp@myseneca.ca
Date of completion    : 4/3/24

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*****************************************************************************
*/
#include "CustomerOrder.h"
#include "Utilities.h"
#include<iostream>
#include<iomanip>

namespace seneca {
	size_t CustomerOrder::m_widthField = 0;
	CustomerOrder::CustomerOrder(const std::string& rec)
	{
		Utilities utils;
		size_t next_pos = 0;
		bool more = true;
		size_t count = 0;

		// Parse tokens to determine m_cntItem and calculate m_widthField
		while (more)
		{
			utils.extractToken(rec, next_pos, more);
			count++;
		}
		m_cntItem = count - 2;
		delete[] m_lstItem;
		// Allocate memory for m_lstItem based on m_cntItem
		m_lstItem = new Item * [m_cntItem];

		// Reset next_pos and more for parsing tokens again
		next_pos = 0;
		more = true;
		for (size_t i = 0; i < count; i++)
		{
			std::string itemStr;
			itemStr = utils.trim(utils.extractToken(rec, next_pos, more));
			if (i == 0) {
				m_name = itemStr;
			}
			else if (i == 1) {
				m_product = itemStr;
			}
			else {
				m_lstItem[i - 2] = new Item(itemStr);
			}
		}
		m_widthField = m_widthField > utils.getFieldWidth() ? m_widthField : utils.getFieldWidth();
	}
	CustomerOrder::CustomerOrder(CustomerOrder& src)
	{
		throw "ERROR: Cannot make copies.";
	}
	CustomerOrder::CustomerOrder(CustomerOrder&& src) noexcept
	{
		*this = std::move(src);
	}
	CustomerOrder& CustomerOrder::operator=(CustomerOrder&& src) noexcept
	{
		if (this != &src)
		{
			// Clean up existing resources
			for (size_t i = 0; i < m_cntItem; i++) {
				delete m_lstItem[i];
			}
			delete[] m_lstItem;

			// Move member variables
			m_name = src.m_name;
			m_product = src.m_product;
			m_widthField = src.m_widthField;
			m_cntItem = src.m_cntItem;
			m_lstItem = src.m_lstItem;
			src.m_product.clear();
			src.m_name.clear();
			src.m_cntItem = 0;
			src.m_lstItem = nullptr;
		}
		return *this;
	}

	CustomerOrder::~CustomerOrder()
	{

		for (size_t i = 0; i < m_cntItem; ++i) {
			delete m_lstItem[i];
		}
		// Deallocate memory for the array itself
		delete[] m_lstItem;

	}
	bool CustomerOrder::isOrderFilled() const
	{
		bool allFilled{ true };

		for (size_t i = 0; i < m_cntItem  && allFilled; i++)
		{
			if (!m_lstItem[i]->m_isFilled)
			{
				allFilled=false; // If any item is not filled, return false
			}
		}
		return allFilled;
	}

	bool CustomerOrder::isItemFilled(const std::string& itemName) const
	{
		bool allFilled{ true };
		for (size_t i = 0; i < m_cntItem&&allFilled; i++)
		{
			if (m_lstItem[i]->m_itemName == itemName && !m_lstItem[i]->m_isFilled)
			{
				return false;
			}
		}
		// If the item doesn't exist in the order, return true.
		return allFilled;
	}

	void CustomerOrder::fillItem(Station& station, std::ostream& os)
	{
		// Check if the order contains the item handled by the station
		const auto& station_name = station.getItemName();
		for (size_t i = 0; i < m_cntItem; ++i)
			if (m_lstItem[i]->m_itemName == station_name) {
				if (!m_lstItem[i]->m_isFilled && station.getQuantity() > 0) {
					m_lstItem[i]->m_isFilled = true;
					station.updateQuantity();
					m_lstItem[i]->m_serialNumber = station.getNextSerialNumber();
					os << "    Filled " << m_name << ", " << m_product << " [" << station_name << "]\n";
					return;
				}

				if (!m_lstItem[i]->m_isFilled && !station.getQuantity())
					os << "    Unable to fill " << m_name << ", " << m_product
					<< " [" << station_name << "]\n";
			}
	}



	void CustomerOrder::display(std::ostream& os) const
	{
		os << std::left << m_name << " - " << m_product << std::endl;
		for (size_t i = 0; i < m_cntItem; ++i) {
			os << "[" << std::setw(6) << std::right << std::setfill('0') << m_lstItem[i]->m_serialNumber << "] "
				<< std::setw(m_widthField - 2) << std::setfill(' ')
				<< std::left << m_lstItem[i]->m_itemName << " - "
				<< (m_lstItem[i]->m_isFilled ? "FILLED" : "TO BE FILLED") << std::endl;
		}
	}

}

