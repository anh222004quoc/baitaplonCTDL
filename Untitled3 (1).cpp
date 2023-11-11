#include<stdio.h>
#include<iostream>
#include<string.h>
#include<iomanip>
#include<stdlib.h>
#include<limits.h>
#include <cctype>
using namespace std;
class NhanVien {
	public:
		string MaNv;
		string HoTenNv;
		string GioiTinh;
		string NamSinh;
		string NoiSinh;
		string DiaChi;
		long long int cccd;
		string ChucVu;
		long long int LuongCoBan, Phucap, ThucLinh;
		NhanVien* next;
};
class QuanLi{
	private: 
		NhanVien* head;
		NhanVien* tail;
	public: 
	    QuanLi()
	    {
	    	head = NULL;
	    	tail = NULL;
		}
	void nhapnhanvien()
	{
		int n;
		int i=1;
		cout<<"Nhap so luong nhan vien hien tai: ";
		cin>>n;
		while(i<=n)
		{
			cout<<"*-*-*-**-*-*-**-*-*-**-*-*-**-*-*-**-*-*-**-*-*-*\n";
			NhanVien* newNhanVien = new NhanVien();
			cout<<"Nhap thong tin: "<<endl;
			cout<<"Ma NV: ";
			cin.ignore(30000,'\n');
			getline(cin, newNhanVien->MaNv);
			cout<<"Ho Ten Nv: ";
			getline(cin, newNhanVien->HoTenNv);
			cout<<"Gioi Tinh: ";
			getline(cin, newNhanVien->GioiTinh);
			cout<<"Nam Sinh: ";
			getline(cin, newNhanVien->NamSinh);
			cout<<"Noi Sinh: ";
			getline(cin, newNhanVien->NoiSinh);
			cout<<"Dia Chi: ";
			getline(cin, newNhanVien->DiaChi);
			cout<<"CCCD: "; 
			cin>>newNhanVien->cccd;		
			cin.ignore(30000,'\n');	
			cout<<"Chuc Vu: "; 
			getline(cin, newNhanVien->ChucVu);
			cout<<"Luong Co Ban: "; 
			cin>>newNhanVien->LuongCoBan;
			cout<<"Phu Cap: "; 
			cin>>newNhanVien->Phucap;
			newNhanVien->ThucLinh = newNhanVien->LuongCoBan + newNhanVien->Phucap;
			if(head == NULL)
			{
				head = newNhanVien;
				tail  = newNhanVien;
			}
			else
			{
				tail->next = newNhanVien;
				tail = newNhanVien;
			}
			i++;	 
		}
	}
	void insert	()
	{
		    cout<<"Nhap thong tin nhan vien can them: \n";
					NhanVien* newNhanVien = new NhanVien();
			cout<<"Ma NV: ";
			cin.ignore(30000,'\n');
			getline(cin, newNhanVien->MaNv);
			cout<<"Ho Ten Nv: ";
			getline(cin, newNhanVien->HoTenNv);
			cout<<"Gioi Tinh: ";
			getline(cin, newNhanVien->GioiTinh);
			cout<<"Nam Sinh: ";
			getline(cin, newNhanVien->NamSinh);
			cout<<"Noi Sinh: ";
			getline(cin, newNhanVien->NoiSinh);
			cout<<"Dia Chi: ";
			getline(cin, newNhanVien->DiaChi);
			cout<<"CCCD: "; 
			cin>>newNhanVien->cccd;		
			cin.ignore(30000,'\n');	
			cout<<"Chuc Vu: "; 
			getline(cin, newNhanVien->ChucVu);
			cout<<"Luong Co Ban: "; 
			cin>>newNhanVien->LuongCoBan;
			cout<<"Phu Cap: "; 
			cin>>newNhanVien->Phucap;
			newNhanVien->ThucLinh = newNhanVien->LuongCoBan + newNhanVien->Phucap;
		int select;
		cout<<"1. Chen dau.\n2. Chen giua.\n3. Chen cuoi."<<endl;
		cout<<"Moi ban chon: ";
		cin>>select;
		if(select == 1)
		{
			newNhanVien->next = head;
			head = newNhanVien;
		}
		else if(select == 2)
		{   
			if(head == tail)
			{
				cout<<"Khong the chen giua vi <= 2 Nhan Vien.\n";
				return;
			}
			int localtion;
			NhanVien *run = head;
			cout<<"Nhap vi tri muon them(localtion): ";
			cin>>localtion;
			for(int i =1; i<localtion-1; i++) // 1 2 
			{
				run= run->next;
			}
			newNhanVien->next = run->next;
			run->next = newNhanVien;
		}
		else if(select == 3)
		{
			tail->next= newNhanVien;
			tail = newNhanVien;
		}
	}
	void deleteNV()
	{
		NhanVien* run = head;
		NhanVien* localdelete = head;
		string dlte;
		cout<<"Nhap MaNV muon xoa: ";
		cin>>dlte;
			if(head->MaNv == dlte)
			head=head->next;
			else
			{
				while(localdelete != NULL)
				{
					localdelete = run->next; 
					if(localdelete->MaNv == dlte) // 1 4 5 6
					{
						run->next = localdelete->next;
						break;
					}
					else{
						run=run->next;
					}
				}
			}
	}
	void Search()
	{
		NhanVien* count = head;
		string search;
		cout<<"Nhap ma NV can tim: ";
		cin>>search;
		while(count != NULL)
		{
			if(count->MaNv == search)
			{
				cout<<"MaNV|HovaTen|GioiTinh|NamSinh|NoiSinh|DiaChi|CCCD|ChucVu|LuongCoBan|PhuCap|ThucLinh\n";
				cout<<count->MaNv<<"|"<<count->HoTenNv<<"|"<<count->GioiTinh<<"|"<<count->NamSinh<<"|"<<count->NoiSinh;
			    cout<<"|"<<count->DiaChi<<"|"<<count->cccd<<"|"<<count->ChucVu<<"|"<<count->LuongCoBan<<"|"<<count->Phucap<<"|"<<count->ThucLinh<<"\n";
			    break;
			}
			else{
				count= count->next;
			}
		}
		
	}
	void Luong10m()
	{
			NhanVien* run = head; 
			cout<<"Nhan vien co luong tren 10m : \n";
			cout<<"MaNV|HovaTen|GioiTinh|NamSinh|NoiSinh|DiaChi|CCCD|ChucVu|LuongCoBan|PhuCap|ThucLinh\n";
			while(run != NULL)
			{
				if(run->ThucLinh >= 10000000)
				{
						cout<<run->MaNv<<"|"<<run->HoTenNv<<"|"<<run->GioiTinh<<"|"<<run->NamSinh<<"|"<<run->NoiSinh;
			    		cout<<"|"<<run->DiaChi<<"|"<<run->cccd<<"|"<<run->ChucVu<<"|"<<run->LuongCoBan<<"|"<<run->Phucap<<"|"<<run->ThucLinh<<"\n";
				}
				run =run->next;
			}
			
	}
	void sort()
	{
		NhanVien* count = head;
		long long int *luong = new long long int[1000];
		int i =1;
        long long int max1= 0;
        NhanVien* run = head;
		luong[0]=LLONG_MAX;
		while(count!= NULL)
		{
            run = head;
			max1= 0; 
			while(run!= NULL)
			{
				if(run->ThucLinh >= max1 && run->ThucLinh < luong[i-1] )	
				{
				  max1 = run->ThucLinh;
				}
				run = run->next;	// 1 2 3 4		
			}
			luong[i] = max1; 
			i++;
			count = count->next;
		}
		count=head;
		cout<<"Sap xep theo luong:\n";
		cout<<"MaNV|HovaTen|GioiTinh|NamSinh|NoiSinh|DiaChi|CCCD|ChucVu|LuongCoBan|PhuCap|ThucLinh\n";
		for(int j = 1; j< i; j++)
		{
            count=head;
			while(count != NULL)
			{
				if(count->ThucLinh == luong[j])
				{
					cout<<count->MaNv<<"|"<<count->HoTenNv<<"|"<<count->GioiTinh<<"|"<<count->NamSinh<<"|"<<count->NoiSinh;
					cout<<"|"<<count->DiaChi<<"|"<<count->cccd<<"|"<<count->ChucVu<<"|"<<count->LuongCoBan<<"|"<<count->Phucap<<"|"<<count->ThucLinh<<"\n";
				}
				count=count->next;
			}
		}	
	}
    void namnu()
    {
        NhanVien* run = head;
        cout<<"Nam or Nu\n";
        string select; 
        cout<<"Moi ban chon: ";
        cin>>select;
        cout<<"Thong tin nhan vien "<<select<<" cua ban: \n";
        while(run != NULL)
        {
            if(strcasecmp(run->GioiTinh.c_str(), select.c_str()) == 0)
            {
                cout<<run->MaNv<<"|"<<run->HoTenNv<<"|"<<run->GioiTinh<<"|"<<run->NamSinh<<"|"<<run->NoiSinh;
                cout<<"|"<<run->DiaChi<<"|"<<run->cccd<<"|"<<run->ChucVu<<"|"<<run->LuongCoBan<<"|"<<run->Phucap<<"|"<<run->ThucLinh<<"\n";
            }
            run=run->next;
        }

    }
	void show()
	{
		NhanVien* count = new NhanVien();
		count = head;
		cout<<"Thong tin nhan vien cua ban: \n"; 
		cout<<"MaNV|HovaTen|GioiTinh|NamSinh|NoiSinh|DiaChi|CCCD|ChucVu|LuongCoBan|PhuCap|ThucLinh\n";
		while(count != NULL)
		{
			cout<<count->MaNv<<"|"<<count->HoTenNv<<"|"<<count->GioiTinh<<"|"<<count->NamSinh<<"|"<<count->NoiSinh;
			cout<<"|"<<count->DiaChi<<"|"<<count->cccd<<"|"<<count->ChucVu<<"|"<<count->LuongCoBan<<"|"<<count->Phucap<<"|"<<count->ThucLinh<<"\n";
			count = count->next;
		}
	}
};
int main(){
	QuanLi *BaiTapLon = new QuanLi();
	while(1){
		cout<<"------------Menu--------------"<<endl;
		cout<<"\t 0-Nhap so luong nhan vien hien tai:"<<endl;
		cout<<"\t 1-Insert(chen)"<<endl;
		cout<<"\t 2-Delete "<<endl;
		cout<<"\t 3-Search "<<endl;
        cout<<"\t 4-Luong tren 10m"<<endl;
        cout<<"\t 5-Sap xep theo luong"<<endl;
        cout<<"\t 6-Phan theo gioi tinh"<<endl;
        cout<<"\t 7-Show"<<endl;
        cout<<"\t 8-Stop"<<endl;
		cout<<"\tNhap lua chon : ";int btl;cin>>btl;
		if(btl==0)
		BaiTapLon->nhapnhanvien();
		else if(btl==1)
		BaiTapLon->insert();
		else if(btl==2)
		BaiTapLon->deleteNV();
		else if(btl==3)
		BaiTapLon->Search();
		else if(btl == 4)
		BaiTapLon->Luong10m();
		else if(btl==5)
		BaiTapLon->sort();
		else if(btl==6)
		BaiTapLon->namnu();
		else if(btl==7)
		BaiTapLon->show();
		else if(btl==8)
		break;
		
		cout<<" Nhan bat ki nut nao de tiep tuc \n";
		system("pause");
	}
}
