#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <algorithm>
#include <list>
#include<iomanip>
using namespace std;

struct Request
{
    string name;
    int priority;

    Request(const string& n, int p) : name(n), priority(p) {}
};

// Custom comparator function to compare Request objects based on priority
struct ComparePriority
{
    bool operator()(const Request& req1, const Request& req2)
    {
        return req1.priority > req2.priority; // Higher priority value means higher priority
    }
};

class node
{
public:
    node* lchild, * rchild;
    int price, stock,order;
    string title, author;
    node* next;
    node* tree_node_ref;

    node(string t, string a, int p, int s)
    {
        lchild = NULL;
        rchild = NULL;
        tree_node_ref = NULL;
        price = p;
        title = t;
        author = a;
        stock = s;
        next = NULL;
    }
};

class linked_list {
public:
    node* head;
    linked_list() {
        head = NULL;

    }

    void insert(node* temp) {
        if (head == NULL) {
            head = temp;
            temp->next = NULL;
        }
        else {
            temp->next = head;
            head = temp;
        }
    }

    void traverse() {
        node* current = head;
        cout << left << setw(30) << "Title"
            << setw(20) << "Author"
            << right << setw(10) << "Price" << endl;

        // Print separator line
        cout << setfill('-') << setw(60) << "" << std::setfill(' ') << endl;
        while (current != NULL) {
            //cout << current->title << "\t" << current->author << "\t" << current->price << endl;
            cout << left << setw(30) << current->title
                << setw(20) << current->author
                << right << setw(10) << fixed << setprecision(2) << current->price << endl;
            current = current->next;

        }
        cout << endl;
    }

    void del(string t) {
        node* current = head;
        node* temp = head;
        if (current->title == t) {
            head = current->next;
            current->tree_node_ref->stock = current->tree_node_ref->stock + current->order;
            cout << current->stock;
            delete current;
            return;
        }
        current = current->next;

        while (current != NULL) {
            if (current->title == t) {
                temp->next = current->next;
                //current->stock = current->stock + current->order;
                current->tree_node_ref->stock = current->tree_node_ref->stock + current->order;
                delete current;
                return;
            }
            else {
                current = current->next;
                temp = temp->next;
            }
        }
    }

    void receipt() {
        int total = 0;
        int p = 0;;
        cout << "YOUR FINAL RECEIPT IS" << endl;
        traverse();
        cout << "YOUR PAYMENT IS: ";
        node* current = head;
        while (current != NULL) {
            p = current->price * current->order;
            total = total + p;
            current = current->next;
        }
        cout << "RS. " << total << endl;
    }

};

class book
{
public:
    node* root_title;
    node* root_price;
    stack<node*> price;
    stack<node*> title;
    linked_list l1;

    book()
    {
        root_title = NULL;
        root_price = NULL;
    }

    void price_hl(node* current) //function to push into the stack
        //it pushes inorder traversal of tree which is based on price 
    {
        if (current == NULL)
        {
            return;
        }
        price_hl(current->lchild);
        price.push(current);
        price_hl(current->rchild);
    }

    void title_hl(node* current) // function to push into the stack
        //it pushes inorder traversal of tree which is based on title 
    {
        if (current == NULL)
        {
            return;
        }
        title_hl(current->lchild);
        title.push(current);
        title_hl(current->rchild);
    }

    void print_price_hl() //pops out the elements from stack and prints the book's information according to price(high to low)
    {
        node* current;
        cout << left << setw(30) << "Title"
            << setw(20) << "Author"
            << right <<setw(10) << "Price" << endl;

        // Print separator line
        cout << setfill('-') << setw(60) << "" << std::setfill(' ') <<endl;
        while (!price.empty())
        {
            current = price.top();
            price.pop();
            //cout << current->title << "\t" << current->author << "\t" << current->price << endl;
            cout <<left <<setw(30) << current->title
                << setw(20) << current->author
                << right << setw(10) <<fixed << setprecision(2) << current->price <<endl;
        }
    }

