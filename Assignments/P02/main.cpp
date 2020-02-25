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
//       type a string then it searches 10 of the same substring
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
#include <limits>

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
    vector<string> matchingwords;
    
    cout<<"Loading Json file ...\n"<<flush;
    JsonFacade J("dict_small.json");   // create instance of json class
    cout<<"Done loading \n"<<flush;
     
    double s = T.Seconds();
    long m = T.MilliSeconds();

    cout <<s << " seconds" <<endl;
    cout <<m << " milli" <<endl;
    int index = 0;                      // 
    string key;                         // key variable to access json object

    cout<<"Getting Keys ...\n"<<flush;
    vector<string> keys = J.getKeys();
    cout<<"Done ...\n"<<flush;
    
    
//all words are in linked list
    cout<<"Loading List ...\n"<<flush;
    for (int i=0;i<J.getSize();i++)         
    {    
        D.Add(J.getKey(i), J.getValue(J.getKey(i)));
    }
    cout<<"Done Loading List ...\n"<<flush;

    string searchword= "";
    char k;
    cout<<"enter word: "<<endl;

    //D.Print();

    cin.ignore();
    cin.sync();

    // while (k=getch() !='Z') //type capital Z when done
    // {                       //somehow not working
        cin>>searchword;
        //searchword += k;      //adds the char
        T.Start();
        matchingwords = D.Search(searchword);    
        T.End();
        cout<<matchingwords.size()<<" words found in "<< s <<" seconds"<<endl;;

         for (int i=0; i<10; i++)
         {
             cout <<matchingwords[i]<<" ";
         }
       
        
    //}


    
    
   return 0;
}
