#ifndef PERSON_H
#define PERSON_H

#include "Enums.h"

#include <set>
#include <string>

// This is the Person class you need to implement
// It has many member functions that get invoked when relationship queries are run
// You are free to add data members to track all the known relationships
//     with this Person found in the database

namespace cs32
{


class Person 
{
private:
    // Member Variables
    std::string mName;
    Gender      mGender;
    // CS 32 Students are expected to add additional private data members as they
    //       fully implement this class
    
public:
    Person();
    Person( std::string name, Gender gender );
    
    // Trivial Getter Functions
    const std::string& getName()   const;
    Gender             getGender() const;
    
    // TODO who is your mother?
    Person*            getMother() const;
    // TODO who is your father?
    Person*            getFather() const;
    
    // TODO who is your mother?
    void               setMother( Person * p );
    // TODO who is your father?
    void               setFather( Person * p );
    // TODO who are your siblings - brothers or sisters?
    void               addSibling( Person * p );
    // TODO who are your grandparents - grandfather or grandmother?
    void               addGrandparent( Person * p );
    // TODO who are your children - sons or daughters?
    void               addChild( Person * p );
    
    // Required Relationship Functions
    // TODO return all your defined siblings - brothers and sisters
    std::set< Person * >  siblings();
    // TODO return all your defined sisters
    std::set< Person * >  sisters();
    // TODO return all your defined brothers
    std::set< Person * >  brothers();
    // TODO return all your defined children - sons and daughters
    std::set< Person * >  children();
    // TODO return all your defined daughters
    std::set< Person * >  daughters();
    // TODO return all your defined sons
    std::set< Person * >  sons();
    // TODO return all your defined grandparents - grandfathers and grandmothers
    std::set< Person * >  grandparents();
    // TODO return all your defined grandfathers
    std::set< Person * >  grandfathers();
    // TODO return all your defined grandmothers
    std::set< Person * >  grandmothers();
    // TODO return all your defined parents
    std::set< Person * >  parents();

};


}

#endif
