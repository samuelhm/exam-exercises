//// BIGING.CPP /////
#include "bigint.hpp"

bigint::bigint() : num("0") {}
bigint::bigint(const bigint &copy) : num(copy.num) {}
bigint::bigint(unsigned long long Num) : num (std::to_string(Num))
{
	normalize();
}
void bigint::normalize()
{
	if (num.size() <= 1)
		return ;
	while (num.size() > 1 && num[0] == '0')
		num.erase(num.begin());
}

bigint& bigint::operator+=(const bigint& other)
{
	int i = num.size() - 1;
	int j = other.num.size() - 1;
	int carry = 0;
	while(i >= 0 || j >= 0)
	{		
		int digit1 = (i >= 0) ? (num[i] - '0') : 0;
		int digit2 = (j >= 0) ? (other.num[j] - '0') : 0;
		int sum = digit1 + digit2 + carry;
		if (sum > 9)
		{
			carry = sum / 10;
			sum %= 10;
		}
		else
			carry = 0;
		if (i >= 0)
			num[i]= sum + '0';
		else
			num.insert(num.begin(), (char)(sum + '0'));
		if (i >= 0)
			i--;
		if (j >= 0)
			j--;
	}
	if (carry != 0)
		num.insert(num.begin(), (char)(carry + '0'));
	return *this;
}

bigint operator+(bigint big1, const bigint &big2)
{
	big1 += big2;
	return big1;
}

std::ostream& operator<<(std::ostream& os, const bigint& Num)
{
    os << Num.num;
    return os;
}

