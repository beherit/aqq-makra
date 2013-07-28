//---------------------------------------------------------------------------
#include <vcl.h>
#include <windows.h>
#pragma hdrstop
#pragma argsused
#include "Aqq.h"
//---------------------------------------------------------------------------

int WINAPI DllEntryPoint(HINSTANCE hinst, unsigned long reason, void* lpReserved)
{
        return 1;
}

// Utworzenie obiektow do struktur
PluginAction TPluginActionPopupmenu;
PluginAction TPluginActionButton;
PluginAction TPluginActionPolaczone;
PluginAction TPluginActionWolne;
PluginAction TPluginActionOddalone;
PluginAction TPluginActionNieobecne;
PluginAction TPluginActionNiePrzeszkadzac;
PluginAction TPluginActionNiewidoczne;
PluginAction TPluginActionRozlaczone;
PluginAction TPluginActionOpis;
PluginAction TPluginActionSeparator;
PluginLink TPluginLink;
PluginInfo TPluginInfo;

//Program
extern "C"  __declspec(dllexport) PluginInfo* __stdcall AQQPluginInfo(DWORD AQQVersion)
{
  TPluginInfo.cbSize = sizeof(PluginInfo);
  TPluginInfo.ShortName = (wchar_t*)L"Makra";
  TPluginInfo.Version = PLUGIN_MAKE_VERSION(0,0,3,2);
  TPluginInfo.Description = (wchar_t *)L"Dodaje makra do g³ównego okna";
  TPluginInfo.Author = (wchar_t *)L"Krzysztof Grochocki (Beherit)";
  TPluginInfo.AuthorMail = (wchar_t *)L"beherit666@vp.pl";
  TPluginInfo.Copyright = (wchar_t *)L"Krzysztof Grochocki (Beherit)";
  TPluginInfo.Homepage = (wchar_t *)L"";
 
  return &TPluginInfo;
}

void PrzypiszPopupmenu()
{
  TPluginActionPopupmenu.cbSize = sizeof(PluginAction);
  TPluginActionPopupmenu.pszName = L"MakraPopup";
  TPluginActionPopupmenu.pszCaption = (wchar_t*) L"MakraPopup";
  TPluginActionPopupmenu.pszPopupName = (wchar_t*) L"MakraPopup";
  TPluginLink.CallService(AQQ_CONTROLS_CREATEPOPUPMENU,0,(LPARAM)(&TPluginActionPopupmenu));
}

void PrzypiszButton()
{
  TPluginActionButton.cbSize = sizeof(PluginAction);
  TPluginActionButton.pszName = L"MakraButton";
  TPluginActionButton.pszCaption = (wchar_t*) L"MakraButton";
  TPluginActionButton.Position = 114;
  TPluginActionButton.IconIndex = 63;
  TPluginActionButton.pszPopupName = (wchar_t*) L"MakraPopup";
  TPluginLink.CallService(AQQ_CONTROLS_TOOLBAR "ToolDown" AQQ_CONTROLS_CREATEBUTTON,0,(LPARAM)(&TPluginActionButton));
}

void PrzypiszKontaPolaczone()
{
  TPluginActionPolaczone.cbSize = sizeof(PluginAction);
  TPluginActionPolaczone.Action = (wchar_t*) L"aMacroOnline";
  TPluginActionPolaczone.pszName = (wchar_t*)L"MakraPrzypiszKontaPolaczone";
  TPluginActionPolaczone.Position = 1;
  TPluginActionPolaczone.pszPopupName = (wchar_t*) L"MakraPopup";
  TPluginLink.CallService(AQQ_CONTROLS_CREATEPOPUPMENUITEM,0,(LPARAM)(&TPluginActionPolaczone));
}

