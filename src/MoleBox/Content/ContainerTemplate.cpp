#include <MoleBox/Content/ContainerTemplate.hpp>


MB::Content::Exception::Exception(ERR_TYPE type,std::string resource)
{
  this->type = type;
  this->resource = resource;
}

std::string MB::Content::Exception::toString()
{
  switch(type)
  {
    case OTHER:
      return "Unknow error with resource:" + this->resource;
      break;
    case COULD_NOT_LOAD:
      return "Could not load " + this->resource;
      break;
    case NOT_IMPLEMENTED:
      return "Resource type is not implemented for resource:" + this->resource;
      break;
    default:
      return "Unknown error with resource:" + this->resource;
      break;
  }
    
}
  