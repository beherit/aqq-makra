#include <vcl.h>
#include <windows.h>
#pragma hdrstop
#pragma argsused
#include <PluginAPI.h>

int WINAPI DllEntryPoint(HINSTANCE hinst, unsigned long reason, void* lpReserved)
{
	return 1;
}
//---------------------------------------------------------------------------

//Struktury-glowne-----------------------------------------------------------
TPluginLink PluginLink;
TPluginInfo PluginInfo;
TPluginAction PluginAction;
//---------------------------------------------------------------------------

//Usuwanie przycisku makr
void DestroyMacroItems()
{
  for(int Count=0;Count<=12;Count++)
  {
    //Wielkosc struktury
	PluginAction.cbSize = sizeof(TPluginAction);
	//Uzupelnianie nazwy itemu
	if(Count==0) PluginAction.pszName = L"MakraPopUp";
	else if(Count==1) PluginAction.pszName = L"MakraButton";
	else if(Count==2) PluginAction.pszName = L"MakraOnlineItem";
	else if(Count==3) PluginAction.pszName = L"MakraFreeForChatItem";
	else if(Count==4) PluginAction.pszName = L"MakraSeparatorItem1";
	else if(Count==5) PluginAction.pszName = L"MakraAwayItem";
	else if(Count==6) PluginAction.pszName = L"MakraXAItem";
	else if(Count==7) PluginAction.pszName = L"MakraDNDItem";
	else if(Count==8) PluginAction.pszName = L"MakraSeparatorItem2";
	else if(Count==9) PluginAction.pszName = L"MakraInvisibleItem";
	else if(Count==10) PluginAction.pszName = L"MakraOfflineItem";
	else if(Count==11) PluginAction.pszName = L"MakraSeparatorItem3";
	else if(Count==12) PluginAction.pszName = L"MakraNoteItem";
	//Usuwanie danego itema lub popupmenu/buttona
	if(Count==0) PluginLink.CallService(AQQ_CONTROLS_DESTROYPOPUPMENU,0,(LPARAM)(&PluginAction));
	else if(Count==1) PluginLink.CallService(AQQ_CONTROLS_TOOLBAR "ToolDown" AQQ_CONTROLS_DESTROYBUTTON,0,(LPARAM)(&PluginAction));
	else PluginLink.CallService(AQQ_CONTROLS_DESTROYPOPUPMENUITEM,0,(LPARAM)(&PluginAction));
  }
}
//---------------------------------------------------------------------------