void PrzypiszKontaWolne()
{
  TPluginActionWolne.cbSize = sizeof(PluginAction);
  TPluginActionWolne.Action = (wchar_t*) L"aMacroChat";
  TPluginActionWolne.pszName = (wchar_t*)L"MakraPrzypiszKontaWolne";
  TPluginActionWolne.Position = 2;
  TPluginActionWolne.pszPopupName = (wchar_t*) L"MakraPopup";
  TPluginLink.CallService(AQQ_CONTROLS_CREATEPOPUPMENUITEM,0,(LPARAM)(&TPluginActionWolne));

  TPluginActionSeparator.cbSize = sizeof(PluginAction);
  TPluginActionSeparator.pszCaption = (wchar_t*) L"-";
  TPluginActionSeparator.pszName = (wchar_t*)L"MakraPrzypiszKontaWolneSeparator";
  TPluginActionSeparator.Position = 3;
  TPluginActionSeparator.pszPopupName = (wchar_t*) L"MakraPopup";
  TPluginLink.CallService(AQQ_CONTROLS_CREATEPOPUPMENUITEM,0,(LPARAM)(&TPluginActionSeparator));
}

void PrzypiszKontaOddalone()
{
  TPluginActionOddalone.cbSize = sizeof(PluginAction);
  TPluginActionOddalone.Action = (wchar_t*) L"aMacroAway";
  TPluginActionOddalone.pszName = (wchar_t*)L"MakraPrzypiszKontaOddalone";
  TPluginActionOddalone.Position = 4;
  TPluginActionOddalone.pszPopupName = (wchar_t*) L"MakraPopup";
  TPluginLink.CallService(AQQ_CONTROLS_CREATEPOPUPMENUITEM,0,(LPARAM)(&TPluginActionOddalone));
}

void PrzypiszKontaNieobecne()
{
  TPluginActionNieobecne.cbSize = sizeof(PluginAction);
  TPluginActionNieobecne.Action = (wchar_t*) L"aMacroXA";
  TPluginActionNieobecne.pszName = (wchar_t*)L"MakraPrzypiszKontaNieobecne";
  TPluginActionNieobecne.Position = 5;
  TPluginActionNieobecne.pszPopupName = (wchar_t*) L"MakraPopup";
  TPluginLink.CallService(AQQ_CONTROLS_CREATEPOPUPMENUITEM,0,(LPARAM)(&TPluginActionNieobecne));
}

void PrzypiszKontaNiePrzeszkadzac()
{
  TPluginActionNiePrzeszkadzac.cbSize = sizeof(PluginAction);
  TPluginActionNiePrzeszkadzac.Action = (wchar_t*) L"aMacroDND";
  TPluginActionNiePrzeszkadzac.pszName = (wchar_t*)L"MakraPrzypiszKontaNiePrzeszkadzac";
  TPluginActionNiePrzeszkadzac.Position = 6;
  TPluginActionNiePrzeszkadzac.pszPopupName = (wchar_t*) L"MakraPopup";
  TPluginLink.CallService(AQQ_CONTROLS_CREATEPOPUPMENUITEM,0,(LPARAM)(&TPluginActionNiePrzeszkadzac));

  TPluginActionSeparator.cbSize = sizeof(PluginAction);
  TPluginActionSeparator.pszCaption = (wchar_t*) L"-";
  TPluginActionSeparator.pszName = (wchar_t*)L"MakraPrzypiszKontaNiePrzeszkadzacSeparator";
  TPluginActionSeparator.Position = 7;
  TPluginActionSeparator.pszPopupName = (wchar_t*) L"MakraPopup";
  TPluginLink.CallService(AQQ_CONTROLS_CREATEPOPUPMENUITEM,0,(LPARAM)(&TPluginActionSeparator));
}

void PrzypiszKontaNiewidoczne()
{
  TPluginActionNiewidoczne.cbSize = sizeof(PluginAction);
  TPluginActionNiewidoczne.Action = (wchar_t*) L"aMacroInvisible";
  TPluginActionNiewidoczne.pszName = (wchar_t*)L"MakraPrzypiszKontaNiewidoczne";
  TPluginActionNiewidoczne.Position = 8;
  TPluginActionNiewidoczne.pszPopupName = (wchar_t*) L"MakraPopup";
  TPluginLink.CallService(AQQ_CONTROLS_CREATEPOPUPMENUITEM,0,(LPARAM)(&TPluginActionNiewidoczne));
}

