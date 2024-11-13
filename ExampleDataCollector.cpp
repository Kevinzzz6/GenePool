//
//  ExampleDataCollector.cpp
//  Titanic
//
//  Created by Howard Stahl on 9/11/23.
//

#include "ExampleDataCollector.h"
#include <iostream>

namespace cs32
{


ExampleDataCollector::ExampleDataCollector()
{
    
}

void ExampleDataCollector::tsvData( std::map< std::string, std::string > row )
{
    using namespace std;
    
    cout << "gotta row!" << endl;
    
    for( std::map< std::string, std::string >::iterator iter = row.begin(); iter != row.end(); iter++)
    {
        std::cout << iter->first << " - " << iter->second << std::endl;
    }
}


}

