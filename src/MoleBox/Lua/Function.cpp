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


#include <MoleBox/Lua/Function.hpp>
#include <MoleBox/Lua/Arguments/Integer.hpp>
#include <MoleBox/Lua/Arguments/String.hpp>
#include <MoleBox/Lua/Arguments/Number.hpp>
#include <MoleBox/Lua/Arguments/Boolean.hpp>
#include <iostream>

namespace MB
{
	namespace Lua
	{

		Function::Function() : args(), ready(false)
		{

		}

		Function::Function(std::map<std::string,Argument*> args)
		{
		  this->args = args;
		}

		Function::Function(const Function& copyFrom)
		{
		  std::map<std::string, Argument*>::iterator itr;

		  for ( itr = this->args.begin(); itr != this->args.end(); itr++ )
		  {
			std::pair<std::string, Argument*> copy( (*itr).first, new Argument( *((*itr).second) )  );
			this->args.insert( copy );
		  }

		}

		Function::~Function()
		{

		}

		void Function::InitCall(lua_State* L,std::string name, bool pushargs)
		{
  
		  this->L = L;
  
		  if ( !name.empty() )
		  {

			lua_getglobal(L,name.c_str());
    
			if ( !lua_isfunction(L,-1) )
			{
			  throw  name + " is not a function.";
			}
    
			this->ready = true;
    
			if ( pushargs )
			  this->PushArgs(L);
    
		  }
  
		}

		void Function::PushArgs(lua_State* L)
		{
		  std::map<std::string, Argument*>::iterator itr;
		  for (itr = this->args.begin(); itr != this->args.end(); itr++)
		  {
			(*itr).second->Push(L);
		  }
		}

		void Function::PushArg(lua_State* L, std::string name)
		{
		  if ( this->args.find(name) != this->args.end() )
		  {
			this->args[name]->Push(L);
		  }
		}

		int Function::FinishCall(int returnValues)
		{
		  this->ready = false;
			return lua_pcall(L,this->args.size(),returnValues,0);
		}

		void Function::AddArg(std::string ref,int arg)
		{
		  this->args.insert( std::pair<std::string,Argument*>( ref ,  new Integer(arg) ) );
		}

		void Function::AddArg(std::string ref,std::string arg)
		{
		  this->args.insert( std::pair<std::string,Argument*>(  ref ,  new String(arg) ) );
		}

		void Function::AddArg(std::string ref, float arg)
		{
		  this->args.insert( std::pair<std::string,Argument*>(  ref ,  new Number(arg) ) );
		}

		void Function::AddArg(std::string ref, double arg)
		{
		  this->args.insert( std::pair<std::string,Argument*>(  ref ,  new Number(arg) ) );
		}

		void Function::AddArg(std::string ref, bool arg)
		{
		  this->args.insert( std::pair<std::string,Argument*>(  ref ,  new Boolean(arg) ) );
		}

		void Function::AddArg(std::string ref, Argument* arg)
		{
		  this->args.insert( std::pair<std::string,Argument*>( ref, arg ) );
		}

		Argument * Function::GetArg(std::string ref)
		{
		  return this->args[ref];
		}

		void Function::SetArg(std::string ref,int arg) 
		{
		//   if ( !ready)
		//     return;
  
		  if ( this->args.find(ref) != this->args.end())
		  {
			Integer* argObj = (Integer*)this->args[ref];
			argObj->Set(arg);
		  }
		}

		void Function::SetArg(std::string ref, std::string arg)
		{
		//   if ( !ready)
		//     return;
  
		  if ( this->args.find(ref) != this->args.end() )
		  {
			String* argObj = (String*)this->args[ref];
			argObj->Set(arg);
		  }
		}

		void Function::SetArg(std::string ref,float arg)
		{
		//   if ( !ready)
		//     return;
  
		  if ( this->args.find(ref) != this->args.end() )
		  {
			Number* argObj = (Number*)this->args[ref];
			argObj->Set(arg);
		  }
		}

		void Function::SetArg(std::string ref,double arg)
		{
		//   if ( !ready)
		//     return;
		//   
		  if ( ( this->args.find(ref) != this->args.end()) )
		  {
			Number* argObj = (Number*)this->args[ref];
			argObj->Set(arg);
		  }
		}

		void Function::SetArg(std::string ref,bool arg)
		{
		//   if ( !ready)
		//     return;
		//   
		  if ( this->args.find(ref) != this->args.end() )
		  {
			Boolean* argObj = (Boolean*)this->args[ref];
			argObj->Set(arg);
		  }
		}
	}
}