    void print_title_hl()   //pops out the elements from stack and prints the book's information according to title(high to low)
    {
        node* current;
        cout << left << setw(30) << "Title"
            << setw(20) << "Author"
            << right << setw(10) << "Price" << endl;

        // Print separator line
        cout << setfill('-') << setw(60) << "" <<setfill(' ') << endl;
        while (!title.empty())
        {
            current = title.top();
            title.pop();
            //cout << current->title << "\t" << current->author << "\t" << current->price << endl;
            cout << left << setw(30) << current->title
                << setw(20) << current->author
                << right << setw(10) << fixed << setprecision(2) << current->price << endl;
        }
    }

    void insert_price(string t, string a, int p, int s) // BST for book information according to price
    {
        node* new_node = new node(t, a, p, s);
        if (root_price == NULL)
        {
            root_price = new_node;
            return;
        }

        node* current = root_price;
        node* temp = root_price;
        while (current != NULL)
        {
            temp = current;
            if (current->price > new_node->price)
            {
                current = current->lchild;
            }
            else
            {
                current = current->rchild;
            }
        }
        if (new_node->price < temp->price)
        {
            temp->lchild = new_node;
        }
        else
        {
            temp->rchild = new_node;
        }
    }

    void insert_title(string t, string a, int p, int s) // BST for book information according to title
    {
        node* new_node = new node(t, a, p, s);
        if (root_title == NULL)
        {
            root_title = new_node;
            return;
        }

        node* current = root_title;
        node* temp = root_title;
        while (current != NULL)
        {
            temp = current;
            if (current->title > new_node->title)
            {
                current = current->lchild;
            }
            else
            {
                current = current->rchild;
            }
        }
        if (new_node->title < temp->title)
        {
            temp->lchild = new_node;
        }
        else
        {
            temp->rchild = new_node;
        }
    }

    void search() {  //search the book if it is present in the list or not.if it is then print the details of that book
        cin.ignore();
        cout << "enter the book you want to search" << endl;
        string t;
        getline(cin, t);
        node* current = root_title;
        while (current != NULL) {
            if (current->title == t) {
                cout << "BOOK is available.the details are:\n";
                cout << current->title << "\t" << current->author << "\t" << current->price << endl;
                return;
            }
            if (current->title > t) {
                current = current->lchild;
            }
            else {
                current = current->rchild;
            }
        }
        cout << t << " is not available" << endl;
    }

    void addtocart() { //add book into the cart
        cin.ignore();
        cout << "enter the book you want to add in cart" << endl;
        string t;
        getline(cin, t);
        cout << "enter the number if books you want to buy" << endl;
        int n;
        cin >> n;
        node* current = root_title;

        while (current != NULL) {
            if (current->title == t) {

                if (n > current->stock) {
                    cout << "the store have only " << current->stock << " book(s)" << endl;
                    return;
                }
                current->stock = current->stock - n;
                cout << current->stock;
                //current->order = n;
                node* cart_node = new node(current->title,current->author,current->price,current->stock);
                cart_node->order = n;
                cart_node->tree_node_ref = current;
                l1.insert(cart_node);
                
                return;
            }
            if (current->title > t) {
                current = current->lchild;
            }
            else {
                current = current->rchild;
            }
        }
        cout << t << " is not available" << endl;
        getline(cin, t);

    }

    void viewcart() { //views the cart that which book are added into the cart
        l1.traverse();
    }

    void removefromcart() { //removes book from the cart if user wants to remove it after adding it into the cart
        cin.ignore();
        cout << "enter the book you want to remove from cart" << endl;
        string t;
        getline(cin, t);
        l1.del(t);
    }

    void checkout() {
        l1.receipt();
    }

    void inorder(node* current) //prints the book's details in low to high manner according to price and title
    {
        
        if (current == NULL)
        {
            return;
        }

        inorder(current->lchild);
        //cout << current->title << "\t" << current->author << "\t" << current->price << endl;
        cout << left << setw(30) << current->title
            << setw(20) << current->author
            << right << setw(10) << fixed << setprecision(2) << current->price << endl;
        inorder(current->rchild);
    }
};

