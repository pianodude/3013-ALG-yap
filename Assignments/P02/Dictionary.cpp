#include <iostream>
#include <string>
#include <fstream> 
#include <vector>
using namespace std;


struct wordNode{
  string word;
  string defn;
  wordNode* Next;
  wordNode(string w,string d){
    word = w;
    defn = d;
    Next = NULL;
  }
};

class Dictionary {
private:
  wordNode* Start;

  string LowerCase(string input){
    for(int i=0;i<input.length();i++){
      if((int)input[i] < 96){
        input[i] += 32;
      }
    }
    return input;
  }


public:

  Dictionary(){
    Start = NULL;
  }

  ~Dictionary(){
    //cout<<
  }

  void Add(string word,string defn){

      // 

    word = LowerCase(word);
    // create new memory
    wordNode* temp = new wordNode(word,defn);
  
    // if list is empty hook in new wordNode
    if(Start == NULL){
      Start = temp;
    }else{
      // get ready to walk the list
      wordNode* traverse = Start;
      while(traverse->Next != NULL){
        // walks the list
        traverse = traverse->Next;
      }
      // now at proper place to link in new memory
      traverse->Next = temp;
    }
  }

  /**
     * Public: Search
     * 
     * Description:
     *      String vector that searches and stores words matching 
     *      the one you typed for each char
     * Params:
     *      -[string] :searchword
     * 
     * Returns:
     *      - vector matchingwords
     */
 vector<string> Search(string searchword)
 {
      wordNode* traverse = Start;
      vector<string> matchingwords;
      while(traverse->Next != NULL){
        // walks the list
        // check if traverse.getWord() starts with searchWord
        // if yes, then add it to the matchingwords
        // matchingwords.push_back(traverse.getWord())
        if (searchword.size()<=traverse->word.size()) //makes sure searchword is smaller than 
        {                                             //the dictionary word
        bool match=true;
       for (int i=0;i<searchword.size();i++)          //goes for each char
       {
           if(searchword[i]!=traverse->word[i])       //if it dosent match
           {
               match=false;
               break;
           }
       }
              if (match==true)
       {
           matchingwords.push_back(traverse->word);    //push_back means insert into vector
       }
        }
        traverse = traverse->Next;                     //goes thruogh each word in dictionary
        
      }
      return matchingwords;
 }
 
  string Remove(string key){
    string temp = "";

    if(!Start){
      return "";
    }else{
      wordNode* cptr = Start;
      wordNode* prev = Start;
      while(cptr && cptr->word != key){
        prev = cptr;
        cptr = cptr->Next;
      }
      // if cptr then we found the word
      if(cptr){
        temp = cptr->word;
        prev->Next = cptr->Next;
        delete cptr;
      }else{
        // no word, return empty
        temp = "";
      }
      return temp;
    }


    return temp;
  }

  void ReOrder(){
    // pointers for new list
    wordNode* NewList = NULL;
    wordNode* Tail=NULL;

    int i;

   while(Start != NULL){

    // helper pointers to manipulate lists
    wordNode* Ptr = Start;
    wordNode* Min = Start;
    wordNode* Prev = Start;
    wordNode* MinPrev = Start;
   

      // find one minimum word in old list
      while(Ptr != NULL){
        if(Ptr->word < Min->word){
          MinPrev = Prev;
          Min = Ptr;
        }

        Prev = Ptr;
        Ptr = Ptr->Next;
      }
      //end finding one word in old list

      // add one word to new list

      if(!NewList){
        NewList = Min;
      }else{
        Tail->Next = Min;
      }

      Tail = Min;
      if(MinPrev == Start){
        Start = Start->Next;
      }else{
        MinPrev->Next = Min->Next;
      }
      
      Min->Next = NULL;
      i++;

      // if(i>=6){
      //   break;
      // }
      // adding one word to new list

      // wordNode* Temptemptmemp = NewList;

      // while(Temptemptmemp){
      //   cout<<Temptemptmemp->word<<" ";
      //   Temptemptmemp = Temptemptmemp->Next;
      // }
      // cout<<endl;
   }

   Start = NewList;


  }

  void Print(){
    wordNode* temp = Start;
    while(temp){
      cout<<temp->word;
      cout<<": "<<temp->defn;
      if(temp->Next){
        cout<<"->";
      }
      temp = temp->Next;
    }
    cout<<endl;
  }




};
/////////////////////////////////////////////////////

// int main() {
//   Dictionary *W;

//   W = new Dictionary;

//   ifstream fin("dictionary.txt");
//   string word;

//   // while(fin>>word){
//   //   W.Add(word);
//   // }

//   //W.Add("Ant");
//   W->Add("Dog");
//   //W.Add("Aaron");
//   //W.Add("Aardvark");
//   W->Add("Cow");
//   //W.Add("Rabbit");


//   W->Print();

//   W->ReOrder();

//   W->Print();

//   delete W;

// }