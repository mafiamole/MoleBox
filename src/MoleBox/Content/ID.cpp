#include <MoleBox/Content/ID.hpp>

namespace MB
{
	namespace Content
	{

		ID::ID(std::string type) : type(type)
		{
  
		}

		ID::~ID()
		{
		}

		std::string ID::Type()
		{
		  return this->type;
		}

		MB::StrVector ID::List()
		{
		  return MB::StrVector();
		}

		bool ID::CheckExtension(std::string extension)
		{
		  return false;
		}
		void ID::Load(std::string fileLocation)
		{
  
		}
	}
}