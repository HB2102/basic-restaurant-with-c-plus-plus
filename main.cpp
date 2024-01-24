#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <time.h>   
#include <cstring>
using namespace std;



struct food
{
	string name;
	int price;
	int preparetime;
	string description;
    string kind;
    
};


struct order{
    bool isPayed=false;
    string cUsername;
    string orderItems;
    int sPreparetime;
    bool ready=false;
    clock_t timer;
};
int stoy(string s);
bool is_emptyt(std::ifstream& pFile);
void getOrders(order *orders);
void loginAsManager(food *fooditem,order *orders);
void showOrders(order *orders,food *fooditem,string username);
void showMenu(string username,food *fooditem,order *orders);
void pay(string username,order *orders);
int maxpreparetime(string s,food *fooditem);
void customer(string username,food *fooditem,order *orders);
void signIn(food *fooditem,order *orders);
void signUp();
void loginAsCustomer(food *fooditem,order *orders);



int stoy(char s){
    stringstream str;
    str<<s;
    int n;
    str>>n;
    return n;

}

int stoy(string s){
    stringstream str;
    str<<s;
    int n;
    str>>n;
    return n;

}



int ordinx=0;

order orders[1000];

string managerUser="managerusername";
string managerPass="password";





int main(){


getOrders(orders);


food fooditem[22];

for(int i=0;i<6;i++)
    fooditem[i].kind="cholo khoresht";

for(int i=6;i<12;i++)
    fooditem[i].kind="kabab";

for(int i=12;i<16;i++)
    fooditem[i].kind="mokhalafat";

for(int i=16;i<22;i++)
    fooditem[i].kind="noshidani";



fooditem[3].name="Ghorme Sabzi" ,fooditem[3].price=17000,fooditem[3].preparetime=20,fooditem[3].description="ba sabzi haye taze va mokhalafat";
fooditem[4].name="Gheyme",fooditem[4].price=15000,fooditem[4].preparetime=15,fooditem[4].description="kamelan pokhte shode va tord ba mokhalafat";
fooditem[5].name="Khoresht Sibzamini",fooditem[5].price=14000,fooditem[5].preparetime=15,fooditem[5].description="khoreshte sibzamini ba kare va mokhalafat";
fooditem[2].name="Loobia Plo",fooditem[2].price=22000,fooditem[2].preparetime=20,fooditem[2].description="loobia plo ba sib zamini va mokhalafat";
fooditem[0].name="Khoresht Boughalamoon",fooditem[0].price=30000,fooditem[0].preparetime=25,fooditem[0].description="khoresht boughalamoon taze va moghalafat";
fooditem[1].name="Khoresht Bademjan",fooditem[1].price=25000,fooditem[1].preparetime=25,fooditem[1].description="khoreshte bademjan va mokhalafat";
fooditem[11].name="Jooje Kabab",fooditem[11].price=250000,fooditem[11].preparetime=30,fooditem[11].description="akbar jooje va mokhalafat";
fooditem[9].name="Chlo Kabab",fooditem[9].price=25000,fooditem[9].preparetime=25,fooditem[9].description="gooshte taze va salem ba mokhalafat";
fooditem[8].name="Morghe Torsh",fooditem[8].price=30000,fooditem[8].preparetime=35,fooditem[8].description="morghe motevaset ba torshi va mokhalafat";
fooditem[6].name="Kabab Dande",fooditem[6].price=40000,fooditem[6].preparetime=25,fooditem[6].description="kabab dande goosfandie taze va mokhalafat";
fooditem[7].name="kabab Torsh",fooditem[7].price=30000,fooditem[7].preparetime=25,fooditem[7].description="kabab barg ba torshie ezafe va mokhalafat";
fooditem[10].name="Kabab Barg",fooditem[10].price=27000,fooditem[10].preparetime=25,fooditem[10].description="kabab barg va mokhalafat";
fooditem[15].name="Maste Mahali",fooditem[15].price=5000,fooditem[15].preparetime=0,fooditem[15].description="mast mahali taze";
fooditem[12].name="Zeytoon Parvardeh",fooditem[12].price=12000,fooditem[12].preparetime=0,fooditem[12].description="zeytoon parvarde mahali";
fooditem[13].name="Salad Fasl",fooditem[13].price=10000,fooditem[13].preparetime=0,fooditem[13].description="salad fasle sade";
fooditem[14].name="Salad Shirazi",fooditem[14].price=8000,fooditem[14].preparetime=0,fooditem[14].description="salad shirazi taze";
fooditem[20].name="Ab Madani",fooditem[20].price=4000,fooditem[20].preparetime=0,fooditem[20].description="Ab madani damavand";
fooditem[17].name="Nooshabe Meshki",fooditem[17].price=8000,fooditem[17].preparetime=0,fooditem[17].description="nooshabe sade";
fooditem[18].name="Nooshabe Narenji",fooditem[18].price=8000,fooditem[18].preparetime=0,fooditem[18].description="nooshabe sade";
fooditem[15].name="Limonad",fooditem[19].price=8000,fooditem[19].preparetime=0,fooditem[19].description="nooshabe sade";
fooditem[19].name="Doogh",fooditem[20].price=5000,fooditem[20].preparetime=0,fooditem[20].description="doogh karkhane ei";
fooditem[16].name="Dooghe mahali",fooditem[16].price=8000,fooditem[16].preparetime=0,fooditem[16].description="doogh mahali taze";















int input;
cout<<"\nwelcome to our resturant\n";
while(true)
{
cout<<"\nchoose a number:\n1-login as customer\n2-login as manager\n0-exit\n";
cin>>input;
if(input==1)
{
loginAsCustomer(fooditem,orders);
}
else if(input==2)
{
    loginAsManager(fooditem,orders);
}

else if(input==0)
{
    break;
}

else    
    continue;


}






}




