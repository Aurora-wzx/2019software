#include<iostream> 
#include<string>
using namespace std;
string address[7][30]={{"省","市","区"},{"市"},{"市","区","县"},{"镇","乡","道"},{"路","街","巷","道","村","号"},{"号"}};
string foundname(string k)
{
	int i;
	string name;
	for(i=0;;i++)
	{
		if(k[i]=='!')
		{
			for(int j=i+1;;j++)
			{
				if(k[j]==',')
				{
					break;
				}
				name+=k[j];
			}
			break;
		}
	}
	return name;
}
int searchnum(char k)//判断是否为数字 
{
	int t=0,i;
	string num="0123456789";
	for(i=0;i<10;i++)
	{
		if(k==num[i])
		{
			t=1;
			break;
		}
	}
	return t;
}
int searchphone(string k,int b)//判断是否为手机号码 
{
	int i,t=1;
	for(i=b;i<=b+10;i++)
	{
		if(searchnum(k[i])==0)
		{
			t=0;
			break;
		}
	}
	return t;
}
string findphone(string k,int b)//寻找手机号 
{
	string phone;
	int i,e;
	for(i=b;i<=b+11;i++)
	{
		phone+=k[i];
	}
	return phone;
}
int searcharea(string k,int r)//判断是否为"省","市"等 
{
	int t=0,i;
	for(i=0;i<20;i++)
	{
		if(address[r][i]==k)
		{
			t=1;
			break;
		}
	}
	return t;
}
string foundarea(string s,int &b,int &r)
{
	string ad,nextad;
	int i;
	for(i=b;;)
	{
		if(s[i]=='.')
		{
			break;
		}
		else if(searchphone(s,i)==0&&searchnum(s[i])==0)
		{
			string m;
			m+=s[i];
			m+=s[i+1];
			ad+=s[i];
			ad+=s[i+1];
			if(searcharea(m,r)==1)
			{
				i+=2;
				b=i;
				r++;
				break;
			}
			i+=2;
			b=i;
		}
		else if(searchphone(s,i)==1)
		{
			i+=11;
			b=i+1;
		}
		else if(searchnum(s[i])==1||s[i]=='#')
		{
			ad+=s[i];
			i++;
			b=i+1;
		}
	}
	return ad;
}
int main()
{
	int i,k=0,b,e,r=0;
	string s,name,ad[10],phone;
	cin>>s;
	name=foundname(s);
	for(i=2;;i++)
	{
		if(searchnum(s[i])==1)
		{
			if(searchphone(s,i)==1)
			{
				phone=findphone(s,i);
				break;
			}
		}
	}
	for(i=0;;i++)
	{
		if(s[i]==',')
		{
			b=i+1;
			break;
		}
	}
	if(s[0]=='1')
	{
		for(i=0;i<5;i++)
		{
			ad[i]=foundarea(s,b,r);
		}
	}
	else if(s[0]=='2')
	{
		for(i=0;i<7;i++)
		{
			ad[i]=foundarea(s,b,r);
		}
	}
	cout<<name<<endl;
	cout<<phone<<endl;
	if(s[0]=='1')
	{
		for(i=0;i<5;i++)
		{
			cout<<ad[i]<<endl;
		}
	}
	else if(s[0]=='2')
	{
		for(i=0;i<7;i++)
		{
			cout<<ad[i]<<endl;
		}
	}
	return 0;
}
