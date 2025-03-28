/*
*****************************************************************************

Full Name  : Christian Ziyu Ukiike
Student ID#: 139915219
Email      : czukiike-santos-delp@myseneca.ca
Date of completion    : 4/3/24

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*****************************************************************************
*/
#include "Workstation.h"
#include"CustomerOrder.h"
#include<memory>
#include<iostream>
namespace seneca {
	std::deque<CustomerOrder> g_pending;
	std::deque<CustomerOrder> g_completed;
	std::deque<CustomerOrder> g_incomplete;
	void Workstation::fill(std::ostream& os)
	{
		if (!m_orders.empty())
		{
			m_orders.front().fillItem(*this, os);
		}
	}
	bool Workstation::attemptToMoveOrder()
	{
		if (!m_orders.empty()) {
			CustomerOrder& order = m_orders.front();

			if (order.isItemFilled(getItemName()) || !getQuantity()) {
				if (!m_pNextStation) {
					if (order.isOrderFilled()) {
						g_completed.push_back(std::move(order));
						m_orders.pop_front();
						return true;
					}

					else {
						g_incomplete.push_back(std::move(order));
						m_orders.pop_front();
						return true;
					}
				}

				m_pNextStation->m_orders.push_back(std::move(order));
				m_orders.pop_front();
				return true;
			}
		}

		return false;
	}
	void Workstation::setNextStation(Workstation* station)
	{
		m_pNextStation = station;
	}
	Workstation* Workstation::getNextStation() const
	{
		return m_pNextStation;
	}
	void Workstation::display(std::ostream& os) const
	{
		if (m_pNextStation == nullptr)
		{
			os << getItemName() << " --> End of Line\n";
		}
		else {
			os << getItemName() << " --> " << m_pNextStation->getItemName() << std::endl;
		}

	}
	Workstation& Workstation::operator+=(CustomerOrder&& newOrder)
	{
		m_orders.push_back(std::move(newOrder));
		return *this;
	}

}

