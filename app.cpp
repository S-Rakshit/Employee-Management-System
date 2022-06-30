#include <bits/stdc++.h>
//#include<iostream>
//#include<vector>
//#include<map>
//#include <fstream>

using namespace std;

class user{
public:
    int age;
    string fname;
    string lname;
    string id;
    string email;
    string gender;
    user(string f,string l,string i,int a,string eml,string gndr){
        fname=f;
        lname=l;
        id=i;
        age=a;
        email=eml;
        gender=gndr;
    }
};

vector<user*>usr;
map<string,user*>mp;

void add(){
    string f,l,i,eml,gndr;
    int a;
    string cnfm;
    cout<<"Enter First name : ";
    cin>>f;
    // cout<<endl;
    cout<<"Enter Last name : ";
    cin>>l;
    // cout<<endl;
    cout<<"Enter ID : ";
    cin>>i;
    cout<<"Enter email-id : ";
    cin>>eml;
    cout<<"Enter gender : ";
    cin>>gndr;
    if(mp[i]!=NULL){
        cout<<"User Exists!! "<<endl;
        return ;
    }
    // cout<<endl;
    cout<<"Enter Age : ";
    string ag;
    cin>>ag;
    if(ag.length()>3){
        cout<<"Invalid age entered "<<endl;
        return;
    }
    for(auto it:ag){
        if((it>='a'&&it<='z')||(it>='A'&&it<='Z')){
            cout<<"Invalid age entered , age should be numeric"<<endl;
            return ;
        }
    }
    a=stoi(ag);
    // cout<<endl;
    cout<<"Press 1 to save user details or any other key to abort ";
    // cout<<endl;
    cin>>cnfm;
    if(cnfm=="1"){
        user *tmp=new user(f,l,i,a,eml,gndr);
        usr.push_back(tmp);
        mp[i]=tmp;
        cout<<"User details saved ."<<endl;
    }
    else{
        cout<<"User details not saved ."<<endl;
    }
    
}

void show(user *it){
     cout<<"User name : "<<it->fname<<" "<<it->lname<<endl;
     cout<<"Id : "<<it->id<<endl;
    cout<<"Age : "<<it->age<<endl;
     cout<<"Email : "<<it->email<<endl;
      cout<<"Gender : "<<it->gender<<endl;
    cout<<endl<<endl;
}

void display(string a){
    if(a=="1"){
        cout<<"Enter User ID to find the user : ";
        string u_id="99";
        cin>>u_id;
        cout<<endl;
        user *tmp=mp[u_id];
        if(tmp==NULL){
            cout<<"No user found with the given id"<<endl;
        }
        else{
           show(tmp);
        }
    }
    else{
        if(usr.size()==0){
            cout<<"No users to display"<<endl;
            return ;
        }

        for(auto it:usr){
            show(it);
        }
    }
    
}

void userdisplay(string a){
      string u_id=a;
        cout<<endl;
        user *tmp=mp[u_id];
        if(tmp==NULL){
            cout<<"No user found with the given id"<<endl;
        }
        else{
           show(tmp);
        }
}

bool verifyhr(string a){
        //cout<<"Enter User ID to find HR : ";
        string u_id=a;
        cout<<endl;
        user *tmp=mp[u_id];
        if(tmp==NULL){
            cout<<"No HR found with the given id"<<endl;
            return false;
        }
        string hrid=tmp->id;
    if(hrid.length()>1&&hrid[0]=='9'&&hrid[1]=='9'){
        cout<<"HR Found Succesfully"<<endl;
        return true;
    }
    cout<<"HR Not Found"<<endl;
    return false;
}

bool verifymn(string a){
        string u_id=a;
        cout<<endl;
        user *tmp=mp[u_id];
        if(tmp==NULL){
            cout<<"No Manager found with the given id"<<endl;
            return false;
        }
        string mnid=tmp->id;
    if(mnid.length()>1&&mnid[0]=='5'&&mnid[1]=='5'){
         cout<<"Manager Found Succesfully"<<endl;
        return true;
        }
    cout<<"Manager Not Found "<<endl;
    return false;
}

bool verifygen(string a){
        string u_id=a;
        cout<<endl;
        user *tmp=mp[u_id];
        if(tmp==NULL){
            cout<<"No General User found with the given id"<<endl;
            return false;
        }
        string mnid=tmp->id;
    if(mnid.length()>1&&mnid[0]!='5'&&mnid[1]!='5'&&mnid[0]!='9'&&mnid[1]!='9'){
        cout<<"General User Found Succesfully"<<endl;
        return true;
    }
    cout<<"General User Not Found"<<endl;
    return false;
}

