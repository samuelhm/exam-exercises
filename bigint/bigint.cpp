//// BIGING.CPP /////
#include "bigint.hpp"

bigint::bigint() : num("0") {}
bigint::bigint(const bigint &copy) : num(copy.num) {}
bigint::bigint(unsigned long long Num) : num (std::to_string(Num)) {}
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
		carry = sum / 10;
		sum %= 10;

		if (i >= 0)
			num[i]= sum + '0';
		else
			num.insert(num.begin(), (sum + '0'));
		if (i >= 0)
			i--;
		if (j >= 0)
			j--;
	}
	if (carry != 0)
		num.insert(num.begin(), (carry + '0'));
	return *this;
}

bigint& bigint::operator++()
{
	*this += 1;
	return *this;
}
bigint bigint::operator++(int)
{
	bigint tmp(*this);
	*this += 1;
	return tmp;
}
bigint& bigint::operator>>=(const bigint& other)
{
	unsigned long long shift = 0;
	for (std::size_t i = 0; i < other.num.size(); i++)
		shift = shift * 10 + (other.num[i] - '0');
	return (*this >>= shift);
}


bigint& bigint::operator<<=(unsigned long long shift)
{
	if (shift == 0 || num == "0")
		return *this;
	num.append(shift, '0');
	return *this;
}
bigint& bigint::operator>>=(unsigned long long shift)
{
	if (shift >= num.size())
	{
		num = "0";
		return *this;
	}
	while(shift--)
		num.pop_back();
	return *this;
}
bool bigint::operator<(const bigint& other) const
{
	if (num.size() != other.num.size())
		return num.size() < other.num.size();
	int end = num.size() -1;
	int i = -1;
	while (++i != end)
		if (num[i] == other.num[i])
			continue;
		else
			return num[i] < other.num[i];
	if (num[i] == other.num[i])
		return false;
	else
		return num[i] < other.num[i];
}
bool bigint::operator==(const bigint& other) const
{
	return num == other.num;
}

bool bigint::operator<=(const bigint& other) const { return (*this == other || *this < other); }
bool bigint::operator>(const bigint& other) const {	return other < *this; }
bool bigint::operator>=(const bigint& other) const { return (*this > other || *this == other); }
bool bigint::operator!=(const bigint& other) const { return !(*this == other); }

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

bigint operator<<(bigint value, unsigned long long shift)
{
	value <<= shift;
	return value;
}

bigint operator>>(bigint value, unsigned long long shift)
{
	value >>= shift;
	return value;
}