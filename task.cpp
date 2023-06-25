#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;

class TextEditor {
public:
    string s="";
    string s1="";
    int cursor=0;
    TextEditor() {
        
    }
    
    void addText(string text) {
        s=s.insert(cursor,text);
        cursor+=text.size();
        s1=s;
    }
    
    void deleteText(int k) {
        int temp=min(cursor,k);
        s.erase(cursor-temp,temp);
        cursor-=temp;
        cout << s << endl;
        
    }

    void backspace() {
        s.erase(s.size()-1);
        cout << s << endl;
    }

    int findCursor() {
        return cursor;
    }
    
    void cursorLeft(int k) {
        int temp=min(k,cursor);
        cursor-=temp;
        
    }
    
    void cursorRight(int k) {
        int p=s.size();
        int temp=min(k,p-cursor);
        cursor+=temp;
        
    }

    string fullText() {
        return s1;
    }

    string showText(int k) {
        int p=s.size();
        string ans=s.substr(cursor,k);
        return ans;
    }
};

int main()
{
    
    TextEditor* obj=new TextEditor();                  //this was me testing the program
    obj->addText("sytfhajdhaskjdfdgdf");
    obj->deleteText(3);
    obj->backspace();
    obj->cursorLeft(12);
    obj->cursorRight(2);
    int ind=obj->findCursor();
    string i=obj->fullText().c_str();
    string j=obj->showText(3).c_str();
    cout << ind << endl;
    cout << i << endl;
    cout << j << endl;
}