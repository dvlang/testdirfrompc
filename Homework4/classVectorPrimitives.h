#define vector(a,i) char* a=new char [i+1];*(a+i)='\0';
#define line(a) char* a=new char [2];*(a+1)='\0';

int ival (char* s);
void bval (int in, char* s);
void vcopy (char* dst, char* src);

class gand {
	char *i1, *i2, *o1;
	public:
		gand (char* a, char* b, char* w); 
		~gand(); // destructor
		void evl ();
};

class gor {
	char *i1, *i2, *o1;
	public:
		gor (char* a, char* b, char* w);
		~gor(); // destructor
		void evl ();
};

class gnot {
	char *i1, *o1;
	public:
		gnot (char* a, char* w);
		~gnot(); // destructor
		void evl ();
};

class gxor {
	char *i1, *i2, *o1;
	public:
		gxor (char* a, char* b, char* w);
		~gxor(); // destructor
		void evl ();
};

class nBitMux {
	char *i1, *i2, *i3, *o1;
	public:
		nBitMux (char* a, char* b, char* sel, char* w);
		~nBitMux(); // destructor
		void evl ();
};

class nBitTri {
	char *i1, *i2, *o1;
	public:
		nBitTri (char* a, char* tri, char* w);
		~nBitTri(); // destructor
		void evl ();
};

class nBitAdder {
	char *i1, *i2, *i3, *o1, *o2;
	public:
		nBitAdder (char* a, char* b, char* ci, char* co, char* sum);
		~nBitAdder(); // destructor
		void evl ();
};

class nBitComparator {
	char *i1, *i2, *o1, *o2, *o3;
	public:
		nBitComparator (char* a, char* b, char* lt, char* eq, char* gt);
		~nBitComparator(); 
		void evl ();
};

class nBitPad {
	char *i1, *i2, *o1;
public:
	nBitPad(char* a, char* b, char* w);
	~nBitPad(); // destructor
	void evl();
};


//class signExtend {
//class rightShift {

class nBitFunctionalRegister {
	public:
		char *d, *c, *q;
		int size;
		char rtype[80]; // = "Register information"; 
	public:
		nBitFunctionalRegister (): size(0) {} 
		~nBitFunctionalRegister () {} 
		void info (char* D, char* C, char* Q, int & N, char typ[]);
		void init (char* value, char typ[]);
		virtual void evl ()=0;
};

class dRegister : public nBitFunctionalRegister {
	public:
		dRegister (char* D="0", char* C="0", char* Q="0");
		~dRegister (); 
		virtual void evl ();
};

class dRegisterE : public dRegister { //Enable
	char* e;
	public:
		dRegisterE (char* D, char* C, char* E, char* Q);
		~dRegisterE (); 
		void evl ();
};

class dRegisterRa : public dRegister { //Reset-asynch
	public:
		char* r;
	public:
		dRegisterRa (char* D="0", char* C="0", char* R="0", char* Q="0");
		~dRegisterRa (); 
		virtual void evl ();
};

class dRegisterRaE : public dRegisterRa { //Reset-asynch, Enable
	char* e;
	public:
		dRegisterRaE (char* D, char* C, char* R, char* E, char* Q);
		~dRegisterRaE (); 
		void evl ();
};

class dRegisterRs : public dRegister {
	char* r;
	public:
		dRegisterRs (char* D, char* C, char* R, char* Q);
		~dRegisterRs (); 
		void evl ();
};

class upCounter : public nBitFunctionalRegister {
	public:
		char* l;
	public:
		upCounter (char* D="0", char* C="0", char* L="0", char* Q="0");
		~upCounter (); 
		virtual void evl ();
};

class upCounterRsE : public upCounter { //Reset-asynch, Enable Count
	char* e;
	char* r;
	public:
		upCounterRsE (char* D, char* C, char* R, char* L, char* E, char* Q);
		~upCounterRsE (); 
		void evl ();
}; 

class upCounterRa : public upCounter { //Reset-asynch
	public:
		char* r;
	public:
		upCounterRa (char* D="0", char* C="0", char* R="0", char* L="0", 
			         char* Q="0");
		~upCounterRa (); 
		virtual void evl ();
};

class upCounterRaE : public upCounterRa { //Reset-asynch, Enable Count
	char* e;
	public:
		upCounterRaE (char* D, char* C, char* R, char* L, char* E, char* Q);
		~upCounterRaE (); 
		void evl ();
}; 
// controller somayeh inserted
class Controller{
	char *rst, *clk, *go, *LdIn, *LdTmp;
	char *LdOut, *free, *aeb, *sel;
	char *cnten, *ready;
	char *beqone, *beqzero;
	int Nstate, Pstate;
	public:
		Controller (char* rst, char* clk, char* go, char* LdIn, char* LdTmp, char* LdOut, char* aeb, char* sel,
		char* cnten, char* ready, char* free, char* beqone, char* beqzero);
		~Controller(); 
		void evl ();
};

class Memory{
	char *rst, *clk, *read, *write;
	char *Din, *AddrBus;
	char* Dout;
	int mem [16];

	public:
		Memory (char* rst, char* clk, char* read, char* write, char* Din,
				char* AddrBus, char* Dout);
		~Memory(); 
		void evl ();
		void initialize(char* filename);
		void blockread ();
};