/* roll no c137223 
name : Himanshu garg */
/* epsilon is represented by # */
#include <iostream>
#include <vector>
#include <fstream>
#include <cstring>
#include <string>
using namespace std;

vector<char> d1,d3,r,r1,ter;
vector< vector <char> > d2,d4;
char c;
string s;
vector< vector < vector <char> > > l,l1;


void findfirst(vector<char> r1, vector<vector< vector <char > > > l1,int i,vector< char >first[])
 {
 	if(first[i].size()==0)
  {
   	for(int j=0;j<l1[i].size();j++)
    {
   	  if(l1[i][j][0]>=65 && l1[i][j][0]<=90)
     	{
     		int k;
     		for( k=0;k<r1.size();k++)
     		if(r1[k]==l1[i][j][0])
     		break;
 		       findfirst(r1,l1,k,first);
 		       first[i]=first[k];
 	    } 
      else
 	    {
 	      first[i].push_back(l1[i][j][0]);
    	} 
   	}
  } 
}
 
void findfollow(vector<char> r1, vector<vector< vector <char > > > l1,int i,vector< char >follow[],vector< char >first[])
{
  int f1=0;
 	for(int j=0;j<r1.size();j++)
 	{
 		for(int k=0;k<l1[j].size();k++)
 		{
 			for(int k1=0;k1<l1[j][k].size();k1++)
 			{	
 				if(l1[j][k][k1]==r1[i])
 				{
 					if(k1==(l1[j][k].size()-1))
 					{
						  if(r1[j]!=l1[j][k][k1])
            {
						    if(follow[j].size()==0 )
						    findfollow(r1,l1,j,follow,first);
							  for(int m1=0;m1<follow[j].size();m1++)
                {
   								follow[i].push_back(follow[j][m1]);
   								f1=1;
							  }
							
						}
 					}
 				
 					else
 					{
 						if(l1[j][k][k1+1]>=65 && l1[j][k][k1+1]<=90 )
 						{
 							int k2;
 							for( k2=0;k2<r1.size();k2++)
 							if(r1[k2]==l1[j][k][k1+1])
 							break;
 						
 							for(int m1=0;m1<first[k2].size();m1++)
 							{
 								if(first[k2][m1]!='#')
 									follow[i].push_back(first[k2][m1]);
 								else
 								     {
 								if(r1[j]!=l1[j][k][k1]){
 						       if(follow[j].size()==0 )
 						       findfollow(r1,l1,j,follow,first);
 						     	for(int m1=0;m1<follow[j].size();m1++)
 						     	follow[i].push_back(follow[j][m1]);}
 								     f1=1;	
 								     }
 							}
 						
 						}
 						else 
 						{
 							follow[i].push_back(l1[j][k][k1+1]);
 							f1=1;
 						}
 					}
 					
 					break;
 				}
 				if(f1==1)
 				break;
 			}
 				if(f1==1)
 				break;
 		}
 			if(f1==1)
 				break;
 	}
 	
}

