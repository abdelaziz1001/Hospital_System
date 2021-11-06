

#include <iostream>
#include <vector>
#include <deque>
#include <string>

using namespace std;

/*--------------------------------*/
string P_name;
int spec;
bool stat;
pair<string, string> x;
vector<deque<pair<string, string>>> pat_List(21);

void print_pair(pair<string, string> p){
    cout << p.first << " " << p.second << "\n";
}
/*--------------------------------*/

void menu(){
    cout << "Enter your choice:\n"
         << "1) Add New Patient\n"
         << "2) Print All Patients\n"
         << "3) Get Next Patient\n"
         << "4) Exit\n"
         << "=> ";
}

void NewPatient(){
    cout << "Enter specialization, name, statis: ";
    cin >> spec >> P_name >> stat;
    x.first = P_name;
    if(pat_List[spec].size() > 5){
        cout << "Sorry, we can't add more patients for this specialization\n";
    }
    else if(stat){
        x.second = "urgent";
        pat_List[spec].push_front(x);
    }
    else{
        x.second = "regular";
        pat_List[spec].push_back(x);
    }
    cout << "\n\n";
}

void PrintAllPatients(){

    for(int i = 1; i <= 20; i++){
        if(!pat_List[i].empty()){
            cout << "*******************************\n\n";
            cout << "There are " << pat_List[i].size() << " patient in specialization " << i << "\n";

        }
        while(!pat_List[i].empty()){
            print_pair(pat_List[i].front());
            pat_List[i].pop_front();
        }
    }
    cout << "\n*******************************\n\n";
}

void GetNextPatient(){
    cout << "Enter specialization: ";
    cin >> spec;
    if(!pat_List[spec].empty()){
        cout << pat_List[spec].front().first << " please go to the Dr\n";
        pat_List[spec].pop_front();
    }
    else{
        cout << "we don't have Patients\n";
    }
    cout << "\n\n";
}

int main()
{
    int ch;

    do{
        menu();
        cin >> ch;
        if(ch == 1)
            NewPatient();
        else if(ch == 2)
            PrintAllPatients();
        else if(ch == 3)
            GetNextPatient();

    }while(ch != 4);

    return 0;
}
