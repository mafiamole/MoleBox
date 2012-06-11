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


#include "luaeditor.h"
#include "LuaScriptHelper.h"
#include "luascript.h"
#include  <time.h>
<<<<<<< HEAD
#include <unistd.h>
=======
#include <qfile.h>
#include <qtextstream.h>

>>>>>>> 5d7d36b0052140611e4ffd1a40f724f5bcd373a5
#ifdef LUA_EDITOR

LuaHighlighter::LuaHighlighter(QObject* parent): QSyntaxHighlighter(parent)
{

}

LuaHighlighter::LuaHighlighter(QTextEdit* parent): QSyntaxHighlighter(parent)
{

}

LuaHighlighter::LuaHighlighter(QTextDocument* parent): QSyntaxHighlighter(parent)
{

}


void LuaHighlighter::highlightBlock(const QString& text)
{

     QTextCharFormat properties;
     properties.setForeground(Qt::black);
     QRegExp propertiesMatch("(\\.([a-zA-Z][a-zA-Z0-9])*)|(([a-zA-Z][a-zA-Z0-9])*\\()|[)+*-><]");
     
     
     QTextCharFormat function;
     function.setFontWeight(QFont::Bold);
     function.setForeground(Qt::black);
     QRegExp functionMatch("(function|end|if|then|local|do|repeat|while|return|nil|false|true|and|or|not)");
     
     QTextCharFormat number;
     number.setForeground(Qt::darkGreen);
     QRegExp numberMatch("[0-9]");

     QTextCharFormat string;
     string.setForeground(Qt::red);
     QRegExp stringMatch("\"[A-Za-z0-9_.]*\"");
     
     QTextCharFormat comment;
     comment.setForeground(Qt::gray);
     QRegExp commentMatch("--.*");
     int index;
     
	 QTextCharFormat globalFormat;
     globalFormat.setForeground(Qt::blue);     
     int len = text.length();
     setFormat(0,len,globalFormat);

     index = text.indexOf(propertiesMatch);
     while (index >= 0) {
         int length = propertiesMatch.matchedLength();
         setFormat(index, length, properties);
         index = text.indexOf(propertiesMatch, index + length);
     }     
          
     index = text.indexOf(functionMatch);
     while (index >= 0) {
         int length = functionMatch.matchedLength();
         setFormat(index, length, function);
         index = text.indexOf(functionMatch, index + length);
     }
     
     index = text.indexOf(numberMatch);
     while (index >= 0) {
         int length = numberMatch.matchedLength();
         setFormat(index, length, number);
         index = text.indexOf(numberMatch, index + length);
     }

     index = text.indexOf(stringMatch);
     while (index >= 0) {
         int length = stringMatch.matchedLength();
         setFormat(index, length, string);
         index = text.indexOf(stringMatch, index + length);
     }

     index = text.indexOf(commentMatch);
     while (index >= 0) {
         int length = commentMatch.matchedLength();
         setFormat(index, length, comment);
         index = text.indexOf(commentMatch, index + length);
     }     



          
}


LuaEditor::LuaEditor(std::vector<std::string> scripts,QWidget *parent) : QWidget(parent)
{
  ui.setupUi(this); 

  this->SetScripts(scripts);
  QApplication::connect( ui.comboBox_scriptSelection, SIGNAL(currentIndexChanged(QString)), this, SLOT(ChangeScript(QString)));
  connect(ui.tabCodeWindow, SIGNAL(currentChanged(int)), this, SLOT(TabChanged(int)));  
  connect(ui.tabCodeWindow,SIGNAL(tabCloseRequested(int)),this,SLOT(CloseTab(int)));
    
  connect ( ui.pushButton_Save, SIGNAL( clicked() ), this, SLOT( pushButton_Save_Click() ) );
  connect ( ui.pushButton_SaveAs, SIGNAL( clicked() ), this, SLOT( pushButton_SaveAs_Click() ) );
  connect ( ui.pushButton_New, SIGNAL( clicked() ), this, SLOT( pushButton_New_Click() ) );

  connect(
      ui.listWidget_errors->model(),
      SIGNAL(rowsInserted ( const QModelIndex &, int, int ) ),
      ui.listWidget_errors,
      SLOT(scrollToBottom ())
    );
  
  // We are assuming the first tab is the resource tab.
  if ( ui.tabCodeWindow->count() > 0 ) { 
    this->ResourcesTabTitle = ui.tabCodeWindow->tabText(0);
  }
  this->ChangeScript(scripts[0].c_str());
}

LuaEditor::~LuaEditor()
{

}


