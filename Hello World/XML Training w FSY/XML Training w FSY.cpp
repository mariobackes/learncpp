// XML Training w FSY.cpp : Defines the entry point for the console application.
//

// Includes
#include "stdafx.h"


//Typedefs
typedef std::vector<Block> Arbeitsplatz;

//Functions
Arbeitsplatz Read(std::istream& is)
{
	using boost::property_tree::ptree;
	ptree pt;
	read_xml(is, pt);

	Arbeitsplatz ans;
	for (ptree::value_type const& v : pt.get_child("Arbeitsplatz"))
	{
		if (v.first == "bloecke")
		{
			Block f;
			f.SetArt(v.second.get<std::string>("<xmlattr>.Art"));
			f.SetSeiten(v.second.get<unsigned int>("Seiten"));
			f.SetFarbe(v.second.get<std::string>("Farbe"));
			f.SetSeitenformat(v.second.get<std::string>("Seite"));
		}
	}
}

// Classes
class Block
{
private:
    std::string m_art;
    unsigned int m_seiten;
    std::string m_farbe;
    std::string m_seitenformat;
public:
    Block(std::string art = "undefined", unsigned int seiten = 0, std::string farbe = "undefined", std::string seitenformat = "undefined")
        : m_art{ art }
        , m_seiten{ seiten }
        , m_farbe{ farbe }
        , m_seitenformat{ seitenformat }
    {

    }

    // Setters //
    void SetArt(std::string art)
    {
        m_art = art;
    }
    void SetSeiten(unsigned int seitenanzahl)
    {
        m_seiten = seitenanzahl;
    }
    void SetFarbe(std::string farbe)
    {
        m_farbe = farbe;
    }
    void SetSeitenformat(std::string seitenformat)
    {
        m_seitenformat = seitenformat;
    }

    // Getters //
    std::string GetArt()
    {
        return m_art;
    }
    unsigned int GetSeiten()
    {
        return m_seiten;
    }
    std::string GetFarbe()
    {
        return m_farbe;
    }
    std::string GetSeitenformat()
    {
        return m_seitenformat;
    }
};

class MbaXml
{
private:

public:
    void read() const
    {

    }
    void write()
    {

    }
};
*/




int main()
{
    return 0;
}

