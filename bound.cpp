#include <iostream>
#include <list>
#include <iterator>
#include <cstring>
using namespace std;

struct bond{
    char name[32];	//bond name (e.g. NYC Water Authority)
    unsigned int maturity;		//maturity year
    float principal;
    float R;	//interest rate
};
struct node{
    char name[32];
    unsigned int frequency;
};
void msg(){
    cout << "enter operations" << endl;
    cout << "0.insert bond" << endl;
    cout << "1.Print all the bonds" << endl;
    cout << "2.Print all bonds in ascending order of their interest rate" << endl;
    cout << "3.Print the minimum and maximum principal values of the entire bond portfolio" << endl;
    cout << "4.print histogram" << endl;
    cout << "5.quit" << endl;
}

void print(list<bond>& l){
    cout << "================\n";
    for(list<bond>::iterator i = l.begin(); i != l.end(); i++){
        cout << "name:" << i->name << "maturity"<< i->maturity<<"principal"<<i->principal<<"R:"<<i->R<<endl;
    }
}

void insert_bond(list<bond>& l){
    bond temp;
    cout << "enter name:";
    cin >> temp.name;
    cout << "enter maturity";
    cin >> temp.maturity;
    cout << "enter principal";
    cin >> temp.principal;
    cout << "enter interest rate";
    cin >> temp.R;
    l.push_back(temp);
}

void print_min_max(list<bond>& l){
    float min = l.front().principal;
    float max = min;
    for(list<bond>::iterator i = l.begin(); i != l.end(); i++){
        min = i->principal < min ? i->principal : min;
        max = i->principal > max ? i->principal : max;
    }
    cout << "min:" << min << "\nmax:" << max << endl;
}
bool compare_R(const bond& first, const bond& second){
    return first.R < second.R;
}

void print_historg(list<bond>& l){}

void print_by_order(list<bond>& l){
    print(l);
    l.sort(compare_R);
    print(l);
}

void count_frequency(list<bond>& l, list<node> n){
    bool found = false;
    node temp_node;
    for(list<bond>::iterator i = l.begin(); i != l.end(); i++){
        found = false;
        for(list<node>::iterator j = n.begin(); j != n.end(); j++){
            if(strcmp(i->name, j->name) == 0){
                found = true;
                j->frequency += 1;
                break;
            }
        }
        if(!found){
            temp_node.frequency = 1;
            strcpy(temp_node.name, i->name);
            n.push_back(temp_node);
        }
    }
    for(list<node>::iterator j = n.begin(); j != n.end(); j++)
        cout << "name:"<< j->name << " freq" << j->frequency<< endl;
}

int main(){
    float min, max;
    bond temp_bond;
    list<bond> bond_list;
    list<node> frequency;
    int choice;
    bool quit = false;
    while(!quit){
        msg();
        cin >> choice;
        switch(choice){
            case 0:
                insert_bond(bond_list);
            break;
            case 1://Print all the bonds (with associated member data)
                print(bond_list);
            break;
            case 2://Print all bonds in ascending order of their interest rate
                print_by_order(bond_list);
            break;
            case 3://print min max principal values
                print_min_max(bond_list);
            break;
            case 4://5 element histogram
                print_historg(bond_list);
            break;
            case 5:{
                quit = true;
                cout << "bye~";
            }
            break;
            case 6:
                count_frequency(bond_list, frequency);
            break;
        }


    }
    

    return 0;
}
/*
o	Provide a count of how many bonds in your portfolio have the same name (e.g. NYC Water Authority, etc) 
	You will need to provide a second list container that contains nodes having unique names and frequency count
o	Print all the bonds (with associated member data)
o	Print all bonds in ascending order of their interest rate
o	Print the minimum and maximum principal values of the entire bond portfolio
o	Take the range of bond principals and create a 5 element histogram array that indicates how many bonds fall within each slot value
o	The Bond Names should be one of these candidates:
    NYC Water Authority
    Nuveen High Yield Municipal
    Delaware National High Yield
    Lord Abbett High Yield
    BNY Mellon High Yield
    PIMCO High Yield Municipal

*/