//Tworzenie przycisku makr
void BuildMacroItems()
{
  for(int Count=0;Count<=12;Count++)
  {
	//Tworzenie menu
	if(Count==0)
	{
	  PluginAction.cbSize = sizeof(TPluginAction);
	  PluginAction.Action = L"";
	  PluginAction.pszCaption = L"";
	  PluginAction.pszName = L"MakraPopUp";
	  PluginAction.Position = 0;
	  PluginAction.IconIndex = 0;
	  PluginAction.pszPopupName = L"";
	  PluginLink.CallService(AQQ_CONTROLS_CREATEPOPUPMENU,0,(LPARAM)(&PluginAction));
	}
	//Tworzenie przycisku
	else if(Count==1)
	{
	  PluginAction.cbSize = sizeof(TPluginAction);
	  PluginAction.Action = L"";
	  PluginAction.pszCaption = L"";
	  PluginAction.pszName = L"MakraButton";
	  PluginAction.Position = 114;
	  PluginAction.IconIndex = 63;
	  PluginAction.pszPopupName = L"MakraPopUp";
	  PluginLink.CallService(AQQ_CONTROLS_TOOLBAR "ToolDown" AQQ_CONTROLS_CREATEBUTTON,0,(LPARAM)(&PluginAction));
	}
	//Tworzenie przycisku "Konta polaczone"
	else if(Count==2)
	{
	  PluginAction.cbSize = sizeof(TPluginAction);
	  PluginAction.Action = L"aMacroOnline";
	  PluginAction.pszCaption = L"";
	  PluginAction.pszName = L"MakraOnlineItem";
	  PluginAction.Position = 1;
	  PluginAction.IconIndex = 0;
	  PluginAction.pszPopupName = L"MakraPopUp";
	  PluginLink.CallService(AQQ_CONTROLS_CREATEPOPUPMENUITEM,0,(LPARAM)(&PluginAction));
	}
	//Tworzenie przycisku "Konta wolne"
	else if(Count==3)
	{
	  PluginAction.cbSize = sizeof(TPluginAction);
	  PluginAction.Action = L"aMacroChat";
	  PluginAction.pszCaption = L"";
	  PluginAction.pszName = L"MakraFreeForChatItem";
	  PluginAction.Position = 2;
	  PluginAction.IconIndex = 0;
	  PluginAction.pszPopupName = L"MakraPopUp";
	  PluginLink.CallService(AQQ_CONTROLS_CREATEPOPUPMENUITEM,0,(LPARAM)(&PluginAction));
	}
	//Tworzenie separatora
	else if(Count==4)
	{
	  PluginAction.cbSize = sizeof(TPluginAction);
	  PluginAction.Action = L"";
	  PluginAction.pszCaption = L"-";
	  PluginAction.pszName = L"MakraSeparatorItem1";
	  PluginAction.Position = 3;
	  PluginAction.IconIndex = 0;
	  PluginAction.pszPopupName = L"MakraPopUp";
	  PluginLink.CallService(AQQ_CONTROLS_CREATEPOPUPMENUITEM,0,(LPARAM)(&PluginAction));
	}
	//Tworzenie przycisku "Konta oddalone"
	else if(Count==5)
	{
	  PluginAction.cbSize = sizeof(TPluginAction);
	  PluginAction.Action = L"aMacroAway";
	  PluginAction.pszCaption = L"";
	  PluginAction.pszName = L"MakraAwayItem";
	  PluginAction.Position = 4;
	  PluginAction.IconIndex = 0;
	  PluginAction.pszPopupName = L"MakraPopUp";
	  PluginLink.CallService(AQQ_CONTROLS_CREATEPOPUPMENUITEM,0,(LPARAM)(&PluginAction));
	}
	//Tworzenie przycisku "Konta nieobecne"
	else if(Count==6)
	{
	  PluginAction.cbSize = sizeof(TPluginAction);
	  PluginAction.Action = L"aMacroXA";
	  PluginAction.pszCaption = L"";
	  PluginAction.pszName = L"MakraXAItem";
	  PluginAction.Position = 5;
	  PluginAction.IconIndex = 0;
	  PluginAction.pszPopupName = L"MakraPopUp";
	  PluginLink.CallService(AQQ_CONTROLS_CREATEPOPUPMENUITEM,0,(LPARAM)(&PluginAction));
	}
	//Tworzenie przycisku "Konta nie przeszkadzac"
	else if(Count==7)
	{
	  PluginAction.cbSize = sizeof(TPluginAction);
	  PluginAction.Action = L"aMacroDND";
	  PluginAction.pszCaption = L"";
	  PluginAction.pszName = L"MakraDNDItem";
	  PluginAction.Position = 6;
	  PluginAction.IconIndex = 0;
	  PluginAction.pszPopupName = L"MakraPopUp";
	  PluginLink.CallService(AQQ_CONTROLS_CREATEPOPUPMENUITEM,0,(LPARAM)(&PluginAction));
	}
	//Tworzenie separatora
	else if(Count==8)
	{
	  PluginAction.cbSize = sizeof(TPluginAction);
	  PluginAction.Action = L"";
	  PluginAction.pszCaption = L"-";
	  PluginAction.pszName = L"MakraSeparatorItem2";
	  PluginAction.Position = 7;
	  PluginAction.IconIndex = 0;
	  PluginAction.pszPopupName = L"MakraPopUp";
	  PluginLink.CallService(AQQ_CONTROLS_CREATEPOPUPMENUITEM,0,(LPARAM)(&PluginAction));
	}
	//Tworzenie przycisku "Konta niewidoczne"
	else if(Count==9)
	{
	  PluginAction.cbSize = sizeof(TPluginAction);
	  PluginAction.Action = L"aMacroInvisible";
	  PluginAction.pszCaption = L"";
	  PluginAction.pszName = L"MakraInvisibleItem";
	  PluginAction.Position = 8;
	  PluginAction.IconIndex = 0;
	  PluginAction.pszPopupName = L"MakraPopUp";
	  PluginLink.CallService(AQQ_CONTROLS_CREATEPOPUPMENUITEM,0,(LPARAM)(&PluginAction));
	}
	//Tworzenie przycisku "Konta rozlaczone"
	else if(Count==10)
	{
	  PluginAction.cbSize = sizeof(TPluginAction);
	  PluginAction.Action = L"aMacroOffline";
	  PluginAction.pszCaption = L"";
	  PluginAction.pszName = L"MakraOfflineItem";
	  PluginAction.Position = 9;
	  PluginAction.IconIndex = 0;
	  PluginAction.pszPopupName = L"MakraPopUp";
	  PluginLink.CallService(AQQ_CONTROLS_CREATEPOPUPMENUITEM,0,(LPARAM)(&PluginAction));
	}
	//Tworzenie separatora
	else if(Count==11)
	{
	  PluginAction.cbSize = sizeof(TPluginAction);
	  PluginAction.Action = L"";
	  PluginAction.pszCaption = L"-";
	  PluginAction.pszName = L"MakraSeparatorItem3";
	  PluginAction.Position = 10;
	  PluginAction.IconIndex = 0;
	  PluginAction.pszPopupName = L"MakraPopUp";
	  PluginLink.CallService(AQQ_CONTROLS_CREATEPOPUPMENUITEM,0,(LPARAM)(&PluginAction));
	}
	//Tworzenie przycisku "Zmien opis..."
	else if(Count==12)
	{
	  PluginAction.cbSize = sizeof(TPluginAction);
	  PluginAction.Action = L"aNote";
	  PluginAction.pszCaption = L"";
	  PluginAction.pszName = L"MakraNoteItem";
	  PluginAction.Position = 11;
	  PluginAction.IconIndex = 0;
	  PluginAction.pszPopupName = L"MakraPopUp";
	  PluginLink.CallService(AQQ_CONTROLS_CREATEPOPUPMENUITEM,0,(LPARAM)(&PluginAction));
	}
  }
}
//---------------------------------------------------------------------------

