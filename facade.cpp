// facade.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <cliext\list>
using namespace std;
using namespace System;


ref class HotelBooker {
public: 
	cliext::list<String^>^ getHotels(){
		cliext::list<String^>^ mlist = gcnew cliext::list<String^>();
		mlist->push_back("Hilton");
		return mlist;
	} 
};

ref class FlyBooker {
public: 
	cliext::list<String^>^ getFlies(){
		cliext::list<String^>^ list = gcnew cliext::list<String^>();
		list->push_back("CHP996");
		return list;
	} 
};

ref class FacadeBooker {
private:
	HotelBooker^ hotelBooker;
	FlyBooker^ flightBooker;
public: 
	FacadeBooker(){;}
	FacadeBooker(HotelBooker^ hotelBooker, FlyBooker^ flightBooker)
	{
		this->hotelBooker = hotelBooker;
		this->flightBooker = flightBooker;
	}
	cliext::list<String^>^ getHotelAndFlies(){
		cliext::list<String^>^ mlist = hotelBooker->getHotels();
		cliext::list<String^>^ nlist = flightBooker->getFlies();
		for each (String^ elem in nlist) 
		   mlist->push_back(elem);
		return mlist;
	} 
};

int _tmain(int argc, _TCHAR* argv[])
{
	FacadeBooker^ mFacadeBooker = gcnew FacadeBooker;
	cliext::list<String^>^ mlist = mFacadeBooker->getHotelAndFlies();
	for each (String^ elem in mlist) 
		  Console::WriteLine(elem);
	Console::ReadLine();

	return 0;
}

