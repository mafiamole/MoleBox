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

#include "luascripts.h"
#include "LuaScriptHelper.h"

class LuaHighlighter : public QSyntaxHighlighter
{
  Q_OBJECT
public:
    LuaHighlighter(QObject* parent);
    LuaHighlighter(QTextEdit* parent);
    LuaHighlighter(QTextDocument* parent);
protected:
    virtual void highlightBlock(const QString& text);
};

class LuaEditor : public QWidget
{
  Q_OBJECT
private:
  LuaHighlighter *luaHighlight;
  Ui_ScriptEditor ui;
  std::vector< std::string > scripts;
public:
    void SetScripts( std::vector< std::string > scripts );
    void SetScript( std::string script );
    LuaEditor(QWidget* parent = 0);
    virtual ~LuaEditor();
	int lastTime;
    
public slots:   
    void ChangeScript(QString scriptFile);
    void UpdateScript();
	void TabChanged(int index);
	void CloseTab(int index);
};

#endif // LUAEDITOR_H
#endif