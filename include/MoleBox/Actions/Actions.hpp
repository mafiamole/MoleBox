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


#ifndef ACTIONS_H
#define ACTIONS_H

#include <map>
#include <string>

#include <MoleBox/Export.hpp>
#include <MoleBox/Actions/Action.hpp>
#include <MoleBox/Types.hpp>

namespace MB {
  namespace Actions {
    
    /**
     * @brief A specialised container for game actions.
     **/
    class MOLEBOX_API Actions
    {
    private:
      bool 				state;
      std::map<std::string,Action *>	actionList;
    public:
      /**
       * @brief default destructor-
       *
       **/
      Actions	();
      /**
       * @brief deletes all actions for you.
       *
       **/
      virtual 				~Actions();     
      /**
       * @brief Register an action
       *
       * @param referenceName Name to reference your action
       * @param action action event to bind with.
       * @return void
       **/
      void 				Register(std::string referenceName, Action *action);
      /**
       * @brief Returns if a partiular reference exists.
       *
       * @param referenceName ...
       * @return bool
       **/
      bool 				Exists	(std::string referenceName);
      /**
       * @brief Clear all Actions from the list.
       *
       * @return void
       **/
      void 				Clear	();

      /**
       * @brief Update all actions.
       *
       * @param elapsed time since last update
       * @param events Input events.
       * @return void
       **/
      void 				Update	(sf::Time elapsed, EventList* events);
      /**
       * @brief Returns an action by reference name
       *
       * @param referenceName reference name of the action.
       * @return :Actions::Action*
       **/
      Action*				Get	(std::string referenceName);
      /**
       * @brief Gets all the actions avaiable.
       *
       * @return std::map< std::string, MB::Actions::Action*, std::less< std::string >, std::allocator< std::pair< const std::string, MB::Actions::Action* > > >
       **/
      std::map<std::string,Action *>	GetList();
    };
  }
}
#endif // ACTIONS_H
