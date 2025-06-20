#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class menu
{
    public:

    string input[20]; // 3rd index se items lena start kar dega  and last deta 13 tak milega 

    

};


int main()
{   
    int place=0;
    /* class se object create karna */
    menu dish;

    /* menu print karwana */

    string sabzi;


    ifstream menu; // creating an object 
    ofstream bill;

    menu.open("menu.txt");
    bill.open("bill.txt");

    menu>>sabzi;

    getline(menu, sabzi);
    
    while(menu.eof()==0)
    {
        getline(menu, sabzi);
        cout<<sabzi<<endl;
        dish.input[place] = sabzi;
        place++;
        
    }

    



    // cout<<dish.input[5];

    /* user se input lena hai */

    int k=1;
    int arr[12];
    
    cout<<" \n PLEASE ENTER YOUR CHOICES: \n...... ENTER 0 FOR CONFORMATION.....\n";

    for(int i=0; i<12; i++)
    {
        if(k != 0)
        {
           cin>>k;
           arr[i]=k;
        }
        else {
            break;
        }

    }

    cout<<" THANKYOU sir, we preparing your order "<<endl;

       
    /* calculations */


    int sum = 0;

    for(int i=0; i<12; i++)

    {

      switch(arr[i])  

        {
        
              case 1 : sum = sum+100; break;
              case 2 : sum = sum+100; break;
              case 3 : sum = sum+100; break;
              case 4 : sum = sum+100; break;
              case 5 : sum = sum+100; break;
              case 6 : sum = sum+100; break;
              case 7 : sum = sum+100; break;
              case 8 : sum = sum+100; break;
              case 9 : sum = sum+100; break;
              case 10 : sum = sum+100; break;
              case 11 : sum = sum+  7; break;
              case 12 : sum = sum+100; break; 

        }
      

    }

    
    

    /* order summery and billing */

    bill<<" ******** BILL WITH ALL DETAILS *********\n\n\n";

    for(int i=0; i<11; i++)


    {

      switch(arr[i])  

        {
        
              case 1 : bill<<dish.input[3]<<endl;   break;
              case 2 : bill<<dish.input[4]<<endl;   break;
              case 3 : bill<<dish.input[5]<<endl;   break;
              case 4 : bill<<dish.input[6]<<endl;   break;
              case 5 : bill<<dish.input[7]<<endl;   break;
              case 6 : bill<<dish.input[8]<<endl;   break;
              case 7 : bill<<dish.input[9]<<endl;   break;
              case 8 : bill<<dish.input[10]<<endl;  break;
              case 9 : bill<<dish.input[11]<<endl;  break;
              case 10 : bill<<dish.input[12]<<endl; break;
              case 11 : bill<<dish.input[13]<<endl;          
            

    }


    }
           
    bill<<"\n     Subtotal :                     "<<sum<<" ₹"<<endl;
    bill<<"     tax(5%)  :                      "<<sum*0.05<<" ₹"<<endl;
    bill<<" total Amount :                     "<<(sum + sum*0.05)<<" ₹"<<endl;

     return 0;







}