/*
*****************************************************************************

Full Name  : Christian Ziyu Ukiike
Student ID#: 139915219
Email      : czukiike-santos-delp@myseneca.ca
Date of completion    : 3/14/24

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*****************************************************************************
*/
#ifndef SENECA_UTILITIES_H
#define SENECA_UTILITIES_H
#include<string>


namespace seneca {
	class Utilities {


		size_t m_widthField = 1;
		static char m_delimiter;
	public:
		void setFieldWidth(size_t newWidth);
		size_t getFieldWidth() const;
		std::string extractToken(const std::string& str, size_t& next_pos, bool& more);
		static void setDelimiter(char newDelimiter);
		static char getDelimiter();
		std::string trim(const std::string str);

	};
}

#endif // !SENECA_UTILITIES_H
