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

#ifndef PATTERNS_HPP
#define PATTERNS_HPP
#include <SFML/System/Mutex.hpp>
#include <SFML/System/Lock.hpp>
#include <list>
#include <MoleBox/GameObject.hpp>
#include <MoleBox/Export.hpp>

template<class T> static T& Singleton()
{
  static T inst;
  return inst;
}
namespace MB
{
  namespace SM
  {

    class MOLEBOX_API Machine;
    
    /**
     * @brief A generic class that encapsulates the idea of a state in a state machine
     **/
    class MOLEBOX_API State
    {
    protected:
      std::list<std::string> nextStates;
      std::string name;
      Machine* stateMachine;
    public:
      State(std::string name,Machine* sfm);
      ~State();
      std::string GetName();
      virtual void DoEntre();
      virtual void DoExit();
      virtual void Update(sf::Time elapsed) = 0;

    };
    
    /**
     * @brief The 'Machine' in state machine.
     **/
    class MOLEBOX_API Machine
    {

    protected:
      std::map<std::string,State*> states;  
      State* currentState;
      bool initalised;
    public:
      /**
       * @brief Default constructor
       *
       **/
     Machine();
      /**
       * @brief Default destructor
       *
       **/
      ~Machine();
      /**
       * @brief Add a state to the state machine
       *
       * @param state The state to add
       * @return void
       **/
      void AddState(State* state);
      /**
       * @brief Set the current state name to run.
       *
       * @param name The name of the state to run.
       * @return void
       **/
      void SetState(std::string name);
      /**
       * @brief Begin the state machine.
       *
       * @return int
       **/
      virtual int Run();
    };

  }
}


#endif