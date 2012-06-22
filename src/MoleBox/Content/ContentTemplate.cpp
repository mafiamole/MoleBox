#include <MoleBox/Content/ContentTemplate.hpp>

MB::Content::ID::ID(std::string type) : type(type)
{
}

MB::Content::ID::~ID()
{
}

std::string MB::Content::ID::Type()
{
  return this->type;
}

MB::Content::StrVect MB::Content::ID::List()
{
  return MB::Content::StrVect();
}

bool MB::Content::ID::CheckExtension(std::string extension)
{
  return false;
}
void MB::Content::ID::Load(std::string string)
{
  
}


