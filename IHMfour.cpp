#include <vcl.h>
#pragma hdrstop

#include "IHMfour.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
	FOUR = new four(); //nouvel objet four
	Timer1->Enabled=true;  //Active Le timer1
	volt=2;
}

//---------------------------------------------------------------------------

void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
   temperature=FOUR->Lecture(); //stockage dans la variable 'temperature'
   LblTemp->Caption=temperature;  //affichage de la température
}

//---------------------------------------------------------------------------

void __fastcall TForm1::Timer2Timer(TObject *Sender)
{
	FOUR->Ecriture(volt); //ecriture

	if(temperature-2>Tcom)
	{
		volt=0;  //Met le voltage a 0
	}
	if(temperature<Tcom)
	{
		volt+=0.2; //On chauffe progressivement
	}


}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------


void __fastcall TForm1::BtnArretClick(TObject *Sender)
{
FOUR->Ecriture(0); //on met le voltage à 0V pour arreter de chauffer
volt= 2;
Timer2->Enabled=false;

}
//---------------------------------------------------------------------------


void __fastcall TForm1::ListTempChange(TObject *Sender)
{
	FOUR->Ecriture(ListTemp->Text.ToDouble()/10); //ecriture du pourcentage en V
}
//---------------------------------------------------------------------------






