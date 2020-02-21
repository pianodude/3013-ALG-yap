///////////////////////////////////////////////////////////////////////////////
//                   
// Author:           Joshua Yap
// Email:            joshyap92@yahoo.com
// Label:            p02
// Title:            processing in linear time
// Course:           CMPS 3013
// Semester:         spring 2020
//
// Description:
//       uses json to find words based on a substring
//
// Usage:
//       one char then searches 10 of the some substring
//
// Files:            Dictionary.cpp
//                   json.hpp
//                   JsonFacade.hpp
//                   mygetch.hpp
//                   Timer.hpp
//                   dict_w_defs.json
/////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include "mygetch.hpp"
#include "JsonFacade.hpp"       // need to grab a copy from resources folder
#include <time.h>
#include <chrono> 
#include "Timer.hpp"            // need to grab a copy from resources folder
#include "Dictionary.cpp"
#include <vector>
using namespace std;

/**
 * STEP 1
 * Create an instance of a list (Dictionary) in your main.
 * Loop through the json file and insert one word:definition into the list
 * Print the list
 * 
 * STEP 2
 * 
 * Search the list for a substring (any substring)
 * Print out any word that matches that substring
 * http://www.cplusplus.com/reference/string/string/find/
 * 
 * STEP 3
 * 
 * 
 */

int main(){
    srand(9870);
    Dictionary D;
    Timer T;
    
    JsonFacade J("dict_w_defs.json");   // create instance of json class
     
    double s = T.Seconds();
    long m = T.MilliSeconds();

    cout <<s << " seconds" <<endl;
    cout <<m << " milli" <<endl;
    int index = 0;                      // 
    string key;                         // key variable to access json object

    vector<string> keys = J.getKeys();
    
    cout<<"hi";
//all words are in linked list
    for (int i=0;i<J.getSize();i++)         
    {    
        D.Add(J.getKey(i), J.getValue(J.getKey(i)));
    }

    string searchword= "";
    char k;
    cout<<"enter word"<<endl;

    while (k=getch() !='Z') //type capital Z when done
    {
        searchword+=k;      //adds the char
        T.Start();
        vector<string>matchingwords=D.Search(searchword);    //
        T.End();
        cout<<matchingwords.size()<<" words found in "<< s <<" seconds";

        for (int i=0; i<10; i++)
        {
            cout <<matchingwords[i]<<" ";
        }
       
        cout<<k<<endl;
    }


    
    
    //D.Print();

    //cout<<keys.size()<<endl;
    //index = rand() % keys.size();
    //key = J.getKey(index);

   // cout<<key<<" = "<<J.getValue(key)<<endl;
   // cout<<"fun"<<" = "<<J.getValue("fun")<<endl;
}
