#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

#include "Customer.hpp"

using namespace std;

Customer::Customer(std::string n, std::string a, bool pm)
{
	name = n;
	accountID = a;
	premiumMember = pm;
}

std::string Customer::getAccountID()
{
	return accountID;
}
std::vector<std::string> Customer::getCart()
{
	return cart;
}
void Customer::addProductToCart(std::string tempIdCode)
{
	cart.push_back(tempIdCode);
}
bool Customer::isPremiumMember()
{
	return premiumMember;
}
void Customer::emptyCart()
{
	cart.clear();
}
