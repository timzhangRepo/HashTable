// Name:Tianchen Zhang
// USC NetID:tzhang03
// CSCI 455 PA5
// Fall 2019

/*
 * grades.cpp
 * A program to test the Table class.
 * How to run it:
 *      grades [hashSize]
 * 
 * the optional argument hashSize is the size of hash table to use.
 * if it's not given, the program uses default listSize (Table::HASH_SIZE)
 *./
 */

#include "Table.h"

// cstdlib needed for call to atoi
#include <cstdlib>

using namespace std;
//Insert name and score in the score table.
void put(Table * &grades, string name, int score);
//Lookup a name and print out its score, or message for name not found.
void contain(Table *&grades, string name);
//remove a student(name), print message iff student not found.
void remove(Table *&grades, string name);
//print out the number of entires or total number of students(name) in the tabel.
void getSize(Table *&grades);
//print out hashSize,numEntry,number of non-empty buckets, and the longest chain in the table.
void getStats(Table *&grades);
//change the score for a student(name), print iff the name is not found.
void change(Table *&grades, string name, int newScore);
//print out a brief command summary for help.
void getHelp();
//print out all names and scores in the table (not ordered)
//E.g.
//Tim 98
//Dave 88
//Mary 92
void print(Table *&grades);
//Ask for user what method to call, and break out iff the user typed "quit".
//checks for valid input, and print out error message if the user give command
//that is not recognized.
//E.g.
//cmd->lookup
//cmd->print
//must follow parameter order to enter the value.
//For example put(Table * &grades, string name, int score).
//Must type a string name and then hit enter, and then type a valid integer.
void console(Table *&grades);

int main(int argc, char * argv[]) {

   // gets the hash table listSize from the command line

   int hashSize = Table::HASH_SIZE;
   Table * grades;  // Table is dynamically allocated below, so we can call
   // different constructors depending on input from the user.

   if (argc > 1) {
      hashSize = atoi(argv[1]);  // atoi converts c-string to int
      if (hashSize < 1) {
         cout << "Command line argument (hashSize) must be a positive number" 
              << endl;
         return 1;
      }
      grades = new Table(hashSize);
   }
   else {   // no command line args given -- use default table listSize
      grades = new Table();
   }
    grades->hashStats(cout);

   // put more code here
   // Reminder: use -> when calling Table methods, since grades is type Table*
    console(grades);
}
void put(Table * &grades, string name, int score){
    int* flag = grades->lookup(name);
    if(flag==NULL){
        grades->insert(name,score);}
    else{
        cout<<"Student "<<name<<" "<<"is already present, and has score: "<<*flag<<endl;
    }
}
void change(Table *&grades, string name, int newScore){
    int* flag = grades->lookup(name);
    if(flag==NULL) {
        cout << "student " << name << " " << "is not present and can not make the change\n";
    }
    else{
        grades->remove(name);
        grades->insert(name, newScore);
    }
}
void contain(Table *&grades, string name){
    int* flag = grades->lookup(name);
    if(flag==NULL){
        cout<<"student "<<name<<" "<<"is not present\n";
    }else{
        cout<<"student "<<name<<" "<<"has score: "<<*flag<<endl;
    }
}
void remove(Table *&grades, string name){
    int* flag = grades->lookup(name);//check if name exists
    if(flag==NULL){
        cout<<"student "<<name<<" "<<"is not present\n";
    }else{
        grades->remove(name);
    }
}
void print(Table *&grades){
    grades->printAll();
}
void getSize(Table *&grades){
    cout<<"number of student entry: "<<grades->numEntries()<<endl;
}
void getStats(Table *&grades){
    grades->hashStats(cout);
}
void getHelp() {
    cout << "-------------------------SUMMARY-------------------------" << endl;
    cout << "---------------------------✿✿✿---------------------------" << endl;
    cout << "I:insert name score: type 'insert' to add a student " << endl;
    cout << "II:change name newscore: type 'change' to change a student with a new score" << endl;
    cout << "III:lookup name: type 'lookup' to lookup a student" << endl;
    cout << "IV:remove name: type 'remove' to remove a student" << endl;
    cout << "V:print: type 'print' to get all students and their scores" << endl;
    cout << "VI:size: type 'size' see the total number of students" << endl;
    cout << "VII:stats: type 'stats' to get the statistics about the table" << endl;
    cout << "VIII:help: type 'help' to see this summary again." << endl;
    cout << "IX:quit: type'quit' to exist the program" << endl;
    cout << "---------------------------✿✿✿-----------------------------" << endl;
    cout << "------------------------------------------------------------" << endl;
}
void console(Table *&grades){
    string action; //userinput,OR the method user wish to use.
    string name; //student name
    int score;//student score
    bool flag = true;
    cout<<"cmd>";
    cin>>action;
    while(flag)
    {
        if(action=="quit"){flag=false;break;}//double safety mechanism to breakout the loop.
        else if(action=="insert"){cin>>name;cin>>score;put(grades,name,score);}
        else if(action=="change"){cin>>name;cin>>score;change(grades,name,score);}
        else if(action=="lookup"){cin>>name;contain(grades,name);}
        else if(action=="remove"){cin>>name;remove(grades,name);}
        else if(action=="print"){print(grades);}
        else if(action=="size"){getSize(grades);}
        else if(action=="stats"){getStats(grades);}
        else if(action=="help"){getHelp();}
        else{cout<<"ERROR: invalid command\n";}
        cout<<"cmd>";
        action.clear();//clear out the string action for safety purpose.
        name.clear();//clear out the string name for safety purpose.
        cin>>action;
    }
}