void LuaEditor::pushButton_Save_Click(){
	if ((QTextEdit*)ui.tabCodeWindow->currentIndex() != 0){
		// Not resources tab, so can save
	
		QFile file(ui.comboBox_scriptSelection->currentText());
 
		if (file.open(QIODevice::WriteOnly|QIODevice::Text)) {
			QTextStream stream(&file); 
			stream << ((QTextEdit*)ui.tabCodeWindow->currentWidget())->toPlainText();
			file.flush();
			file.close();
		}
		else {
			// Error
		return;
		}
	}

}


void LuaEditor::pushButton_SaveAs_Click(){
//	if (nomeFile != "") {
//QFile file(nomeFile);
// 
//if (file.open(QIODevice::WriteOnly|QIODevice::Text)) {
//---> QTextStream stream(&file); <-----
//stream << ui->editaTesto->toPlainText();
//file.flush();
//file.close();
//}
//else {
//QMessageBox::critical(this, tr("Errore"), tr("Non posso salvare il file"));
//return;
//}
//}
}

void LuaEditor::pushButton_New_Click(){
	
}

void LuaEditor::SetScripts( std::vector< std::string > scripts )
{
  
  this->scripts = scripts;    
  
  QStringList list;
  
  std::vector< std::string >::iterator itr;
  
  for (itr = scripts.begin(); itr != scripts.end(); itr++)
  {
    list << (*itr).c_str();
  }
  
  
  ui.comboBox_scriptSelection->addItems(list);
}




void LuaEditor::TabChanged(int index)
{
<<<<<<< HEAD
	// Update current tab formatting
	
	if ( ui.tabCodeWindow->tabText(index) != this->ResourcesTabTitle) {
	
	QTextEdit* currentTextEdit = (QTextEdit*)ui.tabCodeWindow->widget(index);
=======
	if(ui.tabCodeWindow->tabText(index).compare("Resources") == 0){
		// Code to update Resources
		
		
      }else{

		// Update current script tab
		QTextEdit* currentTextEdit = (QTextEdit*)ui.tabCodeWindow->currentWidget();
>>>>>>> 5d7d36b0052140611e4ffd1a40f724f5bcd373a5
	
		luaHighlight = new LuaHighlighter(currentTextEdit->document());
			
<<<<<<< HEAD
	QApplication::connect(currentTextEdit, SIGNAL(textChanged()), this, SLOT(UpdateScript()) ); // updates script on changes.
	}

=======
		QApplication::connect(currentTextEdit, SIGNAL(textChanged()), this, SLOT(UpdateScript()) ); // updates script on changes.
	}
>>>>>>> 5d7d36b0052140611e4ffd1a40f724f5bcd373a5
}

void LuaEditor::CloseTab(int index)
	{
		if((ui.tabCodeWindow->count() != 1) && (index != 0)){
			//Handle tabCloseRequested Signal and Close the Tab
			ui.tabCodeWindow->removeTab(index);	
		}	    	
	};

bool LuaEditor::FindTab(QString scriptFile)
{
  bool needNew = false;

  for(int i=0;i<ui.tabCodeWindow->count();i++){

	  if(ui.tabCodeWindow->tabText(i).compare(ui.comboBox_scriptSelection->currentText()) == 0){
		  // Switch to
		  needNew = false;					
		  ui.tabCodeWindow->setCurrentIndex(i);
		  break;
  }	else{
		  // Mark as needing a new tab created
		  needNew = true;
	  }
  }
  return needNew;
}

	
void LuaEditor::ChangeScript(QString scriptFile)
{

  if (this->FindTab(scriptFile)){
		  // Create new tab, load, then switch to.

      int index = ui.tabCodeWindow->addTab(new QTextEdit(),scriptFile);
      std::string script = LuaHelper::LuaScripts::Instance().GrabScript(scriptFile.toStdString());
      ui.tabCodeWindow->setCurrentIndex(ui.tabCodeWindow->count()-1);
      QTextEdit* editor = (QTextEdit*)ui.tabCodeWindow->widget(index);
      editor->setText(script.c_str());
    
  }
 
}

void LuaEditor::UpdateScript()
{
  
  std::string scriptFile    = ui.comboBox_scriptSelection->itemText( ui.comboBox_scriptSelection->currentIndex() ).toStdString();  
  std::string changedScript = ((QTextEdit*)ui.tabCodeWindow->currentWidget())->toPlainText().toStdString();
  
  try {

    LuaScript script(true);
  
    bool success = script.LoadFromString(changedScript);
      script.RunScript();
      script.RunFunction("init");
      script.RunFunction("update");
      script.RunFunction("draw");
  
      LuaHelper::LuaScripts::Instance().UpdateScript( scriptFile, changedScript );
      
  }
  catch (std::string error) {
    
    this->ui.listWidget_errors->addItem(QString(error.c_str()));
    
  }



  
}

#endif





