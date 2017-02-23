#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;
//	adding some comments 
//
//
// messing around with comments again
//

//going to try to fork off here
//ok these comments, i want to keep with old in testbranch3
//

//adding some more comments.  this time for real.
// lots and lots of comments

// ending some comments





#include "classVectorPrimitives.h"
#include "classVectorFunctions.h"

int main()
{
	int ij,i;

	vector(v_InputA, 4);
	vector(v_InputB, 4);
	vector(v_InputAPAD, 8);

	vector(v_r8_REGAQ,8);
	vector(v_r8_REGTMPQ,8);
	vector(v_r8_REGOUTQ,8);
	vector(v_r4_REGBQ, 4);
	vector(v_r4_REGCNTQ, 4);
	vector(v_lpADD, 4);
	vector(v_ADDROUT, 8);
	vector(v_ASEL, 8);	
	vector(zero, 4);
	bval(0, zero);
	vector(one, 4);
	bval(1, one);

	
	line(free);
	line(clk);
	line(l);  
	line(g);
	line(co);
	line(rst);
	line(l1);  
	line(g1);
		line(ci);
	*(ci + 0) = '0';

	//new lines
	line(LdIn);
	line(LdTmp);
	line(LdTmpORLdIn)
	line(LdOut);
	line(sel);
	line(cnten);
	line(w);
	line(go);
	line(ready);
	line(aeb);
	line(beqone);
	line(beqzero);

	//new components
	//registers
	dRegisterE* r8_REGA = new dRegisterE(v_InputAPAD, clk, LdIn, v_r8_REGAQ);
	dRegisterE* r8_REGTMP = new dRegisterE(v_ASEL, clk, LdTmpORLdIn, v_r8_REGTMPQ);
	dRegisterE* r8_REGOUT = new dRegisterE(v_r8_REGTMPQ, clk, LdOut, v_r8_REGOUTQ);
	dRegisterE* r4_REGB = new dRegisterE(v_InputB, clk, LdIn, v_r4_REGBQ);
	dRegisterE* r4_REGLPCTR = new dRegisterE(v_lpADD, clk, cnten, v_r4_REGCNTQ);

	//mux
	nBitMux* MUX1 = new nBitMux(v_InputAPAD, v_ADDROUT, sel, v_ASEL);
	
	//adder
	nBitAdder* ADDAtoA = new nBitAdder(v_r8_REGAQ, v_r8_REGTMPQ, ci, co, v_ADDROUT);
	nBitAdder* ADDLPCTR = new nBitAdder(one, v_r4_REGCNTQ, ci, co, v_lpADD);

	//comparitor
	nBitComparator* CMP2 = new nBitComparator(v_r4_REGBQ, v_r4_REGCNTQ, l1, aeb, g1);
	nBitComparator* CMP3 = new nBitComparator(v_r4_REGBQ, zero, l1, beqzero, g1);
	nBitComparator* CMP4 = new nBitComparator(v_r4_REGBQ, one, l1, beqone, g1);
	//or gate
	gor* OR1 = new gor(LdIn, LdTmp, LdTmpORLdIn);

	//pad gate
	nBitPad* PAD1 = new nBitPad(v_InputA, zero, v_InputAPAD);

	//controller
	Controller* controller = new Controller(rst, clk, go, LdIn, LdTmp, LdOut, aeb, sel,
		cnten, ready, free, beqone, beqzero);
	
	// controller resetting
	*(rst + 0) = '1';
	controller->evl();
	*(rst + 0) = '0';



	i = 0;
	do {

		cout << "Enter value for Multiplicand A (4bit): "; cin >> v_InputA;
		cout << "Enter value for Multiplier B (4bit): "; cin >> v_InputB;
		cout << "A is: " << v_InputA << endl;
		cout << "B is: " << v_InputB << endl;
		*(go + 0) = '1';
		r4_REGLPCTR->init("0001", "Standard 4-bit D register");
		r4_REGB->init("0000", "Standard 4-bit D register");
		r8_REGOUT->init("00000000", "Standard 8-bit D register");
		PAD1->evl();		//get the padding out of the way

		do {
			*(clk + 0) = 'P';
			OR1->evl();
			r8_REGA->evl();
			r4_REGB->evl();
			CMP3->evl();
			CMP4->evl();
			ADDAtoA->evl();
			MUX1->evl();
			r8_REGTMP->evl();
			r8_REGOUT->evl();
			ADDLPCTR->evl();
			r4_REGLPCTR->evl();
			CMP2->evl();
			controller->evl();
			i++;
			cout << "CLK " << *(clk + 0) << " RDY " << *(ready + 0) << endl;
		} while (*(free + 0) == '0');
		*(go + 0) = '0';

		cout << "W= " << v_r8_REGOUTQ << endl;
		cout << "\n" << "Continue (0 or 1)?"; cin >> ij;

	} while (ij >0);
}
