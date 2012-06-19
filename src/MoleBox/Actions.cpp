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


#include <MoleBox/Actions.hpp>

MB::Actions::Actions() : state(false)
{

}

MB::Actions::~Actions()
{
  std::map<std::string,Action *>::iterator itr;
  for (itr = this->actionList.begin(); itr != this->actionList.end();itr++)
  {
    delete (*itr).second;
  }  
  
  this->actionList.clear();
}

bool MB::Actions::Exists(std::string referenceName)
{
  return this->actionList.find(referenceName) != this->actionList.end();
}

MB::Action* MB::Actions::Get(std::string referenceName)
{

  if ( this->Exists( referenceName ) )
  {
    return this->actionList[referenceName];
    
  }
  else {
    
    return NULL;
    
  }
}

void MB::Actions::Clear()
{

}

void MB::Actions::Update()
{
  
  std::map<std::string,Action *>::iterator itr;
  
  for (itr = this->actionList.begin(); itr != this->actionList.end();itr++)
  {
    (*itr).second->Update();
  }

}


void MB::Actions::Register(std::string referenceName, Action* action)
{
  
  std::pair< std::string,Action* > newAction(referenceName,action);
  this->actionList.insert(newAction);
  
}

std::map< std::string, MB::Action* > MB::Actions::GetList()
{
  return actionList;
}


