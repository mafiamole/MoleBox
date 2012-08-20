/*
    Copyright (c) 2012 Paul Brown <email>

    Permission is hereby granted, free of charge, to any person
    obtaining a copy of this software and associated documentation
    files (the "Software"), to deal in the Software without
    restriction, including without limitation the rights to use,
    copy, modify, merge, publish, distribute, sublicense, and/or sell
    copies of the Software, and to permit persons to whom the
    Software is furnished to do so, subject to the following
    conditions:

    The above copyright notice and this permission notice shall be
    included in all copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
    EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
    OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
    NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
    HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
    WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
    FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
    OTHER DEALINGS IN THE SOFTWARE.
*/


#ifndef MB_LOGGER_HPP
#define MB_LOGGER_HPP
#include <string>
#include <list>
#include <MoleBox/Export.hpp>

namespace MB {

  /**
   * @brief Used for general message logging.
   **/
  class MOLEBOX_API Logger
  {
  protected:
    std::string file;
    std::list<std::string> entries;
  public:
    /**
     * @brief Constructor sets the filename
     *
     * @param filename Filename/location to write to.
     **/
    Logger(std::string filename);
    /**
     * @brief Adds an entry to the internal entry list.
     *
     * @param line ...
     * @return void
     **/
    void AddEntry(std::string line);
    /**
     * @brief Write Entries to file specified by the constructor.
     *
     * @return void
     **/
    void WriteToFile();
      virtual ~Logger();
      
  };

}

#endif // MB_LOGGER_HPP
