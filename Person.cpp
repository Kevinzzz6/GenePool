#include "Person.h"
#include <iostream>
namespace cs32
{


// Person Constructors
Person::Person() : mName(""), mGender(Gender::PREFERNOTTOANSWER), 
    mFather(nullptr), mMother(nullptr) {
}

Person::Person( std::string name, Gender gender ) : mName( name ), mGender( gender ),
    mFather(nullptr), mMother(nullptr) { 
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
Person* Person::getMother() const {
    return mMother;
}

// TODO Who is your father?
Person* Person::getFather() const {
    return mFather;
}

void Person::setMother(Person* p) {
    if (p != nullptr && p->getGender() == Gender::WOMAN) {
        mMother = p;
        p->mChildren.insert(this);
    }
}

void Person::setFather(Person* p) {
    if (p != nullptr && p->getGender() == Gender::MAN) {
        mFather = p;
        p->mChildren.insert(this);
    }
}

// TODO who are your siblings - brothers or sisters?
void Person::addSibling(Person* p) {
    if (p != nullptr && p != this) {
        mSiblings.insert(p);
        p->mSiblings.insert(this);
    }
}

// TODO who are your grandparents - grandfather or grandmother?
void Person::addGrandparent(Person* p) {
    if (p != nullptr) {
        mGrandparents.insert(p);
    }
}

// TODO who are your children - sons or daughters?
void Person::addChild(Person* p) {
    if (p != nullptr) {
        mChildren.insert(p);
        if (mGender == Gender::MAN) {
            p->setFather(this);
        } else if (mGender == Gender::WOMAN) {
            p->setMother(this);
        }
    }
}

// Required Relationship Functions
// TODO return all your defined brothers
std::set<Person*> Person::brothers() {
    std::set<Person*> result;
    for (Person* sibling : mSiblings) {
        if (sibling->getGender() == Gender::MAN) {
            result.insert(sibling);
        }
    }
    return result;
}

// TODO return all your defined children - sons and daughters
std::set<Person*> Person::children() {
    return mChildren;
}

// TODO return all your defined daughters
std::set<Person*> Person::daughters() {
    std::set<Person*> result;
    for (Person* child : mChildren) {
        if (child->getGender() == Gender::WOMAN) {
            result.insert(child);
        }
    }
    return result;
}

// TODO return all your defined grandfathers
std::set<Person*> Person::grandfathers() {
    std::set<Person*> result;
    for (Person* gp : mGrandparents) {
        if (gp->getGender() == Gender::MAN) {
            result.insert(gp);
        }
    }
    return result;
}

// TODO return all your defined grandmothers
std::set<Person*> Person::grandmothers() {
    std::set<Person*> result;
    for (Person* gp : mGrandparents) {
        if (gp->getGender() == Gender::WOMAN) {
            result.insert(gp);
        }
    }
    return result;
}

// TODO return all your defined grandparents - grandfathers and grandmothers
std::set<Person*> Person::grandparents() {
    return mGrandparents;
}

// TODO return all your defined parents - father and mother
std::set<Person*> Person::parents() {
    std::set<Person*> result;
    if (mFather != nullptr) result.insert(mFather);
    if (mMother != nullptr) result.insert(mMother);
    return result;
}

// TODO return all your defined siblings - brothers and sisters
std::set<Person*> Person::siblings( )
{
    return mSiblings;
}

// TODO return all your defined sisters
std::set<Person*> Person::sisters() {
    std::set<Person*> result;
    for (Person* sibling : mSiblings) {
        if (sibling->getGender() == Gender::WOMAN) {
            result.insert(sibling);
        }
    }
    return result;
}

// TODO return all your defined sons
std::set<Person*> Person::sons() {
    std::set<Person*> result;
    for (Person* child : mChildren) {
        if (child->getGender() == Gender::MAN) {
            result.insert(child);
        }
    }
    return result;
}

}
