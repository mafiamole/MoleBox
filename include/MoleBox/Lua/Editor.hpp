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


#ifndef LUAEDITOR_H
#define LUAEDITOR_H
#ifdef LUA_EDITOR

#include <QtGui/QWidget>
#include <QtGui/QTextEdit>
#include <QSyntaxHighlighter>
#include "ui_GameLuaEditor.h"
#include <MoleBox/Lua/Scripts.hpp>
#include <MoleBox/Lua/ScriptHelper.hpp>
#include <QTreeView>
 #include <QStandardItemModel>
 #include <QItemSelectionModel>
#include <MoleBox/Content/Content.hpp>
#include <MoleBox/ContainerDefinitions.hpp>
namespace MB {
  
  namespace Lua {
  
    class Highlighter : public QSyntaxHighlighter
    {
      Q_OBJECT
    public:
	Highlighter(QObject* parent);
	Highlighter(QTextEdit* parent);
	Highlighter(QTextDocument* parent);
    protected:
	virtual void highlightBlock(const QString& text);
    };

    class LuaEditor : public QWidget
    {
      Q_OBJECT
    private:
      Highlighter *luaHighlight;
      Ui_ScriptEditor ui;
      std::vector< std::string > scripts;
      QStandardItemModel *resourceModel;
    protected:
      QString ResourcesTabTitle;
      void SetScripts( std::vector< std::string > scripts );
      bool FindTab(QString scriptFile);
      void InitResourceTree(std::map<std::string,MB::Types::StrVect> resources);
      void AppendToResourceTree(MB::Content::StrVect list , QStandardItem *root);
    public:
	LuaEditor( std::map<std::string,MB::Types::StrVect> resources,std::vector<std::string> scripts,QWidget* parent = 0);
	virtual ~LuaEditor();
	int lastTime;
	
    public slots:   
	void ChangeScript(QString scriptFile);
	void UpdateScript();
	void TabChanged(int index);
	void CloseTab(int index);
	void pushButton_Save_Click();
	void pushButton_SaveAs_Click();
	void pushButton_New_Click();
    };

  }

}

#endif // LUAEDITOR_H
#endif