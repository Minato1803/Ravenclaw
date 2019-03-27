#include "Function.h"

ifstream Input;
ofstream Output;

struct VatTu
{
	char TENVT[50];
	char DVT[50];
	int SLTon;
};

// tao cay vattu
struct nodeVatTu
{
	char MAVT[10];
	VatTu noiDungVT; 
	struct nodeVatTu *left;
	struct nodeVatTu *right;
};
typedef struct nodeVatTu *NODEPTR; 
//NODEPTR tree = NULL; 

//khoitaocay
void KhoiTaoCay(NODEPTR &root)
{
	root = NULL;
}

void ThemNodeCay(NODEPTR &p, char *key, VatTu a)
{
	if(p == NULL)
	{
		p = new nodeVatTu;
		strcpy(p -> MAVT, key);
 		strcpy(p->noiDungVT.TENVT, a.TENVT);
 		strcpy(p -> noiDungVT.DVT, a.DVT);
 		p -> noiDungVT.SLTon = a.SLTon;
		p ->left = NULL; p->right = NULL;
	}
	else
	{
		if(strcmp(key, p->MAVT) < 0)
		{
			ThemNodeCay(p->left, key, a);
		}
		else if(strcmp(key, p->MAVT) > 0)
		{
			ThemNodeCay(p->right, key, a);
		}
		else
		{
			//LoiNodeTrung();
		}
	}
}

void NhapVT(NODEPTR &p)
{
	char VTcode[10];
	VatTu info;
	do
	{
		cout << "Nhap ma vat tu: ";
		cin >> VTcode;
		cin.ignore();
//		cout << strcmp(VTcode, zero) << endl;
		if(strcmp(VTcode, "0") != 0)
		{
			cout << "Nhap ten vat tu: ";
			cin.getline(info.TENVT, 50);
			cout << "Nhap don vi tinh: ";
			cin >> info.DVT;
			cout << "Nhap so luong ton: ";
			cin >> info.SLTon;
			ThemNodeCay(p, VTcode, info);
		}
	}
	while(strcmp(VTcode, "0") != 0);
}

void Inorder(NODEPTR p)
{
	if(p != NULL)
	{
		Inorder(p->left);
		cout << "Ma Vat tu: " << p->MAVT << endl;
		cout << "Ten Vat Tu: " << p->noiDungVT.TENVT << endl;
		cout << "Don Vi Tinh: "<< p->noiDungVT.DVT << endl;
		cout << "So Luong Ton: " << p->noiDungVT.SLTon << endl;
		cout << "=========================================================\n";
		Inorder(p->right);
	}
}

void SaveInorder(NODEPTR p, ofstream& Output)
{
	if(p != NULL)
	{
		SaveInorder(p->left, Output);
		Output << p->MAVT << endl;
		Output << p->noiDungVT.TENVT << endl;
		Output << p->noiDungVT.DVT << endl;
		Output << p->noiDungVT.SLTon << endl;
		SaveInorder(p->right, Output);
	}
}

void SaveFile(NODEPTR p, ofstream& Output)
{
	Output.open("DanhSachVT.txt");
	SaveInorder(p,Output);
	Output.close();
}

void LoadFile(NODEPTR &p, ifstream& Input)
{
	Input.open("DanhSachVT.txt");
	char VTcode[10];
	VatTu info;
	while(!Input.eof())
	{
		Input >> VTcode;
		Input.ignore();  
		Input.getline(info.TENVT, 50);
		Input >> info.DVT;
		Input >> info.SLTon;
		ThemNodeCay(p, VTcode, info);
	}
	Input.close();
}


void XuatVT(NODEPTR p)
{
	cout << "\t\t\tXUAT\n";
	cout << "=========================================================\n"; 
	Inorder(p);
}


int main()
{
	NODEPTR tree = NULL;
	KhoiTaoCay(tree);
	LoadFile(tree, Input);
	//NhapVT(tree);
	//SaveFile(tree, Output);
	XuatVT(tree);
	return 0;	
}

