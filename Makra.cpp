//---------------------------------------------------------------------------
#include <vcl.h>
#include <windows.h>
#pragma hdrstop
#pragma argsused
#include "Struktury.h"
#include "Notyfikacje.h"

int WINAPI DllEntryPoint(HINSTANCE hinst, unsigned long reason, void* lpReserved)
{
        return 1;
}

DWORD PLUGIN_MAKE_VERSION(int a, int b, int c, int d)
{
  return (((((DWORD)(a))&0xFF)<<24)|((((DWORD)(b))&0xFF)<<16)|((((DWORD)(c))&0xFF)<<8)|(((DWORD)(d))&0xFF));
}

int __stdcall MakraService (WPARAM, LPARAM)
{
  return 0;
}

// Utworzenie obiektow do struktur
PluginAction TPluginAction;
PluginLink TPluginLink;
PluginInfo TPluginInfo;

//Program
extern "C"  __declspec(dllexport) PluginInfo* __stdcall AQQPluginInfo(DWORD AQQVersion)
{
  TPluginInfo.cbSize = sizeof(PluginInfo);
  TPluginInfo.ShortName = (wchar_t*)L"Makra";
  TPluginInfo.Version = PLUGIN_MAKE_VERSION(0,0,1,0);
  TPluginInfo.Description = (wchar_t *)L"Dodaje makra do g³ównego okna";
  TPluginInfo.Author = (wchar_t *)L"Krzysztof Grochocki";
  TPluginInfo.AuthorMail = (wchar_t *)L"beherit666@vp.pl";
  TPluginInfo.Copyright = (wchar_t *)L"Prawa zastrze¿one, tylko dla autora.";
  TPluginInfo.Homepage = (wchar_t *)L"Brak";
  TPluginInfo.Flag = 0;
  TPluginInfo.ReplaceDefaultModule = 0;
  
  return &TPluginInfo;
}

void PrzypiszAkcje()
{
  TPluginAction.cbSize = sizeof(PluginAction);
  TPluginAction.Position = 114;
  TPluginAction.IconIndex = 63;
  TPluginAction.pszService = (wchar_t*) L"serwis_makra";
  TPluginAction.pszPopupName = (wchar_t*) L"popMacros";

  TPluginLink.CallService(AQQ_CONTROLS_TOOLBAR "ToolDown" AQQ_CONTROLS_CREATEBUTTON,0,(LPARAM)(&TPluginAction));
  TPluginLink.CreateServiceFunction(L"serwis_makra",MakraService);
}

extern "C" int __declspec(dllexport) __stdcall Load(PluginLink *Link)
{
  TPluginLink = *Link;
  PrzypiszAkcje();

  return 0;
}

extern "C" int __declspec(dllexport) __stdcall Unload()
{
  TPluginLink.DestroyServiceFunction(MakraService);
  TPluginLink.CallService(AQQ_CONTROLS_DESTROYPOPUPMENU ,0,(LPARAM)(&TPluginAction));
  TPluginLink.CallService(AQQ_CONTROLS_TOOLBAR "ToolDown" AQQ_CONTROLS_DESTROYBUTTON ,0,(LPARAM)(&TPluginAction));

  return 0;
}