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
//---------------------------------------------------------------------------

// Utworzenie obiektow do struktur
TPluginAction PluginActionPopupmenu;
TPluginAction PluginActionButton;
TPluginAction PluginActionPolaczone;
TPluginAction PluginActionWolne;
TPluginAction PluginActionOddalone;
TPluginAction PluginActionNieobecne;
TPluginAction PluginActionNiePrzeszkadzac;
TPluginAction PluginActionNiewidoczne;
TPluginAction PluginActionRozlaczone;
TPluginAction PluginActionOpis;
TPluginAction PluginActionSeparator;
TPluginLink PluginLink;
TPluginInfo PluginInfo;

//Program
extern "C"  __declspec(dllexport) TPluginInfo* __stdcall AQQPluginInfo(DWORD AQQVersion)
{
  PluginInfo.cbSize = sizeof(TPluginInfo);
  PluginInfo.ShortName = (wchar_t*)L"Makra";
  PluginInfo.Version = PLUGIN_MAKE_VERSION(1,0,2,0);
  PluginInfo.Description = (wchar_t *)L"Dodaje makra do g³ównego okna";
  PluginInfo.Author = (wchar_t *)L"Krzysztof Grochocki (Beherit)";
  PluginInfo.AuthorMail = (wchar_t *)L"beherit666@vp.pl";
  PluginInfo.Copyright = (wchar_t *)L"Krzysztof Grochocki (Beherit)";
  PluginInfo.Homepage = (wchar_t *)L"";
 
  return &PluginInfo;
}
//---------------------------------------------------------------------------

void PrzypiszPopupmenu()
{
  PluginActionPopupmenu.cbSize = sizeof(TPluginAction);
  PluginActionPopupmenu.pszName = L"MakraPopup";
  PluginActionPopupmenu.pszCaption = (wchar_t*) L"MakraPopup";
  PluginActionPopupmenu.pszPopupName = (wchar_t*) L"MakraPopup";
  PluginLink.CallService(AQQ_CONTROLS_CREATEPOPUPMENU,0,(LPARAM)(&PluginActionPopupmenu));
}
//---------------------------------------------------------------------------

void PrzypiszButton()
{
  PluginActionButton.cbSize = sizeof(TPluginAction);
  PluginActionButton.pszName = L"MakraButton";
  PluginActionButton.pszCaption = (wchar_t*) L"MakraButton";
  PluginActionButton.Position = 114;
  PluginActionButton.IconIndex = 63;
  PluginActionButton.pszPopupName = (wchar_t*) L"MakraPopup";
  PluginLink.CallService(AQQ_CONTROLS_TOOLBAR "ToolDown" AQQ_CONTROLS_CREATEBUTTON,0,(LPARAM)(&PluginActionButton));
}
//---------------------------------------------------------------------------

void PrzypiszKontaPolaczone()
{
  PluginActionPolaczone.cbSize = sizeof(TPluginAction);
  PluginActionPolaczone.Action = (wchar_t*) L"aMacroOnline";
  PluginActionPolaczone.pszName = (wchar_t*)L"MakraPrzypiszKontaPolaczone";
  PluginActionPolaczone.Position = 1;
  PluginActionPolaczone.pszPopupName = (wchar_t*) L"MakraPopup";
  PluginLink.CallService(AQQ_CONTROLS_CREATEPOPUPMENUITEM,0,(LPARAM)(&PluginActionPolaczone));
}
//---------------------------------------------------------------------------

