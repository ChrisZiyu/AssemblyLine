/*
*****************************************************************************

Full Name  : Christian Ziyu Ukiike
Student ID#: 139915219
Email      : czukiike-santos-delp@myseneca.ca
Date of completion    : 3/14/24

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*****************************************************************************
*/
#include "Utilities.h"
#include<sstream>
#include<string>
using namespace std;
namespace seneca {
	void Utilities::setFieldWidth(size_t newWidth)
	{
		m_widthField = newWidth;
	}
	size_t Utilities::getFieldWidth() const
	{
		return m_widthField;
	}

	string Utilities::extractToken(const std::string& str, size_t& next_pos, bool& more) {
		std::string token{};
		std::stringstream ss(str.substr(next_pos));
		if (std::getline(ss, token, m_delimiter)) {
			if (token.empty()) {
				more = false; // Set more to false if the token is empty and there's nothing more to read
				throw "Empty token found";
			}
			next_pos += token.length() + 1;
			more = next_pos < str.length(); // Check if there are more tokens to extract
			if (!more) {
				// If there are no more tokens, move next_pos past the delimiter
				next_pos += token.length() + 1;
			}
			if (token.length() > m_widthField)
				m_widthField = token.length();
		}
		else {
			more = false;
			if (!token.empty() && token[token.length() - 1] == m_delimiter)
				throw "Delimiter found at the end";
		}

		return token;
	}
	void Utilities::setDelimiter(char newDelimiter)
	{
		m_delimiter = newDelimiter;
	}
	char Utilities::getDelimiter()
	{
		return m_delimiter;
	}
	std::string Utilities::trim(const std::string str)
	{
		size_t
			first = str.find_first_not_of(" \t"),
			last = str.find_last_not_of(" \t") + 1;

		return str.substr(first, !first ? last : last - first);
	}
}

