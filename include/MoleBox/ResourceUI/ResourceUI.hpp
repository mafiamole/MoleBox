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


#ifndef RESOURCEUI_H
#define RESOURCEUI_H

#include <QtGui/QWidget>
#include <QtGui/QSyntaxHighlighter>
#include <QStandardItemModel>

#include "ui_Main.h"
#include <MoleBox/Types.hpp>
#include <MoleBox/ResourceUI/LuaEditor.hpp>
#include <MoleBox/ResourceUI/RUI_Thread.hpp>
#include <MoleBox/ResourceUI/ImageUI.hpp>
#include <MoleBox/ResourceUI/AudioUI.hpp>

namespace MB
{

  namespace RUI
  {

  //     class Highlighter : public QSyntaxHighlighter
  //     {
  //       Q_OBJECT
  //     public:
  // 	Highlighter(QObject* parent);
  // 	Highlighter(QTextEdit* parent);
  // 	Highlighter(QTextDocument* parent);
  //     protected:
  // 	virtual void highlightBlock(const QString& text);
  //     };
  

    class ResourceUI : public QWidget
    {
	Q_OBJECT
    private:
	Ui_Main mainUI;
	
	QStandardItemModel *resourceModel;

    public:
      /**
       * @brief ResourceUI Constructor initialises the resource list.
       *
       * @param resources Resoure Map, organised by type
       * @param parent Qt Widget parent Defaults to 0.
       **/
      explicit ResourceUI(ResourceMap resources, QWidget* parent = 0);
      /**
       * @brief Initalises the resource tree by given resource map.
       *
       * @param resources The resource list to initalise the tree view with
       * @return void
       **/
      void InitResourceTree(ResourceMap resources);
      /**
       * @brief Appends a list of a certain type of resource list to the tree;
       *
       * @param list List of a certain resource type.
       * @param root Root to attach list to.
       * @return void
       **/
      void AppendToResourceTree(MB::StrVector list, QStandardItem *root);

      virtual ~ResourceUI();
	
    public slots:
      /**
       * @brief Adds a tab to the tab view given an index from the tree list view.
       *
       * @param index Index from the tree list view.
       * @return void
       **/
      void AddTab(QModelIndex index);
    };

  }
}
#endif // RESOURCEUI_H
