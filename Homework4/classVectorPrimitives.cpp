#include "stdafx.h"
#include "classVectorPrimitives.h"
#include <iostream>
#include <string.h>
#include <math.h>
#include <stdio.h>



using namespace std;

int ival (char* s) {
	int val=0;
	int i=0; int j=0;
	int LEN=strlen(s)-1;
	for (i=LEN; i>=0; i--) {
		if (*(s+i)=='1') val= val+(int)pow(2.0,j);
		j++;
	} 
	return int(val);
}

void bval (const int in, char* s) {
	int jn, kn;
	int i=0;
	kn=in;
	int LEN=strlen(s)-1;
	for (i=LEN; i>=0; i--) {
		jn=kn/2;
		if ((jn*2)==kn) *(s+i)='0';
		else *(s+i)='1';
		kn=jn;
	} 
}

void vcopy (char* dst, char* src) {
	int i=0;
	int LEN=strlen(src);
	for (i=LEN; i>=0; i--) {
		*(dst+i) = *(src+i);
	}
}

gand::gand(char* a, char* b, char* w) {
	i1= a; i2= b; o1= w;
	int i;
	int LEN=strlen(o1);
	for (i=0;i<LEN;i++){
		*(o1+i)='X';
	}
}
gand::~gand() {delete i1; delete i2; delete o1;}
void gand::evl () {
	int i=0;
	do {
		if ((*(i1+i)=='0')||(*(i2+i)=='0')) *(o1+i)='0';
		else if ((*(i1+i)=='1')&&(*(i2+i)=='1')) *(o1+i)='1';
		else *(o1+i)='X';
		i++;
	} while (*(i1+i) != '\0');
}

gor::gor(char* a, char* b, char* w) {
	i1= a; i2= b; o1= w;
	int i=0;
	int LEN=strlen(o1);
	for (i=0;i<LEN;i++){
		*(o1+i)='X';
	}
}
gor::~gor() {delete i1; delete i2; delete o1;}
void gor::evl () {
	int i=0;
	do {
		if ((*(i1+i)=='1')||(*(i2+i)=='1')) *(o1+i)='1';
		else if ((*(i1+i)=='0')&&(*(i2+i)=='0')) *(o1+i)='0';
		else *(o1+i)='X';
		i++;
	} while (*(i1+i) != '\0');
}

gnot::gnot(char* a, char* w) {
	i1= a; o1= w;
	int i;
	int LEN=strlen(o1);
	for (i=0;i<LEN;i++){
		*(o1+i)='X';
	}
}
gnot::~gnot() {delete i1; delete o1;}
void gnot::evl () {
	int i=0;
	do {
		if (*(i1+i)=='0') *(o1+i)='1';
		else if (*(i1+i)=='1') *(o1+i)='0';
		else *(o1+i)='X';
		i++;
	} while (*(i1+i) != '\0');
}

gxor::gxor(char* a, char* b, char* w) {
	i1= a; i2= b; o1= w;
	int i;
	int LEN=strlen(o1);
	for (i=0;i<LEN;i++){
		*(o1+i)='X';
	}
}
gxor::~gxor() {delete i1; delete i2; delete o1;}
void gxor::evl () {
	int i=0;
	do {
		if ((*(i1+i)=='X')||(*(i2+i)=='X')||(*(i1+i)=='Z')||(*(i1+i)=='Z')) *(o1+i)='X';
		else if (*(i1+i)==*(i2+i)) *(o1+i)='0';
		else *(o1+i)='1';
		i++;
	} while (*(i1+i) != '\0');
}

nBitMux::nBitMux (char* a, char* b, char* sel, char* w) {
	i1= a; i2= b; i3= sel; o1= w;
	int i;
	int LEN=strlen(o1);
	for (i=0;i<LEN;i++){
		*(o1+i)='X';
	}
}
nBitMux::~nBitMux() {delete i1; delete i2; delete i3; delete o1;}
void nBitMux::evl () {
	int i=0;
	do {
		if (*(i3)=='0') *(o1+i) = *(i1+i);
		else *(o1+i) = *(i2+i);
		i++;
	} while (*(i1+i) != '\0');
}

