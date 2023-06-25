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
    
    string real="";
    string showt="";
    string original="";
    int del,left,right,pos,show;
    TextEditor* obj=new TextEditor();                  
    cout << "enter the text" << endl;;
    cin >> real;
    obj->addText(real);
    cout << "enter how many characters you want to delete" << endl;;
    cin >> del;
    cout << "string after deleting: " << endl;
    obj->deleteText(del);
    cout << "string after a backspace: " << endl;
    obj->backspace();
    
    cout << "enter by how many positions do you want to shift cursor to the left" << endl;;
    cin >> left;
    obj->cursorLeft(left);
    cout << "enter by how many positions do you want to shift cursor to the right" <<endl;
    cin >> right;
    obj->cursorRight(right);
    pos=obj->findCursor();
    cout << "cursor is at: " + pos << endl;
    cout << "enter the number of characters you want to print after the cursor" << endl;
    cin >> show;
    showt=obj->showText(show);
    cout << "the resulting string is: "+showt << endl;
    original=obj->fullText();
    cout << "the original string was: "+original << endl;

    return 0;
}