void search(){
  display("1");
}

void update(){
    cout<<"Enter User ID to find the user and modify : ";
    string u_id="99";
    cin>>u_id;
    cout<<endl;
    user *tmp=mp[u_id];
    if(tmp!=NULL){
        cout<<"Current details of user : "<<endl;
        show(tmp);
           string f,l,i,cnfm,eml,gndr;
            int a;
            cout<<"Enter Updated First name : ";
            cin>>f;
            cout<<endl;
            cout<<"Enter Updated Last name : ";
            cin>>l;
            cout<<endl;
            cout<<"Enter Updated Age : ";
            cin>>a;
            cout<<endl;
            cout<<"Enter Updated email address : ";
            cin>>eml;
            cout<<endl;
            cout<<"Enter Updated gender : ";
            cin>>gndr;
            cout<<endl;
            cout<<"Press 1 to update user details or any other key to discard ";
            cout<<endl;
            cin>>cnfm;
            if(cnfm=="1"){
                tmp->fname=f;
                tmp->lname=l;
                tmp->age=a;
                tmp->email=eml;
                tmp->gender=gndr;
                cout<<"User details Updated ."<<endl;
            }
            else{
                cout<<"User details not updated ."<<endl;
            }
    }
    else{
        cout<<"No user found with given details"<<endl;;
    }
}

void remove(){
    cout<<"Enter User ID to find the user and delete : ";
    string u_id="99";
    cin>>u_id;
    cout<<endl;
    user *tmp=mp[u_id];
    if(tmp!=NULL){
        cout<<"Details of the user to be deleted "<<endl;
        show(tmp);
        string cnfm=0;
        cout<<"Press '1' to confirm deletion of user "<<endl;
        cin>>cnfm;
        cout<<endl;
        if(cnfm=="1"){
             mp[u_id]=NULL;
             cout<<"User deleted succeessfully"<<endl;
        }
        else{
            cout<<"Deletion Aborted "<<endl;
        }
    }
    else{
         cout<<"No user found with given details"<<endl;;
    }
}

bool comp1(user *u1,user *u2){
    string id_u1=u1->id,id_u2=u2->id;
    if(id_u1<=id_u2){
        return true;
    }
    return false;
}

bool comp2(user *u1,user *u2){
    string name_u1=u1->fname,name_u2=u2->fname;
    if(name_u1<=name_u2){
        return true;
    }
    return false;
}

void sortdoc(int a){
    if(a==1){ //sort by id
        vector<user*>tmp=usr;
        sort(tmp.begin(),tmp.end(),comp1);
        for(auto it:tmp){
            show(it);
        }
    }
    else{ //sort by name
        vector<user*>tmp=usr;
        sort(tmp.begin(),tmp.end(),comp2);  
         for(auto it:tmp){
            show(it);
        }
    }
}

void savedata(){
   ofstream outfile;
   outfile.open ("user_details.txt", ios::out | ios::trunc); 
    for(auto it:usr){
        outfile<<it->fname<<","<<it->lname<<","<<it->id<<","<<it->age<<","<<it->email<<","<<it->gender<<endl;
        //  cout<<it->fname<<","<<it->lname<<","<<it->id<<","<<it->age<<","<<it->email<<","<<it->gender<<endl;
    }
   outfile.close();
}

void separator(string s){
    int len=s.length();
    int prv=0;
    string f,l,my_id,eml,gndr;
    int a,ct=0;
    for(int i=0;i<len;i++){
        if(s[i]==','){
            if(ct==0){
                int lth=i-1-prv+1;
                f=s.substr(prv,lth);
                ct++;
                prv=i+1;
            }
            else if(ct==1){
                int lth=i-1-prv+1;
                l=s.substr(prv,lth);
                ct++;
                prv=i+1;
            }
            else if(ct==2){
                int lth=i-1-prv+1;
                my_id=s.substr(prv,lth);
                ct++;
                prv=i+1;
            }
            else if(ct==3){
                int lth=i-1-prv+1;
                // cout<<"read "<<s.substr(prv,lth)<<endl;
                a=stoi(s.substr(prv,lth));
                ct++;
                prv=i+1;
            }
            else if(ct==4){
                int lth=i-1-prv+1;
                eml=s.substr(prv,lth);
                ct++;
                prv=i+1;
            }
        }
    }
    int lstlen=len-prv+1;
    gndr=s.substr(prv,lstlen);
    user *tmp=new user(f,l,my_id,a,eml,gndr);
    usr.push_back(tmp);
    mp[my_id]=tmp;
}

