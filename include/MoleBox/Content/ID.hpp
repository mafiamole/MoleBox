#ifndef ID_HPP
#define ID_HPP
#include <MoleBox/Export.hpp>
#include <MoleBox/Types.hpp>


namespace MB {
  
  namespace Content {
    /**
    * @brief Class that provides a general way for each resource/content type to identify it self.
    **/
    class MOLEBOX_API ID
	{
	protected:
	  std::string 		type;
	public:
	  
	  /**
	   * @brief constructor that sets the member type
	   *
	   * @param type string identifier
	   **/
				ID(std::string type);
				~ID();
	  
	  /**
	   * @brief Returns member type
	   *
	   * @return MB:string
	   **/
	  std::string 		Type();
	  /**
	   * @brief returns a list of the content this identifies.
	   *
	   * @return :StrVector
	   **/
	  virtual MB::StrVector List();
	  /**
	   * @brief Checks the extension of a given type if supported.
	   *
	   * @param extension extension to check.
	   * @return bool
	   **/
	  virtual bool 		CheckExtension(std::string extension);
	  /**
	   * @brief Load but not return content
	   *
	   * @param fileLocation file location on disk.
	   * @return void
	   **/
	  virtual void 		Load(std::string fileLocation);
	  
	};   
	
  }
}
#endif // ID_HPP