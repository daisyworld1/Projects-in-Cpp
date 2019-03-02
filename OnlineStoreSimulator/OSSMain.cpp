#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
 
using namespace std;

#include "Store.hpp"

int main()
{

	std::string memberID;
	std::string productID;

	Customer customer1("Amy","rMem001", false);
	Customer customer2("Bob", "pMem001", true);

	Product product1("prod0001", "chicken meal", "your dog will love the added jerky.", 39.99, 2);
	Product product2("prod0002", "vegan meal", "your dog will save the earth.", 49.99, 1);
	Product product3("prod0003", "tennis ball", "your dog will get so tired.", 1.99, 0);

	Store shop1;

	shop1.addProduct(&product1);
	shop1.addProduct(&product2);
	shop1.addProduct(&product3);

	shop1.addMember(&customer1);
	shop1.addMember(&customer2);

	shop1.productSearch("jerky");

	shop1.addProductToMemberCart("prod0001", "pMem001");

	shop1.checkOutMember("pMem001");

	system("pause");


	return 0;
}
