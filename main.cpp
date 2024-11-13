#include "Person.h"
#include "GenePool.h"
#include "Query.h"
#include "Settings.h"
#include "ExampleDataCollector.h"
#include "TSVFile.h"

#include <iostream>
#include <stdexcept>
#include <vector>
#include <algorithm>

// This file provides a standard main loop.
// You can edit it if you want, but you shouldn't need to.


// Helper structure to sort person pointers by name
struct Compare {
  bool operator () (const cs32::Person* a, const cs32::Person* b) const {
    return a->getName() < b->getName();
  }
};

void sample()
{
    // an example of working with the DataCollector interface
    using namespace cs32;
    
    std::cout << "ExampleDataCollector-" << std::endl;
    ExampleDataCollector * example = new ExampleDataCollector();
    TSVFile file( example );
    int recordCount = file.readFile( PATH_TO_CUNCO_DATA_MAC );
    std::cout << "ExampleDataCollector-" << recordCount << std::endl;
    delete( example );
}

int main() 
{
    using namespace cs32;
    
    GenePool database;
    // database.load( PATH_TO_SIMPSONS_DATA_WINDOWS );
    // database.load( PATH_TO_CUNCO_DATA_WINDOWS );
    database.load( PATH_TO_SAMPLE_DATA_WINDOWS );
    
    std::string line;
    std::cout << "> ";
    while (std::getline(std::cin, line))
    {
        if (line == "quit" || line == "exit")
        {
            break;
        }
        try {
            // Parse and run the query
            Query query(line);
            std::set<Person*> result = query.run(database);
            
            // Make sure everyone is valid
            if (result.count(nullptr) != 0)
            {
                throw std::runtime_error("Result set contained a null pointer.");
            }
            
            // Sort the people by name for consistent output
            std::vector<Person*> people(result.begin(), result.end());
            std::sort(people.begin(), people.end(), Compare());
            
            // Print the result
            for(std::vector< Person * >::iterator iter = people.begin(); iter != people.end(); ++iter )
            {
                Person * person = *iter;
                std::cout << " - " << person->getName() << std::endl;
            }
            if (people.empty())
            {
                std::cout << " (no results)\n";
            }
        }
        catch(const std::exception& e) 
        {
            // Print the error message:
            std::cout << e.what() << std::endl;
        }
        
        std::cout << "> ";
    }
    
    std::cout << std::endl;
    return( 0 );
}
