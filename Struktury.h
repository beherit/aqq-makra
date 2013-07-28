#ifndef Struktury_H
#define Struktury_H

typedef int __stdcall(*AQQHook) (WPARAM, LPARAM);
typedef int __stdcall(*AQQService) (WPARAM,LPARAM);

struct PluginInfo
{
 unsigned int cbSize;
 wchar_t * ShortName;
 DWORD Version;
 wchar_t * Description;
 wchar_t * Author;
 wchar_t * AuthorMail;
 wchar_t * Copyright;
 wchar_t * Homepage;
 BYTE Flag;
 int ReplaceDefaultModule;
};

struct PluginLink
{
 wchar_t* Path;
 HANDLE (__stdcall *CreateHookableEvent)(const wchar_t*);
 int (__stdcall *DestroyHookableEvent)(HANDLE);
 int (__stdcall *NotifyEventHooks)(HANDLE, WPARAM, LPARAM);
 HANDLE (__stdcall *HookEvent)(const wchar_t*, AQQHook);
 HANDLE (__stdcall *HookEventMessage)(const wchar_t*, HWND, UINT);
 int (__stdcall *UnhookEvent)(HANDLE);
 HANDLE (__stdcall *CreateServiceFunction)(const wchar_t*, AQQService);
 HANDLE (__stdcall *CreateTransientServiceFunction);
 int (__stdcall *DestroyServiceFunction)(HANDLE);
 int (__stdcall *CallService)(const wchar_t*, WPARAM, LPARAM);
 int (__stdcall *ServiceExists)(const wchar_t*);
};


struct PluginAction
{
 int cbSize;
 const wchar_t * Action;
 const wchar_t * pszName;
 const wchar_t * pszCaption;
 DWORD Flags;
 int Position;
 int IconIndex;
 const wchar_t * pszService;
 const wchar_t * pszPopupName;
 int PopupPosition;
 DWORD HotKey;
 const wchar_t * pszContactOwner;
 int GroupIndex;
 bool AutoCheck;
 bool Checked;
 HANDLE Cardinal;
 const wchar_t * ShortCut;
};

#endif

