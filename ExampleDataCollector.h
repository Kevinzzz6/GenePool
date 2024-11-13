//
//  ExampleDataCollector.hpp
//  Titanic
//
//  Created by Howard Stahl on 9/11/23.
//

#ifndef ExampleDataCollectorH
#define ExampleDataCollectorH


#include "DataCollectorCallback.h"
#include <vector>

// a sample class to show students how to work with the DataCollectorCallback

namespace cs32
{


class ExampleDataCollector : public DataCollectorCallback
{
public:
    ExampleDataCollector( );
    
    // the DataCollectorCallback interface
    virtual void tsvData( std::map< std::string, std::string > row );
    
};

}

#endif
