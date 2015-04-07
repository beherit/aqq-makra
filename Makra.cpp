//---------------------------------------------------------------------------
// Copyright (C) 2008-2015 Krzysztof Grochocki
//
// This file is part of Makra
//
// Makra is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 3, or (at your option)
// any later version.
//
// Makra is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with GNU Radio. If not, see <http://www.gnu.org/licenses/>.
//---------------------------------------------------------------------------

#include <vcl.h>
#include <windows.h>
#include <PluginAPI.h>
#pragma hdrstop

int WINAPI DllEntryPoint(HINSTANCE hinst, unsigned long reason, void* lpReserved)
{
	return 1;
}
//---------------------------------------------------------------------------

//Struktury-glowne-----------------------------------------------------------
TPluginLink PluginLink;
TPluginInfo PluginInfo;
//---------------------------------------------------------------------------

//Usuwanie przycisku makr
void DestroyMacroItems()
{
	//Usuwanie PopUpMenu
	TPluginAction MakraPopUp;
	ZeroMemory(&MakraPopUp, sizeof(TPluginAction));
	MakraPopUp.cbSize = sizeof(TPluginAction);
	MakraPopUp.pszName = L"MakraPopUp";
	PluginLink.CallService(AQQ_CONTROLS_DESTROYPOPUPMENU, 0, (LPARAM)(&MakraPopUp));
	//Usuwanie elementow popupmenu
	for(int Count=1 ;Count<=11; Count++)
	{
		TPluginAction MakraPopUpItem;
		ZeroMemory(&MakraPopUpItem,sizeof(TPluginAction));
		MakraPopUpItem.cbSize = sizeof(TPluginAction);
		UnicodeString ItemName = "MakraPopUpItem"+IntToStr(Count);
		MakraPopUpItem.pszName = ItemName.w_str();
		PluginLink.CallService(AQQ_CONTROLS_DESTROYPOPUPMENUITEM , 0, (LPARAM)(&MakraPopUpItem));
	}
	//Usuwanie buttona w oknie kontatkow
	TPluginAction FrmMainMakraButton;
	ZeroMemory(&FrmMainMakraButton,sizeof(TPluginAction));
	FrmMainMakraButton.cbSize = sizeof(TPluginAction);
	FrmMainMakraButton.pszName = L"FrmMainMakraButton";
	PluginLink.CallService(AQQ_CONTROLS_TOOLBAR "ToolDown" AQQ_CONTROLS_DESTROYBUTTON , 0, (LPARAM)(&FrmMainMakraButton));
}
//---------------------------------------------------------------------------

//Tworzenie przycisku makr
void BuildMacroItems()
{
	//Tworzenie PopUpMenu
	TPluginAction MakraPopUp;
	ZeroMemory(&MakraPopUp, sizeof(TPluginAction));
	MakraPopUp.cbSize = sizeof(TPluginAction);
	MakraPopUp.pszName = L"MakraPopUp";
	PluginLink.CallService(AQQ_CONTROLS_CREATEPOPUPMENU, 0, (LPARAM)(&MakraPopUp));
	//Tworzenie buttona w oknie kontaktów
	TPluginAction FrmMainMakraButton;
	ZeroMemory(&FrmMainMakraButton,sizeof(TPluginAction));
	FrmMainMakraButton.cbSize = sizeof(TPluginAction);
	FrmMainMakraButton.pszName = L"FrmMainMakraButton";
	FrmMainMakraButton.Position = 114;
	FrmMainMakraButton.IconIndex = 63;
	FrmMainMakraButton.pszPopupName = L"MakraPopUp";
	PluginLink.CallService(AQQ_CONTROLS_TOOLBAR "ToolDown" AQQ_CONTROLS_CREATEBUTTON, 0, (LPARAM)(&FrmMainMakraButton));
	//Tworzenie elementow popupmenu
	for(int Count=1 ;Count<=11; Count++)
	{
		TPluginAction MakraPopUpItem;
		ZeroMemory(&MakraPopUpItem, sizeof(TPluginAction));
		MakraPopUpItem.cbSize = sizeof(TPluginAction);		
		UnicodeString ItemName = "MakraPopUpItem"+IntToStr(Count);
		MakraPopUpItem.pszName = ItemName.w_str();		
		MakraPopUpItem.Position = Count;
		MakraPopUpItem.pszPopupName = L"MakraPopUp";		
		if(Count==1)
		{
			MakraPopUpItem.Action = L"aMacroOnline";
			MakraPopUpItem.pszCaption = L"";			
		}
		else if(Count==2)
		{
			MakraPopUpItem.Action = L"aMacroChat";
			MakraPopUpItem.pszCaption = L"";			
		}
		else if((Count==3)||(Count==7)||(Count==10))
		{
			MakraPopUpItem.Action = L"";
			MakraPopUpItem.pszCaption = L"-";			
		}
		else if(Count==4)
		{
			MakraPopUpItem.Action = L"aMacroAway";
			MakraPopUpItem.pszCaption = L"";			
		}
		else if(Count==5)
		{
			MakraPopUpItem.Action = L"aMacroXA";
			MakraPopUpItem.pszCaption = L"";			
		}
		else if(Count==6)
		{
			MakraPopUpItem.Action = L"aMacroDND";
			MakraPopUpItem.pszCaption = L"";			
		}
		else if(Count==8)
		{
			MakraPopUpItem.Action = L"aMacroInvisible";
			MakraPopUpItem.pszCaption = L"";			
		}
		else if(Count==9)
		{
			MakraPopUpItem.Action = L"aMacroOffline";
			MakraPopUpItem.pszCaption = L"";			
		}
		else if(Count==11)
		{
			MakraPopUpItem.Action = L"aNote";
			MakraPopUpItem.pszCaption = L"";			
		}
		PluginLink.CallService(AQQ_CONTROLS_CREATEPOPUPMENUITEM, 0, (LPARAM)(&MakraPopUpItem));
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
	PluginInfo.Version = PLUGIN_MAKE_VERSION(2,2,1,0);
	PluginInfo.Description = L"Wtyczka dodaje funkcjonalnoœæ makr, znan¹ ze starych, pocz¹tkowych wersji beta komunikatora AQQ, która kry³a siê pod ikonk¹ pioruna.";
	PluginInfo.Author = L"Krzysztof Grochocki (Beherit)";
	PluginInfo.AuthorMail = L"kontakt@beherit.pl";
	PluginInfo.Copyright = L"Krzysztof Grochocki (Beherit)";
	PluginInfo.Homepage = L"http://beherit.pl";
	PluginInfo.Flag = 0;
	PluginInfo.ReplaceDefaultModule = 0;

	return &PluginInfo;
}
//---------------------------------------------------------------------------
