/////BIGINT.HPP////
#pragma once
#include <string>
#include <ostream>

class bigint
{
	private:
		std::string num;
		void normalize();
	public:
		bigint();
		bigint(const bigint &copy);
		bigint(unsigned long long Num);

		bigint& operator+=(const bigint& other);
		bigint& operator<<=(unsigned long long shift);
		bigint& operator>>=(unsigned long long shift);
		bigint& operator++();
		bigint 	operator++(int);
		bigint& operator>>=(const bigint& other);
		bool operator<(const bigint& other) const;
		bool operator==(const bigint& other) const;
		bool operator<=(const bigint& other) const;
		bool operator>(const bigint& other) const;
		bool operator>=(const bigint& other) const;
		bool operator!=(const bigint& other) const;




		friend std::ostream& operator<<(std::ostream& os, const bigint& Num);

};

bigint operator+(bigint big1, const bigint& big2);
bigint operator<<(bigint value, unsigned long long shift);
bigint operator>>(bigint value, unsigned long long shift);