nBitTri::nBitTri (char* a, char* tri, char* w) {
	i1= a; i2= tri; o1= w;
	int i;
	int LEN=strlen(o1);
	for (i=0;i<LEN;i++){
		*(o1+i)='X';
	}
}
nBitTri::~nBitTri() {delete i1; delete i2; delete o1;}
void nBitTri::evl () {
	int i=0;
	do {
		if (*(i2)=='1') *(o1+i) = *(i1+i);
		else *(o1+i) = 'Z';
		i++;
	} while (*(i1+i) != '\0');
}

nBitPad::nBitPad(char *a, char *b, char *w){
	i1 = a; i2 = b; o1 = w;
	int i;
	int LEN = strlen(o1);
	for (i = 0; i<LEN; i++) {
		*(o1 + i) = 'X';
	}
}

nBitPad::~nBitPad() { delete i1; delete i2; delete o1; }
void nBitPad::evl() {
	int i,j = 0;

		int LENa = strlen(i1);
		int LENb = strlen(i2);

		for (i = 0; i<LENb; i++) {
			*(o1 + i) = *(i2 + i);
		}

		for (j = 0; j<LENa; j++) {
			*(o1 + i) = *(i1 + j);
			i++;
		}


}



nBitAdder::nBitAdder (char* a, char* b, char* ci, char* co, char* sum) {
	i1= a; i2= b; i3= ci;
	o1= sum; o2= co;
	int i;
	int LEN=strlen(o1);
	for (i=0;i<LEN;i++){
		*(o1+i)='X';
	}
	*(o2+0)='X';
}
nBitAdder::~nBitAdder() {delete i1; delete i2; delete i3; delete o1; delete o2;}
void nBitAdder::evl () {
	int isum;
	char* csum=new char [strlen(o1)+1]; // could use vector
	*(csum+strlen(o1)+1)='\0';

	isum = ival(i1) + ival(i2) + ival(i3);
	bval(isum, csum);
	*(o2+0) = *(csum+0);
	int i=1;
	do {
		*(o1+i-1)=*(csum+i);
		i++;
	} while (*(o1+i-1) != '\0');
}

nBitComparator::nBitComparator (char* a, char* b, char* lt, char* eq, char* gt) {
	i1= a; i2= b; 
	o1= lt; o2= eq; o3= gt;
	*(o1+0)='X';
	*(o2+0)='X';
	*(o3+0)='X';
}
nBitComparator::~nBitComparator() {delete i1; delete i2; delete o1; delete o2; delete o3;}
void nBitComparator::evl () {
	int ai, bi;
	ai= ival(i1);
	bi= ival(i2);
	if (ai<bi) {
		*(o1+0)='1'; *(o2+0)='0'; *(o3+0)='0';
	}
	else if (ai==bi) {
		*(o1+0)='0'; *(o2+0)='1'; *(o3+0)='0';
	}
	else {
		*(o1+0)='0'; *(o2+0)='0'; *(o3+0)='1';
	}
}

void nBitFunctionalRegister::info(char* D, char* C, char* Q, int& N, 
								  char typ[]){
	vcopy(D, this->d);
	vcopy(C, this->c);
	vcopy(Q, this->q);
	N= this->size;
	vcopy(typ, this->rtype);
}
void nBitFunctionalRegister::init(char* val, char typ[]){
	vcopy(this->q, val); 
	vcopy(this->rtype, typ); 
}

dRegister::dRegister (char* di, char* clk, char* qo) {
	int i=0;
	this->d = di; 
	this->c = clk;
	this->q = qo;
	this->size = strlen(q);
	int LEN=strlen(this->q);
	for (i=0;i<LEN;i++){
		*(q+i)='X';
	}
}
dRegister::~dRegister() {delete d; delete c; delete q;}
void dRegister::evl(){
	if (*(c+0)=='P') vcopy(q, d); 
}

dRegisterE::dRegisterE (char* di, char* clk, char* en, char* qo)
                       :dRegister (di,clk,qo) {
	this->e = en;
}
dRegisterE::~dRegisterE() {delete d; delete c; delete e; delete q;}
void dRegisterE::evl(){
	if (*(e+0)=='1') dRegister::evl();
}
	
