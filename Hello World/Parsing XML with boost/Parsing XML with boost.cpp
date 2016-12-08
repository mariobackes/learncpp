// Parsing XML with boost.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

typedef boost::gregorian::date Date;

struct Flight
{
	std::string		carrier;
	unsigned int	number;
	Date			date;
	bool			cancelled;
};

typedef std::vector<Flight> Sked;


class DateTranslator
{
	std::locale locale_;

public:
	typedef std::string internal_type;
	typedef Date		external_type;

	DateTranslator();
	boost::optional<external_type> get_value(internal_type const& v);
	boost::optional<internal_type> get_value(external_type const& v);
};


Sked read(std::istream& instrm)
{
	// Readability
	using boost::property_tree::ptree;

	ptree pt;

	// Feed the ptree variable with the XML file.
	read_xml(instrm, pt);

	// Declare Vector of type Flight (struct)
	Sked ans;

	// Iterate over all elements in the ptree object.
	for (ptree::value_type const& var : pt.get_child("sked"))
	{
		// If flight tag is root fill the flight struct with data from the children of this tag.
		if (var.first == "flight")			// Was beinhaltet var.first / var.second?
		{
			Flight flight;
			flight.carrier		= var.second.get<std::string>	("carrier");
			flight.number		= var.second.get<unsigned int>	("number");
			flight.date			= var.second.get<Date>			("date");
			flight.cancelled	= var.second.get				("<xmlattr>.cancelled", false);
			ans.push_back(flight);			// Was macht die push_back Methode?
		}
	}
	// Return vector of type Flight (struct)
	return ans;
}

int main()
{
	std::filebuf fb;
	if (fb.open("sked.xml", std::ios::in))
	{
		std::istream instrm(&fb);
		read(instrm);
		fb.close();
	}
    return 0;
}