void loginAsCustomer(food *fooditem,order *orders)
{
    int input;
    while(true)
    {
        cout<<"\nplease choose a number:\n1-sign up\n2-sign in\n0-exit\n";
        cin>>input;
        if(input==1)
            signUp();

        else if(input==2)
            signIn(fooditem,orders);

        else if(input==0)
            break;

    }


}




void signUp(){
    string username;

    cout<<"\nplease enter your username:\n";
    cin>>username;
    cout<<"please enter your password:\n";
    string password;
    cin>>password;
    ofstream users("users.txt",ios::app);

    users<<username<<" "<<password<<"\n";

    users.close();

    cout<<"\nyou signed up successfully\n";

}


void signIn(food *fooditem,order *orders)
{
    cout<<"\nplease enter your username:\n";
    string username;
    cin>>username;
    string password;
    cout<<"please enter your password:\n";
    cin>>password;
    ifstream users("users.txt");

    string t[2];
    bool te=false;
    while(users>>t[0]>>t[1])
    {
        if(t[0]==username && t[1]==password)
        {
            te=true;
            customer(username,fooditem,orders);
        }
    }

    if(!te)
        {
            cout<<"\nusername or password is wrong\nplease enter again:\n";
            signIn(fooditem,orders);
        }




}



void customer(string username,food *fooditem,order *orders)
{
    int input;
    while(true)
    {
        cout<<"\n please choose a number:\n1-show menu\n2-show orders\n3-pay\n0-exit\n";
        cin>>input;
        if(input==1)
            showMenu(username,fooditem,orders);

        else if(input==2)
            showOrders(orders,fooditem,username);
        else if(input==3)
            pay(username,orders);
        else if(input==0)
            break;






    }



}