class Payment
{
private:
    long int cardnumber;
    int CVV;
    int mobilenumber;

public:
    string name, address, email, card_name;

    void set_name(string n)
    {
        name = n;
    }
    void set_address(string a)
    {
        address = a;
    }
    void set_email(string em)
    {
        email = em;
    }
    void set_Cname(string c_name)
    {
        card_name = c_name;
    }
    void set_Cnumber(long int cnum)
    {
        cardnumber = cnum;
    }
    void set_CVV(int cvv)
    {
        CVV = cvv;
    }
    void set_Mnumber(int mnum)
    {
        mobilenumber = mnum;
    }

    string get_name() { return name; }
    string get_address() { return address; }
    string get_email() { return email; }
    string get_Cname() { return card_name; }
    long int get_Cnum() { return cardnumber; }
    int get_CVV() { return CVV; }
    int get_mobno() { return mobilenumber; }

   /* void Personal_Info()
    {
        string na, addr, ema;
        int mo_num;
        cout << "Name : ";
        cin >> na;
        set_name(na);
        cout << endl
            << "Address : ";
        cin >> addr;
        set_address(addr);
        cout << endl
            << "Email ID : ";
        cin >> ema;
        set_email(ema);
        cout << endl
            << "Mobile Number : ";
        cin >> mo_num;
        set_Mnumber(mo_num);
    }

    void Payment_method()
    {
        int option;
        string cname;
        int cv_v;
        long int c_num;
        cout << "1) Credit/Debit Card " << endl;
        cout << "2) Cash on delivery " << endl;
        cout << "Option : ";

        do
        {
            cin >> option;
            switch (option)
            {
            case 1:
                cout << "Please enter your card information ";
                cout << endl
                    << "Card Name : ";
                cin >> cname;
                set_Cname(cname);
                cout << endl
                    << "Card number : ";
                cin >> c_num;
                set_Cnumber(c_num);
                cout << endl
                    << "CVV : ";
                cin >> cv_v;
                set_CVV(cv_v);
                break;
            case 2:
                cout << "Your order is confirmed for delivery. Please pay the amount at the time of delivery.";
                break;
            default:
                break;
            }
            if (option != 1)
            {
                cout << "\nPress Enter to return to the Payment menu...";
                cin.ignore();
                cin.get();
                system("cls");
            }
        } while (option != 1);
    }
    void display_info()
    {
        cout << "Your personal Information is displayed below \n\n";
        cout << "Name : " << get_Cname() << endl;
        cout << "Address : " << get_address() << endl;
        cout << "Phone Number : " << get_mobno() << endl;
        cout << "Email ID : " << get_email() << endl;

        cout << "Card Number : " << get_Cnum() << endl;
        cout << "Card Name : " << get_Cname() << endl;
        cout << "CVV : " << get_CVV() << endl;
    }*/





    /*void clearInputBuffer() {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }*/

    void Personal_Info() {
        string na, addr, ema;
        long long mo_num;  // Using long long for larger mobile numbers

        cout << "Name: ";
        getline(cin >> ws, na);  // Read input with spaces
        set_name(na);

        cout << "Address: ";
        getline(cin, addr);
        set_address(addr);

        cout << "Email ID: ";
        cin >> ema;
        set_email(ema);

        while (true) {
            cout << "Mobile Number: ";
            if (cin >> mo_num && to_string(mo_num).length() == 10) {
                set_Mnumber(mo_num);
                break;
            }
            else {
                cout << "Invalid mobile number. Please enter a 10-digit number.\n";
                //clearInputBuffer();
            }
        }
    }