void PrzypiszKontaWolne()
{
  PluginActionWolne.cbSize = sizeof(TPluginAction);
  PluginActionWolne.Action = (wchar_t*) L"aMacroChat";
  PluginActionWolne.pszName = (wchar_t*)L"MakraPrzypiszKontaWolne";
  PluginActionWolne.Position = 2;
  PluginActionWolne.pszPopupName = (wchar_t*) L"MakraPopup";
  PluginLink.CallService(AQQ_CONTROLS_CREATEPOPUPMENUITEM,0,(LPARAM)(&PluginActionWolne));

  PluginActionSeparator.cbSize = sizeof(TPluginAction);
  PluginActionSeparator.pszCaption = (wchar_t*) L"-";
  PluginActionSeparator.pszName = (wchar_t*)L"MakraPrzypiszKontaWolneSeparator";
  PluginActionSeparator.Position = 3;
  PluginActionSeparator.pszPopupName = (wchar_t*) L"MakraPopup";
  PluginLink.CallService(AQQ_CONTROLS_CREATEPOPUPMENUITEM,0,(LPARAM)(&PluginActionSeparator));
}
//---------------------------------------------------------------------------

void PrzypiszKontaOddalone()
{
  PluginActionOddalone.cbSize = sizeof(TPluginAction);
  PluginActionOddalone.Action = (wchar_t*) L"aMacroAway";
  PluginActionOddalone.pszName = (wchar_t*)L"MakraPrzypiszKontaOddalone";
  PluginActionOddalone.Position = 4;
  PluginActionOddalone.pszPopupName = (wchar_t*) L"MakraPopup";
  PluginLink.CallService(AQQ_CONTROLS_CREATEPOPUPMENUITEM,0,(LPARAM)(&PluginActionOddalone));
}
//---------------------------------------------------------------------------

void PrzypiszKontaNieobecne()
{
  PluginActionNieobecne.cbSize = sizeof(TPluginAction);
  PluginActionNieobecne.Action = (wchar_t*) L"aMacroXA";
  PluginActionNieobecne.pszName = (wchar_t*)L"MakraPrzypiszKontaNieobecne";
  PluginActionNieobecne.Position = 5;
  PluginActionNieobecne.pszPopupName = (wchar_t*) L"MakraPopup";
  PluginLink.CallService(AQQ_CONTROLS_CREATEPOPUPMENUITEM,0,(LPARAM)(&PluginActionNieobecne));
}
//---------------------------------------------------------------------------

void PrzypiszKontaNiePrzeszkadzac()
{
  PluginActionNiePrzeszkadzac.cbSize = sizeof(TPluginAction);
  PluginActionNiePrzeszkadzac.Action = (wchar_t*) L"aMacroDND";
  PluginActionNiePrzeszkadzac.pszName = (wchar_t*)L"MakraPrzypiszKontaNiePrzeszkadzac";
  PluginActionNiePrzeszkadzac.Position = 6;
  PluginActionNiePrzeszkadzac.pszPopupName = (wchar_t*) L"MakraPopup";
  PluginLink.CallService(AQQ_CONTROLS_CREATEPOPUPMENUITEM,0,(LPARAM)(&PluginActionNiePrzeszkadzac));

  PluginActionSeparator.cbSize = sizeof(TPluginAction);
  PluginActionSeparator.pszCaption = (wchar_t*) L"-";
  PluginActionSeparator.pszName = (wchar_t*)L"MakraPrzypiszKontaNiePrzeszkadzacSeparator";
  PluginActionSeparator.Position = 7;
  PluginActionSeparator.pszPopupName = (wchar_t*) L"MakraPopup";
  PluginLink.CallService(AQQ_CONTROLS_CREATEPOPUPMENUITEM,0,(LPARAM)(&PluginActionSeparator));
}
//---------------------------------------------------------------------------

void PrzypiszKontaNiewidoczne()
{
  PluginActionNiewidoczne.cbSize = sizeof(TPluginAction);
  PluginActionNiewidoczne.Action = (wchar_t*) L"aMacroInvisible";
  PluginActionNiewidoczne.pszName = (wchar_t*)L"MakraPrzypiszKontaNiewidoczne";
  PluginActionNiewidoczne.Position = 8;
  PluginActionNiewidoczne.pszPopupName = (wchar_t*) L"MakraPopup";
  PluginLink.CallService(AQQ_CONTROLS_CREATEPOPUPMENUITEM,0,(LPARAM)(&PluginActionNiewidoczne));
}
//---------------------------------------------------------------------------

