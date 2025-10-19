#include <iostream>
#include <fstream>
#include <ctime>
#include <string>
#include <csdlib>
#include <vector>
using namespace std;

const int MIN_NR = 10, MAX_NR = 99, MIN_LS = 5, MAX_LS = 20;

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

    bool emnpty(){
        return head == nullprt;
    }

    void insert_after(int value, int position) {
        if (position < 0) {
            cout << "Position must be >= 0." << endl;
            return;
        }
        Node* newNode = new Node(value);
        if (!head) {
            head = tail = newNode;
            return;
        }
        Node* temp = head;
        for (int i = 0; i < position && temp; ++i)
            temp = temp->next;
        if (!temp) {
            cout << "Position exceeds list size. Node not inserted.\n";
            delete newNode;
            return;
        }
        newNode->next = temp->next;
        newNode->prev = temp;
        if (temp->next)
            temp->next->prev = newNode;
        else
            tail = newNode;
        temp->next = newNode;
    }

    void delete_val(int value) {
        if (!head) return;
        Node* temp = head;
        while (temp && temp->data != value)
            temp = temp->next;
        if (!temp) return;
        if (temp->prev)
            temp->prev->next = temp->next;
        else
            head = temp->next;
        if (temp->next)
            temp->next->prev = temp->prev;
        else
            tail = temp->prev;
        delete temp;
    }

    void delete_pos(int pos) {
        if (!head) {
            cout << "List is empty." << endl;
            return;
        }
        if (pos == 1) {
            pop_front();
            return;
        }
        Node* temp = head;
        for (int i = 1; i < pos; i++) {
            if (!temp) {
                cout << "Position doesn't exist." << endl;
                return;
            } else
                temp = temp->next;
        }
        if (!temp) {
            cout << "Position doesn't exist." << endl;
            return;
        }
        if (!temp->next) {
            pop_back();
            return;
        }
        Node* tempPrev = temp->prev;
        tempPrev->next = temp->next;
        temp->next->prev = tempPrev;
        delete temp;
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
        delete temp;
    }

    string start(){
        if (head){
            return head ->data;
        }
    }
    string end(){
        if (tail){
            return tail->data;
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
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

};

int main() {
    DoublyLinkedList shop;
    vector <string> names; //I am using a vector to store my names
    ifstream inFile("names.txt");
    string name;
    
    while (getline(inFile, name)){ //this is to see if the file is empty or not, and it is insering the names into the vector I created 
        if (!names.empty()) {
            names.push_back(names);
        }
        else {
            cout << "The file is empty" << endl;
    }
    inFile.close();

    
    for (int i = 0; i<5 ; ++i){
        string randName = names [rand() % names.size()]; //this is to choose random names
        cout << randName << " joined the line" << endl;
        shop.push_back(randName);
    }
    shop.print();
    int prob = rand() % 100 + 1  // returns random number 1-100
        
    if (prob <= 40 && !shop.empty()) {// perform Event A
        cout << shop.start() << " is served" << endl;
        shop.pop_front();
    }

    if (prob <= 60) {
        string randName = names [rand() % names.size()];
        cout << randName << " joins the line" << endl;
        line.push_back(randName);
    }
    
    if (prob <= 20) {
        cout << line.back() << " decided not to wait and left the line" << endl;
    }
    
    if (prob <= 10) {
        line.randomPersonLeaving();
    
    }
    
    if (prob <= 10) {
    
    }
 /*In subsequent time periods, the probability of:
A customer being helped at the beginning of the line and ordering their coffee is 40%
A new customer joining the end of the line is 60%
The customer at the end of the line deciding they don't want to wait and leaving is 20%
Any particular customer can decide they don't want to wait and leave the line: 10%
A VIP (very important person) customer with a Coffee House Gold Card gets to skip the line and go straight to the counter and order: 10% */
}
