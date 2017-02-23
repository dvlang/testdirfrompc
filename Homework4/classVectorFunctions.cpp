
#include "stdafx.h"
/* #include "classVectorPrimitives.h"
#include "classVectorFunctions.h"

int main ()
{
	int ii, ij;
	cout << "Enter number of bits of your operations: "; cin >> ii;
	vector (a, ii);
	vector (b, ii);
	vector (y, ii);
	vector (w, ii);
	vector (v, ii);
	vector (q1, ii); vector (q2, ii); vector (q3, ii); vector (q4, ii);
	line (s);
	line (ci); line (co);
	line (l); line (e); line (g);
	line (clk); line (rst); line (ld); line (en);
	
	char txt1[80], txt2[8], txt3[80], txt4[80];
	int int1;

	and* AND1=new and (a, b, w);
	xor* XOR1=new xor (a, b, w);
	 or*  OR1=new  or (w, a, y);
	xor* XOR2=new xor (y, b, w);
	nBitMux* MUX1=new nBitMux (a, y, s, w);
	nBitAdder* ADD1=new nBitAdder (w, y, ci, co, v);
	nBitComparator* CMP1=new nBitComparator (q1, y, l, e, g);
	dRegister* REG1=new dRegister (w, clk, q1);
		REG1->init("00110000", "Standard 8-bit D register");
	dRegisterRa* REG2=new dRegisterRa (y, clk, rst, q2);
	dRegisterRaE* REG3=new dRegisterRaE (y, clk, rst, en, q3);
	upCounter* CNT1=new upCounter (w, clk, ld, q4);

	do {
		cout << "Enter " << ii << " (or less) bits of a: "; cin >> a;
		cout << "Enter " << ii << " (or less) bits of b: "; cin >> b;
		cout << "Enter one bit for s: "; cin >> s;
		cout << "Enter one bit for ci: "; cin >> ci;

		cout << "Enter one bit for clk: "; cin >> clk;
		cout << "Enter one bit for rst: "; cin >> rst;
		cout << "Enter one bit for ld: "; cin >> ld;
		cout << "Enter one bit for en: "; cin >> en;

 		cout << "You Entered: "<<a<<" for "<<strlen(a)<< " bits of a.\n";
		cout << "You Entered: "<<b<<" for "<<strlen(b)<< " bits of b.\n";
		cout << "You Entered: "<<s<<" for "<<strlen(s)<< " bits of s.\n";

		REG1->info(txt1, txt2, txt3, int1, txt4);
		cout << "txt1: "<<txt1<<"\n";
		cout << "txt2: "<<txt2<<"\n";
		cout << "txt3: "<<txt3<<"\n";
		cout << "int1: "<<int1<<"\n";
		cout << "txt4: "<<txt4<<"\n";

		AND1->evl(); cout << "and (a,b,w): " << w << '\n';
		XOR1->evl(); cout << "xor (a,b,w): " << w << '\n';
		 OR1->evl(); cout << " or (w,a,y): " << y << '\n';
		XOR2->evl(); cout << "xor (y,b,w): " << w << '\n';
		MUX1->evl(); cout << "Mx(a,y,s,w): " << w << '\n';

		REG1->evl(); cout << "..........reg(w,clk,q1): " << q1 << '\n';
		REG2->evl(); cout << "......reg(w,clk,rst,q2): " << q2 << '\n';
		REG3->evl(); cout << "...reg(w,clk,rst,en,q2): " << q3 << '\n';
		CNT1->evl(); cout << ".......cnt(w,clk,ld,q4): " << q4 << '\n';
		
		ADD1->evl(); cout << "Ad(w,y,ci,co,v): " << co << "_" << v << '\n';
		CMP1->evl(); cout << "Cmp(w,y,l,e,g) : " << l << e << g << '\n';

		cout << "\n" << "Continue (0 or 1)?"; cin >> ij;

	} while (ij>0);

	delete [] a;
	delete [] b;
	delete [] y;
	delete [] w;
}
*/