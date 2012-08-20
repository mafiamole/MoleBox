
#include <MoleBox/ResourceUI/RUI_Thread.hpp>
#include <MoleBox/ResourceUI/ResourceUI.hpp>
#include <MoleBox/Content/Content.hpp>

void RUI_Thread(Args args)
{
  QApplication app(args.argc,args.argv);

  MB::RUI::ResourceUI ui(args.map);
  ui.show();
  int result = app.exec();
}


sf::Thread* CreateRUIThreadOBJ(Args args)
{
 return new sf::Thread(&RUI_Thread,args); 
}
