//Write your code here
#include<bits/stdc++.h>
using namespace std;
int main(){
	vector<string>name;
	vector<string>grade;
	vector<int>score;
	string n,input,com;
	int a,b,c,w=0,namec=0;
	string text;
	ifstream in("name_score.txt");
	
	char format[]="%[^:]: %d %d %d";
	while(getline(in,text)){
		//cout<<text<<endl;
		char texter[100];
		char what[100];
		strcpy(texter,text.c_str());
		
		
		sscanf(texter,format,what,&a,&b,&c);
		name.push_back(what);
		score.push_back(a+b+c);
		if(a+b+c>=80){
			grade.push_back("A");
		}else if(a+b+c>=70){
			grade.push_back("B");
		}else if(a+b+c>=60){
			grade.push_back("C");
		}else if(a+b+c>=50){
			grade.push_back("D");
		}else {
			grade.push_back("F");
		}
		/*cout<<name[w]<<" "<<grade[w]<<" "<<score[w]<<endl;
		w++;*/
	}
	string wow="";
	do{
		
		wow="";
		cout<<"Please input your command :";
		
		//cin>>input;
		getline(cin,input);
		cout<<"---------------------------------"<<endl;
		string s;
		istringstream is(input);
		string q[5];
		int u=0;
		while(is>>q[u]){
			u++;
		}
		
		string lol="",mom="";
		 locale loc,ddd;
  		
  		for (string::size_type i=0; i<q[0].length(); ++i){
    			wow=wow+tolower(q[0][i],loc);
		}
		
		if(wow=="grade"){
			
			for (string::size_type i=0; i<q[1].length(); ++i){
    			lol=lol+toupper(q[1][i],loc);
		}
			//cin>>com;
			for(int i=0;i<name.size();i++){
				
					
				if(grade[i]==lol){
					cout<<name[i]<<endl;
					
				}
			}
			
		}else if(wow=="name"){
		for(int t=1;t<u;t++){
				for (string::size_type i=0; i<q[t].length(); ++i){
    			lol=lol+tolower(q[t][i],loc);
		}
		if(t<u-1){
			lol=lol+" ";
		}
		
		
		}
		//cout<<lol;
		
		
				for(int i=0;i<name.size();i++){
					mom="";
					for (string::size_type j=0; j<name[i].length(); ++j){
    			mom=mom+tolower(name[i][j],loc);
		}	
				
				if(mom==lol){
					namec++;
					cout<<name[i]<<"'s grade = "<<grade[i]<<endl;
				}
			}
			if(namec==0){
				cout<<"Cannot found.\n";
			}	
		}else if(wow!="exit"){
			
			cout<<"Invalid command\n";
		}
		
		namec=0;
		cout<<"---------------------------------"<<endl;
	}while(wow!="exit");
	
}
