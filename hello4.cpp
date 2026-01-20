#include<iostream>
#include<vector>
using namespace std;
struct Task{
    string name;
    bool completed;
};
void addTask(vector<Task> &tasks){
    Task t;
    cout<<"Enter task: ";
    cin.ignore();
    getline(cin, t.name);
    t.completed = false;
    tasks.push_back(t);
    cout<<"Task added successfully!\n";
}
void viewTasks(const vector<Task> &tasks){
    if(tasks.empty()) {
        cout<<"No tasks available.\n";
        return ;
    }
    cout<<"TO-DO-LIST"<<endl;
    for(int i=0;i<tasks.size();i++){
        cout<<i+1<<". "<<tasks[i].name;
        if(tasks[i].completed)
        cout<<" [Completed]\n";
        else
        cout<<" [Pending]\n";

    }   
}
void markCompleted(vector<Task> &tasks){
    int num;
    viewTasks(tasks);
    cout<<"Enter task number to mark as completed: ";
    cin>>num;
    if(num>0 && num<=tasks.size()){
        tasks[num-1].completed=true;
        cout<<"Task marked as completd!\n";
    }
    else{
        cout<<"Invalid task number.\n";
    }
}
void removeTask(vector<Task> &tasks){
    int num;
    viewTasks(tasks);
    cout<<"Enter task number to remove: ";
    cin>>num;
    if(num>0 && num<=tasks.size()){
        tasks.erase(tasks.begin() + num - 1);
        cout<<"Task removed successfully!\n";
    }
    else{
        cout<<"Invalid task number.\n";
    }
}
int main(){
    vector<Task> tasks;
    int choice;
    do{
        cout<<"TO-DO-LIST MENU"<<endl;
         cout<<"1. Add Task\n";
          cout<<"2. View Task\n";
           cout<<"3. Mark Task as Completed\n";
            cout<<"4. Remove Task\n";
             cout<<"5. Exit\n";
             cout<<"Enter your choice: ";
             cin>>choice;
             switch(choice){
                case 1: addTask(tasks); break;
                case 2: viewTasks(tasks); break;
                case 3: markCompleted(tasks); break;
                case 4: removeTask(tasks); break;
                case 5: cout<<"Exiting program...\n"; break;
                default: cout<<"Invalid choice!\n";
            
             } 
    }while(choice !=5 );
}