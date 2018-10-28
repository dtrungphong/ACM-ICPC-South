#include <bits/stdc++.h>

using namespace std;

int main(){
	bool Check=1;
	string text;
	string temp="";
	cin>>text;
	if (text[0]>'8')
		text=string(text.size(),'8');
	else if (text[0]=='7')
		text="6"+string(text.size()-1,'8');
	else if (text[0]<'6')
		text=string(text.size()-1,'8');
	else{
		for (unsigned long long int i=0;i<text.size();i++){
			if (text[i]=='6'||text[i]=='8'){
				temp+=text[i];
				continue;
			}
			else if (text[i]>'8'){
				text=temp+string(text.size()-i,'8');
				break;
			}
			else if (text[i]=='7'){
				temp+="6";
				text=temp+string(text.size()-i-1,'8');
				break;
			}
			else if (text[i]<'6'){
				for (unsigned long long int j=temp.size()-1;j>=0;j--){
					if (temp[j]=='8'){
						temp[j]='6';
						break;
					}
					else if (j!=0&&temp[j]=='6'){
						temp[j]='8';
					}
					else if (temp[j]=='6'&&j==0){
						temp=string(temp.begin()+1,temp.end());
					}

				}
				text=temp+string(text.size()-i,'8');
				break;
			}
		}
	}
	cout<<text;
	return 0;
}