dRegisterRa::dRegisterRa (char* di, char* clk, char* rst, char* qo)
                         :dRegister (di,clk,qo) {
	this->r = rst;
}
dRegisterRa::~dRegisterRa() {delete d; delete c; delete r; delete q;}
void dRegisterRa::evl(){
	int i;
	int LEN=strlen(this->q);
	if (*(r+0)=='1') {
		for (i=0;i<LEN;i++){
		*(q+i)='0';
		}
	}
	else dRegister::evl();
}
	
dRegisterRaE::dRegisterRaE (char* di, char* clk, char* rst, char* en, 
                            char* qo):dRegisterRa (di,clk,rst,qo) {
	this->e = en;
}
dRegisterRaE::~dRegisterRaE() {delete d; delete c; delete r; 
                               delete e; delete q;}
void dRegisterRaE::evl(){
	int i;
	int LEN=strlen(this->q);
	if (*(r+0)=='1') {
		for (i=0;i<LEN;i++){
		*(q+i)='0';
		}
	}
	else if (*(e+0)=='1') dRegister::evl();
}
	
dRegisterRs::dRegisterRs (char* di, char* clk, char* rst, char* qo)
	                     :dRegister (di,clk,qo) {
	this->r = rst;
}
dRegisterRs::~dRegisterRs() {delete d; delete c; delete r; delete q;}
void dRegisterRs::evl(){
	int i;
	int LEN=strlen(this->q);
	if ((*(r+0)=='1') && (*(c+0)=='P')) {
		for (i=0;i<LEN;i++){
		*(q+i)='0';
		}
	}
	else dRegister::evl();
}
	
upCounter::upCounter (char* di, char* clk, char* ld, char* qo) { 
	int i=0;
	this->d = di; 
	this->c = clk;
	this->l = ld;
	this->q = qo;
	this->size = strlen(di);
	int LEN=strlen(this->q);
	for (i=0;i<LEN;i++){
		*(q+i)='X';
	}
}
upCounter::~upCounter() {delete d; delete c; delete l; delete q;}
void upCounter::evl(){
	int icnt;
	int bits=strlen(q);
	char* bcnt=new char [bits+1]; *(bcnt+bits)='\0';

	if (*(c+0)=='P') {
		if (*(l+0)=='1') vcopy(q, d);
		else {
			icnt=ival(q)+1;
			bval(icnt, bcnt);
			vcopy(q,bcnt);
		}
	}
}

upCounterRa::upCounterRa (char* di, char* clk, char* rst, char* ld, 
	                      char* qo):upCounter(di,clk,ld,qo) { 
	this->r = rst;
}
upCounterRa::~upCounterRa() {delete d; delete c; delete r; delete l; 
                             delete q;}
void upCounterRa::evl(){
	int i;
	int LEN=strlen(this->q);
	if (*(r+0)=='1') {
		for (i=0;i<LEN;i++){
		*(q+i)='0';
		}
	}
	else upCounter::evl();
}

/// somayeh inserted
upCounterRsE::upCounterRsE(char* di, char* clk, char* rst, char* ld, 
	                       char*en, char* qo):upCounter(di,clk,ld,qo) { 
	this->r = rst;
	this->e = en;
}
upCounterRsE::~upCounterRsE() {delete d; delete c; delete r; delete l; 
                               delete e; delete q;}
void upCounterRsE::evl(){
	int i;
	int LEN=strlen(this->q);
	if (*(c+0) == 'P'){
		if (*(r+0)=='1') {
			for (i=0;i<LEN;i++){
				*(q+i)='0';
			} 
		}
		else if (*(e+0)=='1')upCounter::evl();
	}
}

upCounterRaE::upCounterRaE (char* di, char* clk, char* rst, char* ld, 
	                        char*en,char*qo):upCounterRa(di,clk,rst,ld,qo) { 
	this->e = en;
}
upCounterRaE::~upCounterRaE() {delete d; delete c; delete r; delete l; 
                               delete e; delete q;}