//Zaladowanie wtyczki
extern "C" int __declspec(dllexport) __stdcall Load(PPluginLink Link)
{
  //Linkowanie wtyczki z komunikatorem
  PluginLink = *Link;
  //Tworzenie przycisku makr
  BuildMacroItems();

  return 0;
}
//---------------------------------------------------------------------------

//Wyladowanie wtyczki
extern "C" int __declspec(dllexport) __stdcall Unload()
{
  //Usuwanie przycisku makr
  DestroyMacroItems();

  return 0;
}
//---------------------------------------------------------------------------

//Informacje o wtyczce
extern "C" __declspec(dllexport) PPluginInfo __stdcall AQQPluginInfo(DWORD AQQVersion)
{
  PluginInfo.cbSize = sizeof(TPluginInfo);
  PluginInfo.ShortName = L"Makra";
  PluginInfo.Version = PLUGIN_MAKE_VERSION(2,1,0,0);
  PluginInfo.Description = L"Wtyczka dodaje funkcjonalnoœæ makr, znan¹ ze starych, pocz¹tkowych wersji beta komunikatora AQQ, która kry³a siê pod ikonk¹ pioruna.";
  PluginInfo.Author = L"Krzysztof Grochocki (Beherit)";
  PluginInfo.AuthorMail = L"kontakt@beherit.pl";
  PluginInfo.Copyright = L"Krzysztof Grochocki (Beherit)";
  PluginInfo.Homepage = L"http://beherit.pl";

  return &PluginInfo;
}
//---------------------------------------------------------------------------
