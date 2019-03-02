#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

#include "Store.hpp"

void Store::addProduct(Product* p)
{
	Product* myP = p;
	inventory.push_back(myP);

}
void Store::addMember(Customer* c)
{
	Customer* myC = c;
	members.push_back(myC);

for (int i = 0; i < members.size(); i++)
	{
		cout << i << endl;
		cout << members.at(i) << endl;
	}
}
Product* Store::getProductFromID(std::string pID)
{
	std::string productID=pID;
	for (int i = 0;i < inventory.size();i++)
	{
		if (inventory.at(i)->getIdCode() == productID)
		{
			return inventory.at(i);
		}
		else
		{
			return NULL;
		}
	}
}
Customer* Store::getMemberFromID(std::string aID)
{
	std::string accountID = aID;
	for (int i = 0;i < members.size();i++)
	{
		if (members.at(i)->getAccountID() == accountID)   
			return members.at(i);
		else return NULL;
	}
}
void Store::productSearch(std::string str)
{

	std::string input = str;

	std::for_each(input.begin(), input.end(), [](char & c) {c = ::tolower(c);});

	for (int i = 0;i < inventory.size();i++) 
	{
		if (inventory.at(i)->getDescription().find(input) == std::string::npos); //if product not found, does nothing.

		else
		{
			std::cout << inventory.at(i)->getTitle() << endl;
			std::cout << "ID code: " << inventory.at(i)->getIdCode() << endl;
			std::cout << "price: " << inventory.at(i)->getPrice() << endl;
			std::cout << inventory.at(i)->getDescription() << endl;
		}
	}
}
void Store::addProductToMemberCart(std::string pID, std::string mID)
{
	std::string pInput = pID;
	std::string mInput = mID;
	int pTracker = 0;
	int mTracker = 0;
	

	for (int i = 0;i < inventory.size();i++) 
	{
		if (inventory.at(i)->getIdCode() == pInput)
		{
			for (int j = 0; j < members.size();j++)
			{
				if (members.at(j)->getAccountID() == mInput)
				{
					members.at(j)->addProductToCart(pInput);
				}
				else
				{
					mTracker = mTracker + 1;
				}
			}
		}
		else if (inventory.at(i)->getIdCode()!= pInput)
		{
			pTracker = pTracker + 1;

			for (int j = 0; j < members.size();j++)
			{
				if (members.at(j)->getAccountID() == mInput);

				else
				{
					mTracker = mTracker + 1;
				}
			}
				
		}

	}
	
	if (pTracker==inventory.size())
	{
		std::cout << "Product# " << pInput << " not found." << endl;
	}

	if (mTracker == members.size())
	{
		std::cout << "Member# " << mInput << " not found." << endl;
		std::cout << "line1" << endl;
	}

}

void Store::checkOutMember(std::string mID)
{
	std::string mInput = mID;
	double subtotal=0.00;
	double shippingCost=0.00;
	bool isMember;

	for (int i = 0;i < members.size();i++) //find if the customer is a member
	{

		if (members.at(i)->getAccountID()== mInput)
		{
			std::cout << "line3" << endl;

			for (int i = 0;i < members.at(i)->getCart().size();i++); //print product from cart of that member
			{

				if (getProductFromID(members.at(i)->getCart().at(i))->getQuantityAvailable() > 0)
				{
					std::cout << "line4" << endl;
				std:cout << getProductFromID(members.at(i)->getCart().at(i))->getTitle() << " - $"
					<< getProductFromID(members.at(i)->getCart().at(i))->getPrice() << endl;

					getProductFromID(members.at(i)->getCart().at(i))->decreaseQuantity();

					subtotal = subtotal + getProductFromID(members.at(i)->getCart().at(i))->getPrice();
					shippingCost = shippingCost + subtotal*0.07;

				}
				else
				{
					std::cout << "line5" << endl;
					std::cout << "Sorry, product #" << getProductFromID(members.at(i)->getCart().at(i))->getIdCode() << " ,\""
						<< getProductFromID(members.at(i)->getCart().at(i))->getTitle() << "\", is no longer available." << endl;
				}

			}

		}
		else
		{
			isMember = false;
		}

		std::cout << "Subtotal: $" << subtotal << endl;
		std::cout << "Shipping Cost: $" << shippingCost << endl;
		std::cout << "Total: $" << subtotal << endl;

	}

	if (!isMember)
	{
		std::cout << "Member# " << mInput << " not found." << endl;
	}
}