    void Payment_method() {
        int option;
        string cname;
        int cv_v;
        long long c_num;

        while (true) {
            cout << "\nSelect Payment Method:\n";
            cout << "1) Credit/Debit Card\n";
            cout << "2) Cash on Delivery\n";
            cout << "Option: ";
            cin >> option;

            if (option == 1) {
                cout << "\nEnter Card Information:\n";

                cout << "Card Name: ";
                cin.ignore();  // Clear buffer for getline
                getline(cin, cname);
                set_Cname(cname);

                while (true) {
                    cout << "Card Number (16 digits): ";
                    if (cin >> c_num && to_string(c_num).length() == 16) {
                        set_Cnumber(c_num);
                        break;
                    }
                    else {
                        cout << "Invalid card number. Please enter a 16-digit number.\n";
                        //clearInputBuffer();
                    }
                }

                while (true) {
                    cout << "CVV (3 digits): ";
                    if (cin >> cv_v && to_string(cv_v).length() == 3) {
                        set_CVV(cv_v);
                        break;
                    }
                    else {
                        cout << "Invalid CVV. Please enter a 3-digit number.\n";
                       // clearInputBuffer();
                    }
                }
                display_info();

                cout << "Payment confirmed successfully.\n";
                break;

            }
            else if (option == 2) {
                cout << "Order confirmed for delivery. Please pay upon delivery.\n";
                break;
            }
            else {
                cout << "Invalid option. Please choose again.\n";
                //clearInputBuffer();
            }
        }
    }

    //void display_info() {
    //    cout << "\nYour Personal Information:\n";
    //    cout << "Name: " << get_Cname() << "\n";
    //    cout << "Address: " << get_address() << "\n";
    //    cout << "Phone Number: " << get_mobno() << "\n";
    //    cout << "Email ID: " << get_email() << "\n";

    //    cout << "\nCard Information:\n";
    //    //string masked_card = string(12, '*') + to_string(get_Cnum()).substr(12);
    //    cout << "Card Number: " << masked_card << "\n";
    //    cout << "Card Name: " << get_Cname() << "\n";
    //    cout << "CVV: *** (Hidden for security)\n";
    //}


    void display_info()
    {
        cout << "Your personal Information is displayed below \n\n";
        cout << "Name : " << get_Cname() << endl;
        cout << "Address : " << get_address() << endl;
        cout << "Phone Number : " << get_mobno() << endl;
        cout << "Email ID : " << get_email() << endl;

        cout << "Card Number : " << get_Cnum() << endl;
        cout << "Card Name : " << get_Cname() << endl;
        cout << "CVV : " << get_CVV() << endl;
    }

};

class Login_admin
{
    string admin_ID, password;

public:
    string get_adminid() { return admin_ID; }
    void set_adminid(string id) { admin_ID = id; }
    string get_passwd() { return password; }
    void set_passwd(string pw) { password = pw; }

    void ask_info()
    {
        string aID, PW;
        cout << "Admin ID ";
        cin >> aID;
        set_adminid(aID);
        cout << endl
            << "Password ";
        cin >> PW;
        set_passwd(PW);

        bool check = login_check(aID, PW);

        if (!check)
        {
            cout << "\nInvalid Username or Password!! Try Again." << endl;
            exit(0);
        }
        else
        {
            cout << "\nWelcome Admin!!" << endl;

        }
    }

    bool login_check(string id, string pword)
    {
        if (((id == "22k-4561") || (id == "22k-4164")) && ((pword == "rayyan") || (pword == "kashan")))
        {
            return true;
        }
        return false;
    }
    void emptypricestack(book& myobj) {
        node* current;
        while (!myobj.price.empty())
        {
            current = myobj.price.top();
            myobj.price.pop();
        }

    }

    void emptytitlestack(book& myobj) {
        node* current;
        while (!myobj.title.empty())
        {
            current = myobj.title.top();
            myobj.title.pop();
        }

    }


    void add_book(book& myobj) {
        string t, a;
        int p, s;
        cout << "enter book title:" << endl;
        cin.ignore();
        getline(cin, t);
        cout << "enter book author:" << endl;
        cin.ignore();
        getline(cin, a);
        cout << "enter book price" << endl;
        cin >> p;
        cout << "enter book stock" << endl;
        cin >> s;
        myobj.insert_price(t, a, p, s);
        myobj.insert_title(t, a, p, s);
        emptypricestack(myobj);
        emptytitlestack(myobj);
        myobj.price_hl(myobj.root_price);
        myobj.title_hl(myobj.root_title);
    }
};