int main()
{
  
   ifstream fin;
   fin.open("cfg.txt");
   while(!fin.eof())
   {
     fin>>c;
     	if(c!='.')
     	  r.push_back(c);
     	fin>>c>>c;
     	while(c!='.'){
       	fin>>c;
       	while(c!='/' && c!='.')
       	{
       		d1.push_back(c);
       		fin>>c;
       	}
    	   d2.push_back(d1);
    	   d1.clear();
  	   }
     	l.push_back(d2);
     	d2.clear();
   }
   fin.close();
   
   
   cout<<"production  rules\n\n";
   for(int i=0;i<r.size();i++)
   {
     cout<<r[i]<<" -> ";
     for(int j=0;j<l[i].size();j++)
     {
     	    for(int k=0;k<l[i][j].size();k++)
       	    cout<<l[i][j][k];
       	    cout<<" /";
     }                  
     cout<<"\b\t\n";
  } 
  
  for(int i=0;i<r.size();i++)
  {
  	int lr=0;
  	  for(int j=0;j<l[i].size();j++)
  	  {
  	  	if(l[i][j][0]==r[i])
  	  	{
  	  		lr=1;
  	  		break;
  	  		
  	  	}
  	  }
  	  
  	  if(lr==1){
  	  	r1.push_back(r[i]);
  	  	r1.push_back((int)r[i]+10);
  	  	for(int j=0;j<l[i].size();j++)
  	  	 {
  	  	 	if(l[i][j][0]==r[i])
  	  	 	{
  	  	 		for(int k=1;k<l[i][j].size();k++)
  	  	 		d1.push_back(l[i][j][k]);
  	  	 		d1.push_back((int)r[i]+10);
  	          	d4.push_back(d1);
  	          	d1.clear();
  	  	 	}
  	  	 	else
  	  	 	{
  	  	 		for(int k=0;k<l[i][j].size();k++)
  	  	 		d1.push_back(l[i][j][k]);
  	  	 		d1.push_back((int)r[i]+10);
  	          	d2.push_back(d1);
  	          	d1.clear();
  	  	 	}
  	  	 }
  	  	 l1.push_back(d2);
  	  	 d2.clear();
  	  	 d1.push_back('#');
  	  	 d4.push_back(d1);
  	  	 l1.push_back(d4);
  	  	 d1.clear();
  	  	 d4.clear();
  	  }
  	  	else
  	  	{
  	  		r1.push_back(r[i]);
  	  	 	l1.push_back(l[i]);
  	  		
  	  	}
   }
  	     
   cout<<"\n\nproduction  rules after removing left recursion\n\n";
  for(int i=0;i<r1.size();i++){
   cout<<r1[i]<<" -> ";
   for(int j=0;j<l1[i].size();j++)
   {
   	    for(int k=0;k<l1[i][j].size();k++)
        {
     	    cout<<l1[i][j][k];
     	    int m=0;
     	   if(l1[i][j][k]<65 || l1[i][j][k]>90){
     	   
     	    for(int k1=0;k1<ter.size();k1++)
     	    if(l1[i][j][k]==ter[k1])
     	    {
     	    	m=1;break;
     	    }
     	    if(m==0)
     	    ter.push_back(l1[i][j][k]);
          }
   	    
		    }
   	    cout<<" /";
   }                  
   cout<<"\b\t\n";
  } 
  
  
  
  cout<<"\nterminals\n";
  for(int i=0;i<ter.size();i++)
  cout<<ter[i]<<" ";
  cout<<"\n";
  vector<char>  follow[r1.size()],first[r1.size()];
 
 cout<<"\n\nfinding first\n\n";
  
  for(int i=0;i<r1.size();i++)
  {
  	if(first[i].size()==0){
  findfirst(r1,l1,i,first);}
  }

for(int i=0;i<r1.size();i++)
  {
  cout<<"first ("<<r1[i]<<")"<<" = { ";
  for(int j=0;j<first[i].size();j++)
  cout<<first[i][j]<<",";
  cout<<"\b }\n";
  } 
 
cout<<"\n\nfinding follow\n\n";

follow[0].push_back('$');

for(int i=0;i<r1.size();i++)
  {
  findfollow(r1,l1,i,follow,first);
  }
  

for(int i=0;i<r1.size();i++)
  {
  cout<<"follow ("<<r1[i]<<")"<<" = { ";
  for(int j=0;j<follow[i].size();j++)
  cout<<follow[i][j]<<",";
  cout<<"\b }\n";
  } 
 
cout<<"\n parsing table\n\n	";
ter.push_back('$');
 for(int i=0;i<ter.size();i++)
  cout<<ter[i]<<"	";
  
  
vector<char> table[r1.size()][ter.size()];
  
for(int i=0;i<r1.size();i++)
{
//	cout<<r1[i]<< "	";
	for(int j=0;j<l1[i].size();j++)
	{
	  if(l1[i][j][0]>=65 && l1[i][j][0]<=90)
	    {
	    	for(int k1=0;k1<r1.size();k1++)
	    	if(r1[k1]==l1[i][j][0])
	    	{
	    	     for(int k2=0;k2<first[k1].size();k2++)
	    	     {
	    	     	for(int k3=0;k3<ter.size();k3++)
  	    	     	if(first[k1][k2]==ter[k3])
  	    	     	{
  	    	     		table[i][k3].push_back(r1[i]);
  	    	     		table[i][k3].push_back('-');
  	    	     		table[i][k3].push_back('>');
  	    	     		for(int k=0;k<l1[i][j].size();k++)
  	    	     		table[i][k3].push_back(l1[i][j][k]);
  	    	     		break;
  	    	     	}
	    	     }
	    	     break;
	    	}
	    }
	    
	    else if(l1[i][j][0]=='#')
	    {
	    	   for(int k2=0;k2<follow[i].size();k2++)
	    	     {
	    	     	for(int k3=0;k3<ter.size();k3++)
	    	     	if(follow[i][k2]==ter[k3])
	    	     	{
	    	     		table[i][k3].push_back(r1[i]);
	    	     		table[i][k3].push_back('-');
	    	     		table[i][k3].push_back('>');
	    	     		for(int k=0;k<l1[i][j].size();k++)
	    	     		table[i][k3].push_back(l1[i][j][k]);
	    	     		break;
	    	     	}
	    	     }
	    }
	    else
	    {
	    	
	    		for(int k3=0;k3<ter.size();k3++)
	    		if(l1[i][j][0]==ter[k3])
	    		{
	    				  table[i][k3].push_back(r1[i]);
	    	     		table[i][k3].push_back('-');
	    	     		table[i][k3].push_back('>');
	    	     		for(int k=0;k<l1[i][j].size();k++)
	    	     		table[i][k3].push_back(l1[i][j][k]);
	    	     		break;
	    		}
	    	
	    	
	    }
	}
}
  
  cout<<"\n";
  for(int i=0;i<r1.size();i++)
  {
  	cout<<r1[i]<<"	";
  	for(int j=0;j<ter.size();j++)
  	{
  		for(int k=0;k<table[i][j].size();k++)
  		cout<<table[i][j][k];
  		cout<<"	";
  	}
  	cout<<"\n";
  }
  
  string s;
  cout<<"enter a string\n";
  cin>>s;
  


  vector<char> stk,input,output;
  
  stk.push_back('$');input.push_back('$');
  stk.push_back(r1[0]);
  for(int i=s.length()-1;i>=0;i--)
  input.push_back(s.at(i));
  
  
    cout<<"stack	input		output\n";
  
  int i,j,m2=0;
  while(1)
  {
  start:
  	m2++;
  	for(int i=0;i<stk.size();i++)
  	cout<<stk[i];
  	cout<<"	";
  		for(int i=input.size()-1;i>=0;i--)
  	cout<<input[i];
  		cout<<"		";
  		for(int i=0;i<output.size();i++)
  	cout<<output[i];
  	cout<<"\n";
  	
  	if(input.size()==1 && stk.size()==1)
  	break;
  	
  	if(stk[stk.size()-1]==input[input.size()-1])
  	{
  		input.pop_back();
  		stk.pop_back();
  		goto start;
  	}
  	
  	for( i=0;i<r1.size();i++)
  	if(stk[stk.size()-1]==r1[i])
  	break;
  	for(j=0;j<ter.size();j++)
  	if(input[input.size()-1]==ter[j])
  	break;
  	output.clear();
  	int m=1;
  	for(int k=0;k<table[i][j].size();k++)
  	output.push_back(table[i][j][k]);
  	stk.pop_back();
  	for(int k=table[i][j].size()-1;k>=0;k--){
  		
  		if(table[i][j][k]=='>'){
  	m=0;break;}
  	if(m==1)
  	{
      if(table[i][j][k]!='#') 	
  		stk.push_back(table[i][j][k]);
  	}
  }
  	
  }
  	
  
}