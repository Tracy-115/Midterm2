#include <iostream>
#include <fstream>
#include <ctime>
#include <string>
#include <cstdlib>
#include <vector>
using namespace std;

class DoublyLinkedList {
private:
    struct Node {
        string data;
        Node* prev;
        Node* next;
        Node(string val, Node* p = nullptr, Node* n = nullptr) {
            data = val;
            prev = p;
            next = n;
        }
    };

    Node* head;
    Node* tail;

public:
    DoublyLinkedList() { 
        head = nullptr; 
        tail = nullptr; 
    }

    bool empty(){
        return head == nullptr;
    }

    void push_back(string v) {
        Node* newNode = new Node(v);
        if (!tail)
            head = tail = newNode;
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void push_front(string v) {
        Node* newNode = new Node(v);
        if (!head)
            head = tail = newNode;
        else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void pop_front() {
        if (!head) {
            cout << "List is empty." << endl;
            return;
        }
        Node* temp = head;
        if (head->next) {
            head = head->next;
            head->prev = nullptr;
        } else
            head = tail = nullptr;
        delete temp;
    }

    void pop_back() {
        if (!tail) {
            cout << "List is empty." << endl;
            return;
        }
        Node* temp = tail;
        if (tail->prev) {
            tail = tail->prev;
            tail->next = nullptr;
        } else
            head = tail = nullptr;
        delete temp;
    }
    void randomPersonLeaving() {
        int count = 0;
        Node* temp=head;
        while (temp){
            count++;
            temp = temp->next;
        }
        if (count <=1 ){
            return;
        }
        int position = rand() % count;
        temp = head;
        for (int i = 0 ; i<position ; ++i){
            temp = temp->next;
        }
        cout  << temp -> data << " left the line" << endl;
        if(temp->prev){
            temp->prev->next = temp->next;
        }
        else {
            head = temp->next;
        }
        if(temp->next){
            temp->next->prev=temp->prev;
        }
        else{
            tail = temp->prev;
        }
        delete temp;
    }

    string start(){
        if (head){
            return head ->data;
        }
        return ""; //if it is empty, it returns an empty string
    }
    string end(){
        if (tail){
            return tail->data;
        }
        return "";
    }

    ~DoublyLinkedList() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void print() {
        Node* current = head;
        if (!current) {
            cout << "List is empty." << endl;
            return;
        }
        while (current) {
            cout << current->data << " " <<endl;
            current = current->next;
        }
        cout << endl;
    }

};

int main() {
    srand(time(0));
    DoublyLinkedList line;
    vector <string> names; //I am using a vector to store my names
    ifstream inFile("names.txt");
    string name;
    
    while (getline(inFile, name)){ //this is to see if the file is empty or not, and it is insering the names into the vector I created 
        names.push_back(name);
    }
    if (name.empty()){
        cout << "The file is empty" << endl;
        return 0;
    }
    inFile.close();

    cout<< "Shop Opens!!" << endl;
    
    for (int i = 0; i<5 ; ++i){
        string randName = names [rand() % names.size()]; //this is to choose random names
        cout << randName << " joined the line" << endl;
        line.push_back(randName);
    }
    cout << "\nCurrently in line: " << endl;
    line.print();

    for (int i = 2; i<=20; i++){
        cout << i << " minutes" << endl;
    int prob = rand() % 100 + 1;  // returns random number 1-100
        
    if (prob <= 40 && !line.empty()) {// perform Event A
        cout << line.start() << " is served" << endl;
        line.pop_front();
    }
    prob = rand() % 100 + 1;
    if (prob <= 60 && !line.empty()) {
        string randName = names [rand() % names.size()];
        cout << randName << " joins the line" << endl;
        line.push_back(randName);
    }
    prob = rand() % 100 + 1;
    if (prob <= 20 && !line.empty()) {
        cout << line.end() << " decided not to wait and left the line" << endl;
        line.pop_back();
    }
    prob = rand() % 100 + 1;
    if (prob <= 10 && !line.empty()) {
        line.randomPersonLeaving();
    }
    prob = rand() % 100 + 1;
    if (prob <= 10 && !line.empty()) {
        string VIP = names [rand() % names.size()];
        cout <<  VIP << " (VIP) joins the front of the line" << endl;
        line.push_front(VIP);
    }

        cout << "The shop's current listing: " << endl;
        line.print();
 /*In subsequent time periods, the probability of:
A customer being helped at the beginning of the line and ordering their coffee is 40%
A new customer joining the end of the line is 60%
The customer at the end of the line deciding they don't want to wait and leaving is 20%
Any particular customer can decide they don't want to wait and leave the line: 10%
A VIP (very important person) customer with a Coffee House Gold Card gets to skip the line and go straight to the counter and order: 10% */
    }
    return 0;
}
