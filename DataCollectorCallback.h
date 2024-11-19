//
//  DataCollectorCallback.hpp
//  Titanic
//
//  Created by Howard Stahl on 7/1/23.
//

#ifndef DATACOLLECTORCALLBACK_H
#define DATACOLLECTORCALLBACK_H

#include <map>
#include <string>

namespace cs32
{

class DataCollectorCallback
{
public:
    virtual void tsvData( std::map< std::string, std::string > row ) = 0;
    virtual ~DataCollectorCallback() = default;
private:
    
};

}

#endif