int maxpreparetime(string s,food *fooditem)
{
    int n=(int)s.length();
int max =0;
int t;
for(int i=0;i<n;i++){
    stringstream str;
    if(s[i]=='-')
        continue;
    if(s[i+1]=='-' && s[i]=='0')
        continue;
    if(s[i+1]==0 && s[i-1]=='-')
        {
            str<<s[i];
            str>>t;
            t*=10;
        }
    else {
        str<<s[i];
        str>>t;
    }
if(fooditem[t].preparetime>max)
    max = fooditem[t].preparetime;
}

return max;


}



 void showMenu(string username,food *fooditem,order *orders){
    int input;
    while(input!=0){
     cout<<"\nwhich kind of food do you want?\n1-cholo khoresht\n2-kabab\n3-mokhalafat\n4-nushidani\n0-exit\n";
     
     cin>>input;
      string ord;
      bool dor=false;
     if(input==1){
        for(int i=0;i<6;i++)
            cout<<i<<"-food name : "<<fooditem[i].name<<" price: "<<fooditem[i].price<<" prepating time:"<<fooditem[i].preparetime<<" details: "<<fooditem[i].description<<endl;
            cout<<"\ndo you want to order anything?\n1-yes\n2-no\n";
            int majid;
            cin>>majid;
            if(majid==1)
                {
                    
                    int temp;
                   
                    while(true)
                    {
                        cout<<"enter your order(enter -1 if you want to exit)\n";
                        
                        int j=0;
                        string o;
                       
                        
                            cin>>o;
                            if(o=="-1")
                                break;
                            ord.append(o);
                            ord.append("-");
                            dor=true;
                        

                    }
                    if(dor){
                        ofstream orderf("orders.txt",ios::app);
                        orders[ordinx].cUsername=username;
                        orders[ordinx].orderItems=ord;
                        orders[ordinx].sPreparetime=maxpreparetime(ord,fooditem);
                        orderf<<orders[ordinx].cUsername<<" "<<orders[ordinx].orderItems<<" "<<orders[ordinx].sPreparetime;
                        orders[ordinx].timer=clock();
                        if(!orders[ordinx].isPayed)
                            orderf<<" notPayed ";

                        else
                            orderf<<" payed ";

                        if(!orders[ordinx].ready)
                            orderf<<" notReady ";

                        else 
                            orderf<<" ready ";

                            orderf<<"\n";
                             orderf.close();
                    cout<<"\nthank for your order";


                    }


                }
     }
    else if(input==2){
          for(int i=6;i<12;i++)
            cout<<i<<"-food name : "<<fooditem[i].name<<" price: "<<fooditem[i].price<<" prepating time:"<<fooditem[i].preparetime<<" details: "<<fooditem[i].description<<endl;
   
            cout<<"\ndo you want to order anything?\n1-yes\n2-no\n";
            int majid;
            cin>>majid;
            if(majid==1)
                {
                    int temp;
                    while(true)
                    {
                        cout<<"enter your order(enter -1 if you want to exit)\n";
                        bool dor=false;
                        int j=0;
                        string o;
                        string ord;
                        
                        
                            cin>>o;
                            if(o=="-1")
                                break;
                            ord.append(o);
                            ord.append("-");
                            dor=true;
                        

                    }
                    if(dor){
                        ofstream orderf("orders.txt");
                        orders[ordinx].cUsername=username;
                        orders[ordinx].orderItems=ord;
                        orders[ordinx].sPreparetime=maxpreparetime(ord,fooditem);
                        orderf<<orders[ordinx].cUsername<<" "<<orders[ordinx].orderItems<<" "<<orders[ordinx].sPreparetime<<" ";
                        orders[ordinx].timer=clock();
                           if(!orders[ordinx].isPayed)
                            orderf<<" notPayed ";

                        else
                            orderf<<" payed ";

                        if(!orders[ordinx].ready)
                            orderf<<" notReady ";

                        else 
                            orderf<<" ready ";

                            orderf<<"\n";
                             orderf.close();
                    cout<<"\nthank for your order";


                    }


                }
    
    
    }

    else if(input==3){
          for(int i=12;i<16;i++)
            cout<<i<<"-food name : "<<fooditem[i].name<<" price: "<<fooditem[i].price<<" prepating time:"<<fooditem[i].preparetime<<" details: "<<fooditem[i].description<<endl;
    
            cout<<"\ndo you want to order anything?\n1-yes\n2-no\n";
            int majid;
            cin>>majid;
            if(majid==1)
                {
                    int temp;
                    while(true)
                    {
                        cout<<"enter your order(enter -1 if you want to exit)\n";
                        bool dor=false;
                        int j=0;
                        string o;
                        string ord;
                        
                            cin>>o;
                            if(o=="-1")
                                break;
                            ord.append(o);
                            ord.append("-");
                            dor=true;
                        

                    }
                    if(dor){
                        ofstream orderf("orders.txt");
                        orders[ordinx].cUsername=username;
                        orders[ordinx].orderItems=ord;
                        orders[ordinx].sPreparetime=maxpreparetime(ord,fooditem);
                        orderf<<orders[ordinx].cUsername<<" "<<orders[ordinx].orderItems<<" "<<orders[ordinx].sPreparetime<<" ";
                           if(!orders[ordinx].isPayed)
                            orderf<<" notPayed ";

                        else
                            orderf<<" payed ";

                        if(!orders[ordinx].ready)
                            orderf<<" notReady ";

                        else 
                            orderf<<" ready ";

                            orderf<<"\n";
                            orderf.close();
                        orders[ordinx].timer=clock();
                    cout<<"\nthank for your order";


                    }


                }
    
    
    }
       else if(input==4){
          for(int i=16;i<22;i++)
            cout<<i<<"-food name : "<<fooditem[i].name<<" price: "<<fooditem[i].price<<" prepating time:"<<fooditem[i].preparetime<<" details: "<<fooditem[i].description<<endl;
    
            cout<<"\ndo you want to order anything?\n1-yes\n2-no\n";
            int majid;
            cin>>majid;
            if(majid==1)
                {
                    int temp;
                    while(true)
                    {
                        cout<<"enter your order(enter -1 if you want to exit)\n";
                        bool dor=false;
                        int j=0;
                        string o;
                        string ord;
                        
                            cin>>o;
                            if(o=="-1")
                                break;
                            ord.append(o);
                            ord.append("-");
                            dor=true;
                        

                    }
                    if(dor){
                        ofstream orderf("orders.txt");
                        orders[ordinx].cUsername=username;
                        orders[ordinx].orderItems=ord;
                        orders[ordinx].sPreparetime=maxpreparetime(ord,fooditem);
                        orderf<<orders[ordinx].cUsername<<" "<<orders[ordinx].orderItems<<" "<<orders[ordinx].sPreparetime<<" ";
                           if(!orders[ordinx].isPayed)
                            orderf<<" notPayed ";

                        else
                            orderf<<" payed ";

                        if(!orders[ordinx].ready)
                            orderf<<" notReady ";

                        else 
                            orderf<<" ready ";

                            orderf<<"\n";
                             orderf.close();
                        orders[ordinx].timer=clock();
                    cout<<"\nthank for your order";


                    }


                }
    
    
    }
    }
    ordinx++;
 }



