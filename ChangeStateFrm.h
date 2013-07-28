//---------------------------------------------------------------------------

#ifndef ChangeStateFrmH
#define ChangeStateFrmH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include <ExtCtrls.hpp>
#include "XPMan.hpp"
//---------------------------------------------------------------------------
class TChangeStateForm : public TForm
{
__published:	// IDE-managed Components
        TComboBox *StateBox;
        TTimer *Timer;
        TXPMan *XPMan;
        void __fastcall FormShow(TObject *Sender);
        void __fastcall TimerTimer(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
private:	// User declarations
public:		// User declarations
        __fastcall TChangeStateForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TChangeStateForm *ChangeStateForm;
//---------------------------------------------------------------------------
#endif
