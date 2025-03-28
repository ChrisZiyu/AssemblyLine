/*
*****************************************************************************

Full Name  : Christian Ziyu Ukiike
Student ID#: 139915219
Email      : czukiike-santos-delp@myseneca.ca
Date of completion    : 4/3/24

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*****************************************************************************
*/
#ifndef SENECA_WORKSTATION_H
#define SENECA_WORKSTATION_H
#include"Station.h"
#include"CustomerOrder.h"
#include<deque>

namespace seneca {
	extern std::deque<CustomerOrder> g_pending;
	extern std::deque<CustomerOrder> g_completed;
	extern std::deque<CustomerOrder> g_incomplete;

	class Workstation : public Station {
		std::deque<CustomerOrder>m_orders{};
		Workstation* m_pNextStation{};
	public:
		Workstation(const std::string str) : Station(str) {};
		void fill(std::ostream& os);
		bool attemptToMoveOrder();
		void setNextStation(Workstation* station);
		Workstation* getNextStation() const;
		void display(std::ostream& os) const;
		Workstation& operator+=(CustomerOrder&& newOrder);
	};
}
#endif // !SENECA_WORKSTATION_H