void PrzypiszKontaRozlaczone()
{
  TPluginActionRozlaczone.cbSize = sizeof(PluginAction);
  TPluginActionRozlaczone.Action = (wchar_t*) L"aMacroOffline";
  TPluginActionRozlaczone.pszName = (wchar_t*)L"MakraPrzypiszKontaRozlaczone";
  TPluginActionRozlaczone.Position = 9;
  TPluginActionRozlaczone.pszPopupName = (wchar_t*) L"MakraPopup";
  TPluginLink.CallService(AQQ_CONTROLS_CREATEPOPUPMENUITEM,0,(LPARAM)(&TPluginActionRozlaczone));

  TPluginActionSeparator.cbSize = sizeof(PluginAction);
  TPluginActionSeparator.pszCaption = (wchar_t*) L"-";
  TPluginActionSeparator.pszName = (wchar_t*)L"MakraPrzypiszKontaRozlaczoneSeparator";
  TPluginActionSeparator.Position = 10;
  TPluginActionSeparator.pszPopupName = (wchar_t*) L"MakraPopup";
  TPluginLink.CallService(AQQ_CONTROLS_CREATEPOPUPMENUITEM,0,(LPARAM)(&TPluginActionSeparator));
}

void PrzypiszZmienOpis()
{
  TPluginActionOpis.cbSize = sizeof(PluginAction);
  TPluginActionOpis.Action = (wchar_t*) L"aNote";
  TPluginActionOpis.pszName = (wchar_t*)L"MakraPrzypiszZmienOpis";
  TPluginActionOpis.Position = 11;
  TPluginActionOpis.pszPopupName = (wchar_t*) L"MakraPopup";
  TPluginLink.CallService(AQQ_CONTROLS_CREATEPOPUPMENUITEM,0,(LPARAM)(&TPluginActionOpis));
}

extern "C" int __declspec(dllexport) __stdcall Load(PluginLink *Link)
{
  TPluginLink = *Link;
  PrzypiszPopupmenu();
  PrzypiszButton();
  PrzypiszKontaPolaczone();
  PrzypiszKontaWolne();
  PrzypiszKontaOddalone();
  PrzypiszKontaNieobecne();
  PrzypiszKontaNiePrzeszkadzac();
  PrzypiszKontaNiewidoczne();
  PrzypiszKontaRozlaczone();
  PrzypiszZmienOpis();

  return 0;
}

extern "C" int __declspec(dllexport) __stdcall Unload()
{
  TPluginLink.CallService(AQQ_CONTROLS_DESTROYPOPUPMENUITEM ,0,(LPARAM)(&TPluginActionPolaczone));
  TPluginLink.CallService(AQQ_CONTROLS_DESTROYPOPUPMENUITEM ,0,(LPARAM)(&TPluginActionWolne));
  TPluginLink.CallService(AQQ_CONTROLS_DESTROYPOPUPMENUITEM ,0,(LPARAM)(&TPluginActionOddalone));
  TPluginLink.CallService(AQQ_CONTROLS_DESTROYPOPUPMENUITEM ,0,(LPARAM)(&TPluginActionNieobecne));
  TPluginLink.CallService(AQQ_CONTROLS_DESTROYPOPUPMENUITEM ,0,(LPARAM)(&TPluginActionNiePrzeszkadzac));
  TPluginLink.CallService(AQQ_CONTROLS_DESTROYPOPUPMENUITEM ,0,(LPARAM)(&TPluginActionNiewidoczne));
  TPluginLink.CallService(AQQ_CONTROLS_DESTROYPOPUPMENUITEM ,0,(LPARAM)(&TPluginActionRozlaczone));
  TPluginLink.CallService(AQQ_CONTROLS_DESTROYPOPUPMENUITEM ,0,(LPARAM)(&TPluginActionOpis));
  TPluginLink.CallService(AQQ_CONTROLS_DESTROYPOPUPMENUITEM ,0,(LPARAM)(&TPluginActionSeparator));
  TPluginLink.CallService(AQQ_CONTROLS_DESTROYPOPUPMENU ,0,(LPARAM)(&TPluginActionPopupmenu));
  TPluginLink.CallService(AQQ_CONTROLS_TOOLBAR "ToolDown" AQQ_CONTROLS_DESTROYBUTTON ,0,(LPARAM)(&TPluginActionButton));

  return 0;
}