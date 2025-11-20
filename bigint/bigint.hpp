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
		friend std::ostream& operator<<(std::ostream& os, const bigint& Num);

};

bigint operator+(bigint big1, const bigint& big2);