void Store_info()
{
    string store_name, store_add, store_phone, store_email;
    cout << "Store Information \n\n";
    cout << "Address : Saddar, Karachi \n";
    cout << "Contact Details : +923014567890 \n";
    cout << "Instagram : read_online \n";
}
int main()
{
    int choice;
    list<string> bookname;
    priority_queue<Request, vector<Request>, ComparePriority> customer_support;
    Payment pay;
    Login_admin LA;

    book b;

    b.insert_price("gulliver Travels", "jonathon swift", 1800, 2);
    b.insert_price("The Hobbit", "J.R.R. Tolkien", 2200, 5);
    b.insert_price("Great Expectations", "Charles Dickens", 2000, 4);
    b.insert_price("Brave New World", "Aldous Huxley", 2400, 3);
    b.insert_price("Fahrenheit 451", "Ray Bradbury", 2100, 6);
    b.insert_price("Animal Farm", "George Orwell", 1900, 7);
    b.insert_price("Treasure Island", "Charles Dickens", 2700, 11);

    b.insert_title("Gulliver Travels", "jonathon swift", 1800, 2);
    b.insert_title("The Hobbit", "J.R.R. Tolkien", 2200, 5);
    b.insert_title("Great Expectations", "charles Dickens", 2000, 4);
    b.insert_title("Brave New World", "Aldous Huxley", 2400, 3);
    b.insert_title("Fahrenheit 451", "Ray Bradbury", 2100, 6);
    b.insert_title("Animal Farm", "George Orwell", 1900, 7);
    b.insert_title("Treasure Island", "Charles Dickens", 2700, 11);

    b.price_hl(b.root_price);
    b.title_hl(b.root_title);



    do
    {

        cout << "\nRead Online Bookstore" << endl
            << endl;
        cout << "_______________________________________________" << endl;
        cout << "Menu:" << endl;
        cout << "1) Book List " << endl;
        cout << "2) Search " << endl;
        cout << "3) Cart " << endl;
        cout << "4) Login " << endl;
        cout << "5) Customer support " << endl;
        cout << "6) Store information " << endl;
        cout << "7) Exit " << endl;
        cout << "_______________________________________________" << endl;
        cout << "\nEnter your option : ";

        cin >> choice;
        switch (choice)
        {

        case 1:
            system("cls");
            cout << "Book List " << endl;
            int Book_option;

            do
            {
                cout << "1) Price (high - low) " << endl;
                cout << "2) Price (low - high) " << endl;
                cout << "3) Title (high - low) " << endl;
                cout << "4) Title (low - high) " << endl;
                cout << "5) Exit " << endl;
                cout << "Enter the filter : ";

                cin >> Book_option;
               //cin.ignore(numeric_limits<streamsize>::max(), '\n');
                switch (Book_option)
                {
                case 1:
                    system("cls");
                    cout << "Price (high - low)" << endl;
                    cout << endl;
                    b.print_price_hl();
                    b.price_hl(b.root_price);  //this is the change i made after project evaluation.now the user 
                    //can repeatedly see book's details according to price (high to low).
                    break;
                case 2:
                    system("cls");
                    cout << "Price (low - high) " << endl << endl;
                    cout << left << setw(30) << "Title"
                        << setw(20) << "Author"
                        << right << setw(10) << "Price" << endl;

                    // Print separator line
                    cout << setfill('-') << setw(60) << "" << std::setfill(' ') << endl;
                    b.inorder(b.root_price);
                    break;
                case 3:
                    system("cls");
                    cout << "Title (high - low) " << endl << endl;
                    b.print_title_hl();
                    b.title_hl(b.root_title);  //this is the change i made after project evaluation.now the user 
                    //can repeatedly see book's details according to title (high to low).
                    break;
                case 4:
                    system("cls");
                    cout << "Title (low - high) " << endl << endl;
                    cout << left << setw(30) << "Title"
                        << setw(20) << "Author"
                        << right << setw(10) << "Price" << endl;

                    // Print separator line
                    cout << setfill('-') << setw(60) << "" << std::setfill(' ') << endl;
                    b.inorder(b.root_title);
                    break;
                case 5:
                    break;

                default:
                    cout << "invalid option " << endl;
                    break;
                }
                if (Book_option != 5)
                {
                    cout << "\nPress Enter to return to the book list menu...";
                    cin.ignore();
                    cin.get();
                    system("cls");
                }
            } while (Book_option != 5);
            break;
        case 2:
            system("cls");
            cout << "Search " << endl
                << endl;
            b.search();

            break;
        case 3:
            system("cls");
            cout << "Cart " << endl
                << endl;
            int Cart_option;

            do
            {
                cout << "1) View Cart " << endl;
                cout << "2) Add to cart " << endl;
                cout << "3) Remove from cart " << endl;
                cout << "4) Checkout " << endl;
                cout << "5) Exit " << endl;
                cout << "Enter your option : ";

                cin >> Cart_option;
                switch (Cart_option)
                {
                case 1:
                    system("cls");
                    cout << "Viewing the cart..." << endl;
                    b.viewcart();
                    break;
                case 2:
                    system("cls");
                    cout << "Adding to the cart " << endl;
                    b.addtocart();
                    break;
                case 3:
                    system("cls");
                    cout << "Removing from the cart " << endl;
                    b.removefromcart();
                    break;

                
                case 4:
                    system("cls");
                    cout << "Checkout " << endl;
                    b.checkout();
                    pay.Personal_Info();
                    pay.Payment_method();
                    //cout << "Your ordered will be deliver within 5 working days" << endl;
                    break;
                case 5:
                    break;

                default:
                    cout << "invalid option " << endl;
                    break;
                }
                /*if (Cart_option != 1 && Cart_option != 2 && Cart_option != 3 && Cart_option != 4 && Cart_option != 5) {
                    cout << "invalid option " << endl;
                }*/
                /*if (Cart_option != 5)
                {
                    cout << "\nPress Enter to return to the Cart menu...";
                    cin.ignore();
                    cin.get();
                    system("cls");
                }*/
                if (Cart_option != 5)
                {
                    cout << "\nPress Enter to return to the Cart menu...";
                    cin.ignore();
                    //cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear input buffer
                    cin.get();  // Pause for Enter key
                    system("cls");
                }
            } while (Cart_option != 5);

            break;
        case 4:
            system("cls");
            cout << "Login " << endl
                << endl;
            int Login_option;
            do
            {
                cout << "Log-in as : " << endl;
                cout << "1) Administrator " << endl;

                cout << "Select option ";

                cin >> Login_option;
                switch (Login_option)
                {
                case 1:
                    LA.ask_info();

                    break;

                default:
                    cout << "Enter a valid option " << endl;
                    break;
                }

            } while (Login_option != 1);
            LA.add_book(b);

            break;
        case 5:
            system("cls");
            cout << "Customer support " << endl;

            customer_support.push(Request("Issue with login", 3));
            customer_support.push(Request("Book recommendation - Fantasy", 1));
            customer_support.push(Request("Complaint about product", 2));
            customer_support.push(Request("Technical assistance", 4));

            while (!customer_support.empty())
            {
                Request currentRequest = customer_support.top();
                cout << "Processing: " << currentRequest.name << " (Priority # : " << currentRequest.priority << ")" << endl;
                customer_support.pop();
            }
            break;
        case 6:
            system("cls");
            cout << "Store information " << endl
                << endl;
            Store_info();

            break;
        case 7:
            system("cls");
            cout << "Exiting ... " << endl;

            break;

        default:
            system("cls");
            cout << "Invalid choice \nPlease enter a valid choice " << endl;
            break;
        }

        if (choice != 7)
        {
            cout << "\nPress Enter to return to the menu...";
            cin.ignore();
            cin.get();
            system("cls");
        }

    } while (choice != 7);

    return 0;
}
