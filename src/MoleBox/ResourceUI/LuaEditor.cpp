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

#include <Qt/qfile.h>
#include <QTextStream>

#include <MoleBox/ResourceUI/LuaEditor.hpp>
#include <MoleBox/Lua/Script.hpp>
#include <MoleBox/Patterns.hpp>
#include <MoleBox/Lua/Container.hpp>
#include <MoleBox/Content/Content.hpp>


using namespace MB::RUI;



LuaEditor::LuaEditor(QString file,QWidget* parent): QWidget(parent) , scriptname(file)
{
  ui.setupUi(this);
  
  connect(ui.textEdit_script,SIGNAL(textChanged()),this, SLOT(UpdateScript()) );
  QString contents;
  
  MB::Lua::Script* script = MB::Content::Load< MB::Lua::Script* >(file.toStdString());
  
  testScript = new MB::Lua::Script( script->CloneFunctions() );
  QFile textFile(file);
  if (textFile.open(QIODevice::ReadOnly | QIODevice::Text))
  {

    QTextStream in(&textFile);
    while (!in.atEnd())
    {
	contents += in.readLine() + "\n";
    }
  }
  this->ui.textEdit_script->setText(contents);
}

LuaEditor::~LuaEditor()
{
  
}

void LuaEditor::UpdateScript()
{
  
  
    std::string scriptTest = ui.textEdit_script->toPlainText().toStdString();
    
    if ( this->TestScript(scriptTest) )
    {
      MB::Lua::Script* scriptOb = MB::Content::Load<MB::Lua::Script*>(this->scriptname.toStdString());
      
      scriptOb->UpdateFromString(scriptTest);
      //Singleton<MB::Lua::LuaScripts>().Update(this->scriptname.toStdString(), scriptTest);
    }
    
}


bool LuaEditor::TestScript(std::string Body)
{
  
//   script.RegisterLibrary("Window",lua_reg_window_DUMMY);
//   script.RegisterLibrary("Sprite",lua_reg_sprite_DUMMY);
//   script.RegisterLibrary("Text",lua_reg_text_DUMMY);
//   script.RegisterLibrary("Sound",lua_reg_sound_DUMMY);
  
  bool success = this->testScript.LoadFromString(Body);
  
  return success;
}
