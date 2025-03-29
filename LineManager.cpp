/*
*****************************************************************************

Full Name  : Christian Ziyu Ukiike
Student ID#: 139915219
Email      : czukiike-santos-delp@myseneca.ca
Date of completion    : 4/3/24

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*****************************************************************************
*/
#include "LineManager.h"
#include"fstream"
#include<sstream>
#include<algorithm>
#include <string>
#include<iostream>

using namespace std;

namespace seneca {
	LineManager::LineManager(const std::string& file, const std::vector<Workstation*>& stations) {
		std::ifstream instream(file);
		if (!instream) {
			throw std::runtime_error("Failed to open file " + file);
		}

		std::string a_line;
		while (std::getline(instream, a_line)) {
			std::istringstream istring(a_line);
			std::string workstationName, nextWorkstationName;

			if (std::getline(istring, workstationName, '|')) {
				if (!workstationName.empty()) {
					auto it = std::find_if(stations.begin(), stations.end(), [&](const Workstation* station) {
						return station->getItemName() == workstationName;
						});
					Workstation* currentStation = *it;
					if (it != stations.end()) {
						if (std::getline(istring, nextWorkstationName) && !nextWorkstationName.empty()) {
							auto nextIt = std::find_if(stations.begin(), stations.end(), [&](const Workstation* station) {
								return station->getItemName() == nextWorkstationName;
								});
							if (nextIt != stations.end()) {
								currentStation->setNextStation(*nextIt);
							}
							else {
								throw std::runtime_error("Next workstation not found: " + nextWorkstationName);
							}
						}
						if (nextWorkstationName.empty())
						{
							currentStation->setNextStation(nullptr);
						}
						m_activeLine.push_back(currentStation);
					}
				}
			}
			m_cntCustomerOrder++;

		}
		// Find the first station in the assembly line
		auto firstStationIter = m_activeLine.begin();

		if (firstStationIter != m_activeLine.end()) {
			m_firstStation = *firstStationIter;
		}
		else {
			throw std::runtime_error("No first station found in file: " + file);
		}
		m_cntCustomerOrder = g_pending.size();
	}
	void LineManager::reorderStations() {
		const auto last_station = std::find_if(m_activeLine.begin(), m_activeLine.end(), [](const Workstation* station) {
			return !(station->getNextStation());
			});

		std::swap(*last_station, m_activeLine.back());
		const std::string* station_ptr = &(m_activeLine.back()->getItemName());

		for (size_t i = m_activeLine.size() - 1; i > 0; --i) {
			const auto matching_station = std::find_if(m_activeLine.begin(), m_activeLine.end(), [&station_ptr](const Workstation* innerStation) {
				return innerStation->getNextStation()->getItemName() == *station_ptr;
				});

			std::swap(*matching_station, m_activeLine[i - 1]);
			station_ptr = &(m_activeLine[i - 1]->getItemName());
		}

		m_firstStation = m_activeLine.front();
	}
	bool LineManager::run(std::ostream& os)
	{
		static auto count = 1;
		static const auto max_order = g_pending.size();
		os << "Line Manager Iteration: " << count << endl;
		if (!g_pending.empty())
		{
			*m_firstStation += move(g_pending.front());
			g_pending.pop_front();
		}
		for_each(m_activeLine.begin(), m_activeLine.end(), [&os](Workstation* station) {
			station->fill(os);
			});
		for_each(m_activeLine.begin(), m_activeLine.end(), [](Workstation* station) {
			station->attemptToMoveOrder();
			});
		++count;
		return g_completed.size() + g_incomplete.size() == max_order;
	}
	void LineManager::display(std::ostream& os) const
	{
		for_each(m_activeLine.begin(), m_activeLine.end(), [&](Workstation* station) {
			station->display(os);
			});
	}


}