void showOrders(order *orders,food *fooditem,string username){
    for(int i=0;i<ordinx;i++)
    {
        int t;
        
        cout<<orders[1].cUsername;
        if(orders[i].cUsername==username)
        {
            
            for(int j=0;j<orders[i].orderItems.length();j++)
            {
                 
                 
                if(orders[i].orderItems.at(j)=='-')
                    continue;
                else if( ( orders[i].orderItems.at(j+1)=='-'  && j<orders[i].orderItems.length()-1)  && ( j>0 && orders[i].orderItems.at(j-2) != '-'))
                    continue;
                else if( (j>0 && j<orders[i].orderItems.length()-1) && orders[i].orderItems.at(j-1)=='-' && orders[i].orderItems.at(j+2) != '-')
                    t=stoy(orders[i].orderItems.at(j))*10;
                else
                {
                    
                    t=stoy(orders[i].orderItems.at(j));
                    

                }
                
                cout<<"\nfood: "<<fooditem[t].name<<" price: "<<fooditem[t].price<<" description: "<<fooditem[t].description<<" time remaining: ";
                if(((int)(clock() - orders[i].timer))/((double)CLOCKS_PER_SEC)/60 >= fooditem[t].preparetime)
                    cout<<(int)(clock() - orders[i].timer)/((double)CLOCKS_PER_SEC)/60<<endl;
                else
                    cout<<"Ready to serve\n";

            }

        }
    }


}




