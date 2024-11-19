    #include <iostream>
    #include <string>
    #include <cassert>

    #include "Person.h"

    int main()
    {
          using namespace std;
          using namespace cs32;
     
          // Person tests
          Person person( "Howard", Gender::MAN );
          Person mother( "Alberta", Gender::WOMAN );
          Person father( "Myron", Gender::MAN );
          Person grandfather( "Karl", Gender::MAN );
          Person grandmother( "Sadie", Gender::WOMAN );
          // establish the family tree
          person.setFather( &father );
          person.setMother( &mother );
          person.addGrandparent( &grandmother );
          person.addGrandparent( &grandfather );
          father.addChild( &person );
          mother.addChild( &person );
                  
          assert( person.getFather() != nullptr );
          assert( person.getMother() != nullptr );
          assert( person.getFather()->getName() == "Myron" );
          assert( person.getMother()->getName() == "Alberta" );
          assert( person.parents().size() == 2 );
          assert( person.children().size() == 0 );
          assert( person.daughters().size() == 0 );
          assert( person.sons().size() == 0 );
          assert( person.grandparents().size() == 2 );

          cout << "all tests passed!" << endl;
          return( 0 );
    }  