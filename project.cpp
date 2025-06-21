#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
using namespace std;

int seprate(string s)
{
    string final = "";

    int lnth = s.length();

    char f1, f2, f3;

      f1  = s[lnth-7];
      f2  = s[lnth-6];
      f3  = s[lnth-5];

      string  first(1, f1);
      string middle(1, f2);
      string   last(1, f3);

      final = first + middle + last;
      int num = stoi(final);

      return num;
      

}

int main()

{  
   /* declaration */

   int price[50];
   int choice[50];
   float sum = 0;
   int i = 0;
   int price_id;
   int dish_id;

   string dish;
   string dish_name[50];   

   ifstream menu;
   ofstream bill;

   menu.open("menu.txt");
   bill.open("bill.txt");


   while(menu.eof()==0)
   {
      getline(menu, dish);
      cout<<dish<<endl; // so that we can show menu

      dish_name[i] = dish; // so that dish ki di

      price[i] = seprate(dish);
      i++;

   }

   /* user choose choices */

   cout<<"\nEnter your choices : "<<endl;


   for(int i=0; i<50; i++)
   {
      cin>>choice[i];

      if(choice[i] == 0)
      {
         cout<<"\nThankyou sir, we prepare your order.\n"<<endl;
         break;
      }

   }


   /* for billing calculation */


   for(int i=0; i<50; i++)
   {
      price_id = choice[i];

      if(price_id ==0)
      {
         break;
      }

      sum = sum + price[price_id-1];

   }

 

   /* bill printing */
   cout<<"************Bill*****************"<<endl;
   cout<<endl;   
   cout<<"   DISHES                   PRICE"<<endl;
   cout<<endl;
   
   bill<<"************Bill*****************"<<endl;
   bill<<endl;   
   bill<<"   DISHES                   PRICE"<<endl;
   bill<<endl;


   for(int i = 0; i<50; i++)
   {
      dish_id = choice[i];

      if(dish_id==0)
      {
         break;
      }

      bill<<dish_name[dish_id-1]<<endl;
      cout<<dish_name[dish_id-1]<<endl;

   }
   
   cout<<endl;
   cout<<"************************************"<<endl;
   cout<<"  Total     :               "<<sum<<" ₹"<<endl;
   cout<<"  Tax(5%)   :              "<<(sum*0.05)<<" ₹"<<endl;
   cout<<"  Subtotal  :             "<<(sum + (sum)*0.05 )<<" ₹"<<endl;
   cout<<"************************************"<<endl;

   bill<<endl;
   bill<<"************************************"<<endl;
   bill<<"  Total     :               "<<sum<<" ₹"<<endl;
   bill<<"  Tax(5%)   :              "<<(sum*0.05)<<" ₹"<<endl;
   bill<<"  Subtotal  :             "<<(sum + (sum)*0.05 )<<" ₹"<<endl;
   bill<<"************************************"<<endl;




   




}