void loginAsManager(food *fooditem,order *orders)
{
    bool t = false;
    while(!t)
    { 
        string us,ps;
        cout<<"\nenter username:";
        cin>>us;
        cout<<endl;
        cout<<"enter password:";
        cin>>ps;
        cout<<endl;
        if(us==managerUser && ps==managerPass)
            t=true;
        else{
            cout<<"wrong password or username do you want to try again?\n1-yes\n2-no\n";
            int input;
            cin>>input;
            if(input==1)
                continue;
            else 
                break;

        }

    }



    if(t)
        while(true)
        {
            cout<<"\nplease choose a number:\n1-show orders\n2-change ready situation\n3-exit:";
            int input;
            cin>>input;
            if(input==3)
                break;
            if(input==1){
                string usert,orderi,ispay;
                int preparing;
                ifstream orderf("orders.txt");
                for(int i=0;i<ordinx;i++)
                {
                cout<<"\nusername : "<<orders[i].cUsername<<" orders:\n";
                 
    
        int t;
        

            for(int j=0;j<orders[i].orderItems.length();j++)
            {
                if(orders[i].orderItems[j]=='-')
                    continue;
                else if(orders[i].orderItems[i+1]=='-' && orders[i].orderItems[i-1] != '-')
                    continue;
                else if(orders[i].orderItems[i-1]=='-' && orders[i].orderItems[i+1]!='-')
                    t=i*10;
                else
                    t=i;
                cout<<"\nfood: "<<fooditem[t].name<<" price: "<<fooditem[t].price<<" description: "<<fooditem[t].description<<" time remaining: ";
                if((int)(clock() - orders[i].timer)/((double)CLOCKS_PER_SEC)/60 >=fooditem[t].preparetime)
                    cout<<(int)(clock() - orders[i].timer)/((double)CLOCKS_PER_SEC)/60<<endl;
                else
                    cout<<"Ready to serve\n";

            }


            cout<<" ready: "<<orders[i].ready<<" is payed: "<<orders[i].isPayed<<endl;
                }


                 for(int i=0;i<ordinx;i++)
                {
                    if(!orders[i].isPayed){
                cout<<"\nusername : "<<orders[i].cUsername<<" orders:\n";
                 
    
        int t;
        

            for(int j=0;j<orders[i].orderItems.length();j++)
            {
                if(orders[i].orderItems[j]=='-')
                    continue;
                else if(orders[i].orderItems[j+1]=='-' && orders[i].orderItems[j-1] != '-')
                    continue;
                else if(orders[i].orderItems[j-1]=='-' && orders[i].orderItems[j+1]!='-')
                    t=i*10;
                else
                    t=i;
                cout<<"\nfood: "<<fooditem[t].name<<" price: "<<fooditem[t].price<<" description: "<<fooditem[t].description<<" time remaining: ";
                if((int)(clock() - orders[i].timer)/((double)CLOCKS_PER_SEC)/60 >=fooditem[t].preparetime)
                    cout<<(int)(clock() - orders[i].timer)/((double)CLOCKS_PER_SEC)/60<<endl;
                else
                    cout<<"Ready to serve\n";

            }


            cout<<" ready: "<<orders[i].ready<<" is payed: "<<orders[i].isPayed<<endl;
                    }
                }

   
    }
    if(input==2)
    {
        cout<<"enter order number:";
        int tor;
        cin>>tor;
        cout<<endl;
        orders[tor].ready=true;


    }
            }







            }


        










void getOrders(order *orders){
int i=0;

ifstream orderf("orders.txt");
string t;
int space;
while(getline(orderf,t))
{
    int te=t.find(" ");
    int temp;
    orders[i].cUsername=t.substr(0,te);
    temp=t.find(" ",te + 1);
    orders[i].orderItems=t.substr(te+1,temp);
    te=t.find(" ",temp+1);
    orders[i].sPreparetime=stoy(t.substr(temp+1,te));
    temp=t.find(" ",te);
    if(t.substr(te+1,temp)=="notPayed")
        orders[i].isPayed=false;
    else
        orders[i].isPayed=true;
    te=t.find(" ",temp);
    if(t.substr(temp+1,te)=="notReady")
        orders[i].ready=false;
    else
        orders[i].ready=true;


i++;
ordinx++;


}


    
}






bool is_emptyt(std::ifstream& pFile)
{
    return pFile.peek() == std::ifstream::traits_type::eof();
}




void pay(string username,order *orders)
{
for(int i=0;i<ordinx;i++){
    if(orders[i].cUsername==username)
    {
        orders[i].isPayed=true;
        ofstream orderf("orders.txt",ios::app);
         orderf<<endl<<orders[i].cUsername<<" "<<orders[i].orderItems<<" "<<orders[i].sPreparetime<<" payed "<<endl;
        
    }
}
cout<<"\npayed.\n";

}