void upCounterRaE::evl(){
	int i;
	int LEN=strlen(this->q);
	if (*(r+0)=='1') {
		for (i=0;i<LEN;i++){
		*(q+i)='0';
		}
	}
	else if (*(e+0)=='1')upCounter::evl();
}
//
Controller::Controller (char* rst, char* clk, char* go, char* LdIn, char* LdTmp, char* LdOut, char* aeb, char* sel, 
	char* cnten, char* ready, char* free, char* beqone, char* beqzero){
	this->rst = rst; this->clk = clk; this->go = go; this->LdIn = LdIn; this->LdTmp = LdTmp; this->LdOut = LdOut;
	this->free = free; this->aeb = aeb; this->sel = sel; this->cnten = cnten; this->ready = ready; this->beqone = beqone; this->beqzero=beqzero;

	*(free+0) = 'X';
	*(LdIn+0) = 'X';
	*(LdTmp+0) = 'X';
	*(LdOut+0) = 'X';
	*(sel+0) = 'X';
	*(cnten+0) = 'X';
	*(ready+0) = 'X';

	Nstate= 0;
	Pstate= 0;
	}
Controller::~Controller() {delete rst; delete clk; delete go; delete LdIn; delete LdTmp; delete LdOut; 
delete free; delete aeb; delete sel; delete cnten; delete ready; delete beqone; delete beqzero;
}

void Controller::evl () {

	*(free+0)='1';
	*(LdIn+0)='0';
	*(LdTmp+0)='0';
	*(LdOut+0)='0';
	*(sel+0)='1';
	*(cnten+0)='0';
	*(ready+0)='0';
		
	switch (Pstate){
		case 0: //wait
			if (*(rst+0) == '1') Nstate = 0;
			else if(*(go+0) == '1') Nstate = 6;
			else Nstate = 0; break;
		case 6://load

			if (*(rst+0) == '1') Nstate = 0;

			else Nstate = 1; break;
		case 1://ckval

			if (*(rst + 0) == '1') Nstate = 0;
			else if (*(beqone + 0) == '1') Nstate = 4;
			else if (*(beqzero + 0) == '1') Nstate = 5;
			else Nstate = 2; break;
		case 2:// calc
			if (*(rst+0) == '1') Nstate = 0;
			else Nstate = 3; break;
		case 3: //store

			if (*(rst+0) == '1') Nstate = 0;
			else if (*(aeb + 0) == '1') Nstate = 4;
			else Nstate = 2; break;
		case 4: // output;
			if (*(rst+0) == '1') Nstate = 0;
			else Nstate = 5; break;
		case 5: // pulse output
			if (*(rst+0) == '1') Nstate = 0;
			else Nstate = 0;break;
	}
	switch (Pstate){
		case 0: //wait

			if (*(rst+0) == '1') *(free+0)='1';
			else if(*(go+0) == '1') *(free+0)='0';
			else *(free+0)='1';
			break;
		case 1://ckval

			if (*(rst+0) == '1') *(free+0)='1';
			else {
	
				*(free+0) = '0';
			}
			break;
		case 2:// calc

			if (*(rst+0) == '1') *(free+0)='1';
			else {

				*(cnten+0) = '1';

				*(free+0) = '0';
			}
			break;
		case 3: //store

			if (*(rst+0) == '1') *(free+0)='1';
			else {
				*(LdTmp+0) = '1';
				*(free+0) = '0';
			}
			break;
		case 4: // out

			if (*(rst+0) == '1') *(free+0)='1';
			else {

				*(LdOut+0) = '1';
				*(free+0) = '0';
			}

			break;
		case 5: // pulse

			if (*(rst+0) == '1') *(free+0)='1';
			
			else {
				*(ready + 0) = '1';
				*(free + 0) = '1';
			}
			break;
		case 6://load

			if (*(rst + 0) == '1') *(free + 0) = '1';
			else {
				*(LdIn + 0) = '1';
				*(sel + 0) = '0';
				*(free + 0) = '0';
			}
			break;
	}
	
	if (*(rst+0)=='1') Pstate= 0;
	else if (*(clk+0)=='P') Pstate = Nstate;	
}