void retireive_data(){
   ifstream infile ("user_details.txt", std::ifstream::binary); 
   string line;
    while(getline(infile, line)){ //read data from file object and put it into string.
        //  cout << line << "\n"; //print the data of the string
         separator(line);
      }
}

void looper(){
        while(1){
        string n;
        cout<<"   Press 1 to add new user : "<<endl;
        cout<<"   Press 2 to search user : "<<endl;
        cout<<"   Press 3 to display user : "<<endl;
        cout<<"   Press 4 to update user : "<<endl;
        cout<<"   Press 5 to delete user : "<<endl;
        cout<<"   Press 6 to sort  : "<<endl;
        cout<<"   Press 9 to Exit "<<endl;
        cin>>n;
        if(n=="1"){
            add();
        }
        else if(n=="2"){
            search();
        }
        else if(n=="3"){
            string z="1";
            cout<<"Press '1' to find single user or anyother key to see all user details : ";
            cin>>z;
            cout<<endl;
            display(z);
        }
        else if(n=="4"){
            update();
        }
        else if(n=="5"){
            remove();
        }
        else if(n=="6"){
            cout<<"Press 1 to sort user by IDs or press anyother key to sort by their name"<<endl;
            string z;
            cin>>z;
            if(z=="1"){
                sortdoc(1);
            }
            else{
                sortdoc(100);
            }
        }
        else if(n=="9"){
            string ch;
            cout<<"Press Y/y to confirm to exit"<<endl;
            cin>>ch;
            if(ch=="Y"||ch=="y")break;
            
        }
        else{
            cout<<"Alert!! Enter a valid option "<<endl;
        }
    }
    savedata();
}

void loopermn(){
        while(1){
        string n;
        cout<<"   Press 1 to search user : "<<endl;
        cout<<"   Press 2 to display user : "<<endl;
        cout<<"   Press 3 to sort  : "<<endl;
        cout<<"   Press 9 to Exit "<<endl;
        cin>>n;
        if(n=="1"){
            search();
        }
        else if(n=="2"){
            string z="1";
            cout<<"Press '1' to find single user or anyother key to see all user details : ";
            cin>>z;
            cout<<endl;
            display(z);
        }
        else if(n=="3"){
            cout<<"Press 1 to sort user by IDs or press anyother key to sort by their name"<<endl;
            string z;
            cin>>z;
            if(z=="1"){
                sortdoc(1);
            }
            else{
                sortdoc(100);
            }
        }
        else if(n=="9"){
            string ch;
            cout<<"Press Y/y to confirm to exit"<<endl;
            cin>>ch;
            if(ch=="Y"||ch=="y")break;
            
        }
        
        else{
            cout<<"Alert!! Enter a valid option "<<endl;
        }
    }
}

int main(){
retireive_data();
    while(1){
        string typeemp;
         cout<<"   Press HR/hr for HR Login : "<<endl;
         cout<<"   Press MN/mn for Management Login : "<<endl;
         cout<<"   Press GEN/gen for General Login : "<<endl;
         cout<<"   Press Q/q for Quiting : "<<endl;
         cin>>typeemp;
         if(typeemp=="HR"||typeemp=="hr"){
            bool flg=false;
            cout<<"Enter HR User Name"<<endl;
            string hrid="";
            cin>>hrid;
            //HR userid start from 99
            flg=verifyhr(hrid);
            if(flg){
                looper();
            }
         }
         else if(typeemp=="MN"||typeemp=="mn"){
            bool flg=false;
            cout<<"Enter Manager User Name"<<endl;
            //Manager userid start from 55
            string mangid="";
            cin>>mangid;
            flg=verifymn(mangid);
            if(flg){
                loopermn();
            }
         }
         else if(typeemp=="GEN"||typeemp=="gen"){
            bool flg=false;
            cout<<"Enter General User Name"<<endl;
            //Manager userid start from 55
            string genid="";
            cin>>genid;
            flg=verifygen(genid);
            if(flg){
                userdisplay(genid);
            }
         }
         else if(typeemp=="Q"||typeemp=="q"){
            string ch;
            cout<<"Press Y/y to confirm to exit"<<endl;
            cin>>ch;
            if(ch=="Y"||ch=="y")break;
            
        } 
         else{
             cout<<"Enter Valid Option";
         }
    }

}