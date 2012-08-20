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
#include <iostream>
#include <stdlib.h>

#include <MoleBox/ResourceUI/ResourceUI.hpp>
#include <MoleBox/Content/Content.hpp>

using namespace MB::RUI;

ResourceUI::ResourceUI(ResourceMap resources, QWidget* parent): QWidget()
{
  mainUI.setupUi(this);
  this->resourceModel = new QStandardItemModel; 
  this->InitResourceTree(resources);
  connect(mainUI.treeView_resources,SIGNAL(clicked(QModelIndex)),this,SLOT(AddTab(QModelIndex)));

}

ResourceUI::~ResourceUI()
{

  
}

void ResourceUI::AddTab(QModelIndex index)
{
  QStandardItem* item = this->resourceModel->itemFromIndex(index);

  if (item->parent() != 0) {

    QString category = item->parent()->text();
    QString filename = item->text();

      if (category == QString("texture") )
      {
	
      int numIndex = mainUI.tabWidget_resourceViews->addTab(new ImageUI(filename),filename);

      }
      else if (category == QString("sound") )
      {
      int numIndex = mainUI.tabWidget_resourceViews->addTab(new AudioUI(filename),filename);
	
      }
      else if (category == QString("luascript") )
      {
      int numIndex = mainUI.tabWidget_resourceViews->addTab(new LuaEditor(filename),filename);
	
      }
      else if (category == QString("music") )
      {
      int numIndex = mainUI.tabWidget_resourceViews->addTab(new QTextEdit,filename);
	
      }
  }
}

void ResourceUI::InitResourceTree(ResourceMap resources)
{
  QStandardItem *rootNode = this->resourceModel->invisibleRootItem();
  
  
 ResourceMap::iterator resourceItr;
  
  for (resourceItr = resources.begin(); resourceItr != resources.end(); resourceItr++)
  {
    QStandardItem *item = new QStandardItem ( (*resourceItr).first.c_str() );
    this->AppendToResourceTree((*resourceItr).second,item);
    rootNode->appendRow(item);
  }
  this->mainUI.treeView_resources->setModel(resourceModel);
  this->mainUI.treeView_resources->expandAll();
}

void ResourceUI::AppendToResourceTree(MB::StrVector list, QStandardItem *root)
{
  MB::StrVector::iterator resourceItr;
  
  for (resourceItr = list.begin(); resourceItr != list.end(); resourceItr++)
  {
    QStandardItem *item = new QStandardItem((*resourceItr).c_str());
    root->appendRow(item);
  }  
}

