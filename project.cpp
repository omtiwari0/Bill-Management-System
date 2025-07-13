#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class menu
{
public:
    int id;
    int price;
    string name;

    void get_data()
    {
        cout << "enter dish_id : ";
        cin >> id;

        cin.ignore();

        cout << "enter dish_name : ";
        cin >> name;

        cout << "enter dish_price : ";
        cin >> price;
        cout << endl;
    }
};

void Add_item()

{
    int dish_price;
    int dish_id;
    string add;
    string dish_name;

    ofstream write_menu("menu.txt", ios::app); /// can be use for write in menu ///

    vector<menu> dish;

    int n;
    cout << "How many dishes you want to enter : ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        menu d;
        d.get_data();

        dish.push_back(d);

        write_menu << dish[i].id << "." << dish[i].name << "     " << dish[i].price << " ₹\n";
    }
}

void menu_display()
{

    ifstream menu;
    menu.open("menu.txt");

    /********************Menu Opening******************/

    while (menu.eof() == 0)
    {
        string line;
        getline(menu, line);
        cout << line << endl;
    }
}

int main()
{
    /*******************************DECLARATION & initilization***************************/

    vector<menu> dish; //
    vector<int> order;

    int option, pass, edt_optn;

    /* Read menu.txt file and get1 all necessary details */

    string t1, t2, name;
    int id, price;

    ifstream read_menu;
    read_menu.open("menu.txt");

    /* In case if menu.txt is not present */

    if (!read_menu)
    {
        ofstream newFile("menu.txt");
        newFile << "1.tea     15 ₹" << endl;
    }

    string line;

    while (read_menu.eof() == 0)
    {

        getline(read_menu, line);

        stringstream ss(line);
        ss >> t1;
        ss >> t2;

        size_t dot_pos = t1.find('.');

        id = stoi(t1.substr(0, dot_pos));

        name = t1.substr(dot_pos + 1, t1.length());

        price = stoi(t2);

        menu d;
        d.id = id;
        d.name = name;
        d.price = price;

        dish.push_back(d);
    }

    /////////////////////////////////////////////////////////////////////////////////////////////////////

    

    cout << "1) customer " << endl;
    cout << "2) Employee " << endl;
    cout << "3) Exit    " << endl;

    cout << "\nPlease choose your option : ";
    cin >> option;

    /**********************FOR CUSTMER******************************/

    if (option == 1)
    {
        /////////////// Menu Opening ///////////////////

        menu_display();

        /****************Taking Order********************/

        cout << "please enter dish id and for conformation enter 0 : " << endl;

        while (1)
        {
            int n;
            cin >> n;
            if (n == 0)
            {
                break;
            }

            order.push_back(n);
        }

        cout << "thankyou sir, We are prepare your order " << endl;

        //////// Bill calculation /////////////////

        float sum = 0;
        int length = order.size();

        for (int i = 0; i < length; i++)
        {
            sum = sum + dish[order.at(i) - 1].price;
        }

        ofstream bill;
        bill.open("bill.txt");

        for (int i = 0; i < length; i++)
        {
            bill << dish[order.at(i) - 1].id;
            bill << ".";
            bill << dish[order.at(i) - 1].name;
            bill << "      ";
            bill << dish[order.at(i) - 1].price << " ₹\n";

            cout << dish[order.at(i) - 1].id;
            cout << ".";
            cout << dish[order.at(i) - 1].name;
            cout << "      ";
            cout << dish[order.at(i) - 1].price << " ₹\n";
        }

        bill << "*******************\n";

        bill << "total                " << sum << " ₹" << endl;
        bill << "tax                  5%" << endl;
        bill << "subtotal             " << sum + 0.05 * sum << " ₹" << endl;

        cout << "*******************\n";

        cout << "total                " << sum << endl;
        cout << "tax                  5%" << endl;
        cout << "subtotal             " << sum + 0.05 * sum << endl;
    }

    //////////////////////////////// FOR Employee ////////////////////////////////

    else if (option == 2)
    {
        while (1)
        {
            cout << "please enter your password : ";
            cin >> pass;

            if (pass == 1234)
            {
                cout << "1. Add items" << endl;
                cout << "2. Remove items" << endl;
                cout << "3. Edit price" << endl;
                cout << "4. Exit" << endl;

                cin >> edt_optn;

                int lnth = dish.size();

                int edt_id, newPrice;
                int dish_lenght = dish.size();

                switch (edt_optn)
                {

                case 1:
                    Add_item();
                    break;
                case 2:
                {
                    ofstream edt;
                    edt.open("menu.txt");
                    for (int i = 0; i < dish_lenght-1; i++)
                    {
                        cout << dish[i].id << "." << dish[i].name << "                                               " << dish[i].price << " ₹" << endl;
                    }

                    int choice;
                    cout << "Enter your dish Id : ";
                    cin >> choice;

                    for (int i = choice - 1; i < lnth - 1; i++)
                    {
                        dish[i].name = dish[i + 1].name;
                        dish[i].price = dish[i + 1].price;
                    }

                    for (int i = 0; i < lnth - 2; i++)
                    {
                        edt << dish[i].id << "." << dish[i].name << "                         " << dish[i].price << " rps " << endl;
                    }
                }

                break;
                case 3:
                {
                    ofstream edt;
                    edt.open("menu.txt");
                    // menu_display();
                    for (int i = 0; i < dish_lenght-1; i++)
                    {
                        cout << dish[i].id << "." << dish[i].name << "                                               " << dish[i].price << " ₹" << endl;
                    }

                    cout << "Enter your Dish_ID: ";
                    cin >> edt_id;

                    for (int i = 0; i < lnth; i++)
                    {

                        if (edt_id == dish[i].id)
                        {

                            cout << "Enter new price : ";
                            cin >> newPrice;
                            dish[i].price = newPrice;
                            // edt << dish[i].id << "." << dish[i].name << "     " << dish[i].price << endl;
                        }
                        else if (edt_id == 0)
                        {
                            break;
                        }
                    }

                    for (int i = 0; i < lnth-1; i++)
                    {
                        edt << dish[i].id << "." << dish[i].name << "                         " << dish[i].price << " rps " << endl;
                    }

                    break;
                }
                case 4:
                    break;

                default:
                    cout << "you have entered invalid number !!!!" << endl;
                    break;
                }

                break;
            }

            else
            {
                cout << "!!!!!!!!!! You entered wrong password !!!!!!!!!!!!" << endl;
            }
        }
    }
    else if (option == 3)
    {
        cout << "you are successfully exit.... \n";
    }
    else
    {
        cout << "please enter valid number!!!!!\n";
    }
}
