// Boost XML Tutorial.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"



struct debug_settings
{
	std::string           m_file;		 // log filename
	int				            m_level;	 // debug level
  std::set<std::string> m_modules; // modules where logging is enabled
  void load(const std::string& filename);
  void save(const std::string& filename);
};



void debug_settings::load(const std::string& filename)
{
  using boost::property_tree::ptree;

  // Declare an empty property tree object.
  ptree pt;

  // Load the XML file into this object/tree. If file can not be opened, an exception is thrown.
  read_xml(filename, pt);

  // If debug.xml is not found, an exception is thrown.
  m_file = pt.get<std::string>("debug.filename");

  //If the value is not found, the default value (second parameter) will be used.
  m_level = pt.get("debug.level", 0);

  // Iterate over the debug.modules ans store them in the m_modules set.
  for (ptree::value_type& var : pt.get_child("debug.modules"))
  {
    m_modules.insert(var.second.data());
  }
}



void debug_settings::save(const std::string& filename)
{
  using boost::property_tree::ptree;
  
  ptree pt;
  
  pt.put("debug.filename", m_file);
  
  pt.put("debug.level", m_level);

  for (const std::string& name : m_modules)
  {
    pt.put("debug.modules.module", name);
  }
  write_xml(filename, pt);

}



int main()
{
    return 0;
}

