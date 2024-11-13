#include "Person.h"

namespace cs32
{


// Person Constructors
Person::Person( ) : mName( "" ), mGender( Gender::PREFERNOTTOANSWER )
{
    
}

Person::Person( std::string name, Gender gender ) : mName( name ), mGender( gender )
{
    
}

// Trivial Person getters
const std::string& Person::getName()   const
{
    return( mName );
}

Gender             Person::getGender() const
{
    return( mGender );
}

// TODO Who is your mother?
void           Person::setMother( Person * p )
{
}

// TODO Who is your father?
void           Person::setFather( Person * p )
{
}

// TODO Who is your mother?
Person*        Person::getMother() const
{
    return( nullptr );
}

// TODO Who is your father?
Person*        Person::getFather() const
{
    return( nullptr );
}

// TODO who are your siblings - brothers or sisters?
void           Person::addSibling( Person * p )
{
}

// TODO who are your grandparents - grandfather or grandmother?
void           Person::addGrandparent( Person * p )
{
}

// TODO who are your children - sons or daughters?
void           Person::addChild( Person * p )
{
}

// Required Relationship Functions
// TODO return all your defined brothers
std::set<Person*> Person::brothers( )
{
    // just for now...  this returned set is empty
    std::set< Person * > set;
    return( set );
}

// TODO return all your defined children - sons and daughters
std::set<Person*> Person::children()
{
    // just for now...  this returned set is empty
    std::set< Person * > set;
    return( set );
}

// TODO return all your defined daughters
std::set<Person*> Person::daughters()
{
    // just for now...  this returned set is empty
    std::set< Person * > set;
    return( set );
}

// TODO return all your defined grandfathers
std::set<Person*> Person::grandfathers( )
{
    // just for now...  this returned set is empty
    std::set< Person * > set;
    return( set );
}

// TODO return all your defined grandmothers
std::set<Person*> Person::grandmothers()
{
    // just for now...  this returned set is empty
    std::set< Person * > set;
    return( set );
}

// TODO return all your defined grandparents - grandfathers and grandmothers
std::set<Person*> Person::grandparents()
{
    // just for now...  this returned set is empty
    std::set< Person * > set;
    return( set );
}

// TODO return all your defined parents - father and mother
std::set<Person*> Person::parents( )
{
    // just for now...  this returned set is empty
    std::set< Person * > set;
    return( set );
}

// TODO return all your defined siblings - brothers and sisters
std::set<Person*> Person::siblings( )
{
    // just for now...  this returned set is empty
    std::set< Person * > set;
    return( set );
}

// TODO return all your defined sisters
std::set<Person*> Person::sisters( )
{
    // just for now...  this returned set is empty
    std::set< Person * > set;
    return( set );
}

// TODO return all your defined sons
std::set<Person*> Person::sons()
{
    // just for now...  this returned set is empty
    std::set< Person * > set;
    return( set );
}

}
