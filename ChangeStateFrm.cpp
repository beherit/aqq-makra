//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include "ChangeStateFrm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "XPMan"
#pragma resource "*.dfm"
TChangeStateForm *ChangeStateForm;
//---------------------------------------------------------------------------
int TMPLeft;
int TMPTop;
//---------------------------------------------------------------------------
__fastcall TChangeStateForm::TChangeStateForm(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TChangeStateForm::FormShow(TObject *Sender)
{
  TMPLeft=0;
  TMPTop=0;
  StateBox->ItemIndex = 7;
  Timer->Enabled=true;
  ShowWindow(Application->Handle, SW_HIDE);
}
//---------------------------------------------------------------------------

void __fastcall TChangeStateForm::TimerTimer(TObject *Sender)
{
  HWND hVWnd = FindWindow("TfrmSetState",NULL);
  if(hVWnd!=NULL)
  {
    TRect rRect;
    GetWindowRect(hVWnd,&rRect);
    hVWnd = FindWindow("TChangeStateForm",NULL);
    if((TMPLeft!=rRect.Left)||(TMPTop!=rRect.Top))
    {
      SetWindowPos(hVWnd,HWND_TOPMOST,rRect.Left+181,rRect.Top+101,0,0,SWP_NOSIZE);
      TMPLeft=rRect.Left;
      TMPTop=rRect.Top;
    }
    StateBox->Visible=true;
  }
}
//---------------------------------------------------------------------------

void __fastcall TChangeStateForm::FormClose(TObject *Sender,
      TCloseAction &Action)
{
  Timer->Enabled=false;
}
//---------------------------------------------------------------------------