void PrzypiszKontaRozlaczone()
{
  PluginActionRozlaczone.cbSize = sizeof(TPluginAction);
  PluginActionRozlaczone.Action = (wchar_t*) L"aMacroOffline";
  PluginActionRozlaczone.pszName = (wchar_t*)L"MakraPrzypiszKontaRozlaczone";
  PluginActionRozlaczone.Position = 9;
  PluginActionRozlaczone.pszPopupName = (wchar_t*) L"MakraPopup";
  PluginLink.CallService(AQQ_CONTROLS_CREATEPOPUPMENUITEM,0,(LPARAM)(&PluginActionRozlaczone));

  PluginActionSeparator.cbSize = sizeof(TPluginAction);
  PluginActionSeparator.pszCaption = (wchar_t*) L"-";
  PluginActionSeparator.pszName = (wchar_t*)L"MakraPrzypiszKontaRozlaczoneSeparator";
  PluginActionSeparator.Position = 10;
  PluginActionSeparator.pszPopupName = (wchar_t*) L"MakraPopup";
  PluginLink.CallService(AQQ_CONTROLS_CREATEPOPUPMENUITEM,0,(LPARAM)(&PluginActionSeparator));
}
//---------------------------------------------------------------------------

void PrzypiszZmienOpis()
{
  PluginActionOpis.cbSize = sizeof(TPluginAction);
  PluginActionOpis.Action = (wchar_t*) L"aNote";
  PluginActionOpis.pszName = (wchar_t*)L"MakraPrzypiszZmienOpis";
  PluginActionOpis.Position = 11;
  PluginActionOpis.pszPopupName = (wchar_t*) L"MakraPopup";
  PluginLink.CallService(AQQ_CONTROLS_CREATEPOPUPMENUITEM,0,(LPARAM)(&PluginActionOpis));
}
//---------------------------------------------------------------------------

extern "C" int __declspec(dllexport) __stdcall Load(TPluginLink *Link)
{
  PluginLink = *Link;

  //Przypisywanie ikonki makra w g³ównym oknie
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
//---------------------------------------------------------------------------

extern "C" int __declspec(dllexport) __stdcall Unload()
{
  PluginLink.CallService(AQQ_CONTROLS_DESTROYPOPUPMENUITEM ,0,(LPARAM)(&PluginActionPolaczone));
  PluginLink.CallService(AQQ_CONTROLS_DESTROYPOPUPMENUITEM ,0,(LPARAM)(&PluginActionWolne));
  PluginLink.CallService(AQQ_CONTROLS_DESTROYPOPUPMENUITEM ,0,(LPARAM)(&PluginActionOddalone));
  PluginLink.CallService(AQQ_CONTROLS_DESTROYPOPUPMENUITEM ,0,(LPARAM)(&PluginActionNieobecne));
  PluginLink.CallService(AQQ_CONTROLS_DESTROYPOPUPMENUITEM ,0,(LPARAM)(&PluginActionNiePrzeszkadzac));
  PluginLink.CallService(AQQ_CONTROLS_DESTROYPOPUPMENUITEM ,0,(LPARAM)(&PluginActionNiewidoczne));
  PluginLink.CallService(AQQ_CONTROLS_DESTROYPOPUPMENUITEM ,0,(LPARAM)(&PluginActionRozlaczone));
  PluginLink.CallService(AQQ_CONTROLS_DESTROYPOPUPMENUITEM ,0,(LPARAM)(&PluginActionOpis));
  PluginLink.CallService(AQQ_CONTROLS_DESTROYPOPUPMENUITEM ,0,(LPARAM)(&PluginActionSeparator));
  PluginLink.CallService(AQQ_CONTROLS_DESTROYPOPUPMENU ,0,(LPARAM)(&PluginActionPopupmenu));
  PluginLink.CallService(AQQ_CONTROLS_TOOLBAR "ToolDown" AQQ_CONTROLS_DESTROYBUTTON ,0,(LPARAM)(&PluginActionButton));

  return 0;
}
//---------------------------------------------------------------------------
