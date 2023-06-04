#include <iostream>
#include "doctest.h"
#include "sources/MagicalContainer.hpp"

using namespace ariel;

TEST_CASE("Check MagicalContainer Method Size"){
    MagicalContainer m_c;
    CHECK(m_c.size() == 0);

    CHECK_NOTHROW(m_c.addElement(2));
    CHECK(m_c.size() == 1);

    CHECK_NOTHROW(m_c.addElement(5));
    CHECK_NOTHROW(m_c.addElement(6));

    CHECK(m_c.size() == 3);

    CHECK_NOTHROW(m_c.removeElement(6));
    CHECK_NOTHROW(m_c.removeElement(5));
    CHECK_NOTHROW(m_c.removeElement(2));
    CHECK(m_c.size() == 0);

}

TEST_CASE("Check MagicalContainer Method addElement"){
    MagicalContainer m_c;
    CHECK_NOTHROW(m_c.addElement(2));
    CHECK_NOTHROW(m_c.addElement(3));
    CHECK_NOTHROW(m_c.addElement(6));
    CHECK_NOTHROW(m_c.addElement(1));
}

TEST_CASE("Check MagicalContainer Method removeElement"){
    MagicalContainer m_c;
    CHECK_NOTHROW(m_c.addElement(2));
    CHECK_NOTHROW(m_c.addElement(3));
    CHECK_NOTHROW(m_c.addElement(6));
    CHECK_NOTHROW(m_c.addElement(1));

    CHECK_NOTHROW(m_c.removeElement(2));
    CHECK_NOTHROW(m_c.removeElement(3));
    CHECK_NOTHROW(m_c.removeElement(6));
    CHECK_NOTHROW(m_c.removeElement(1));
}

TEST_CASE("init Iterators"){  
    MagicalContainer m_c;
    CHECK_NOTHROW(m_c.addElement(2));
    CHECK_NOTHROW(m_c.addElement(3));
    CHECK_NOTHROW(m_c.addElement(6));
    CHECK_NOTHROW(m_c.addElement(1));

    CHECK_NOTHROW(MagicalContainer::AscendingIterator ascIter(m_c));
    CHECK_NOTHROW(MagicalContainer::SideCrossIterator sidIter(m_c));
    CHECK_NOTHROW(MagicalContainer::PrimeIterator priIter(m_c));
}

TEST_CASE("Check AscendingIterator"){
    MagicalContainer m_c;
    CHECK_NOTHROW(m_c.addElement(20));
    CHECK_NOTHROW(m_c.addElement(10));
    CHECK_NOTHROW(m_c.addElement(60));
    CHECK_NOTHROW(m_c.addElement(1));

    CHECK_NOTHROW(MagicalContainer::AscendingIterator ascIter(m_c));

    MagicalContainer::AscendingIterator ascIter(m_c);
    auto it = ascIter.begin();
    CHECK_EQ(*it, 1);
    CHECK_NOTHROW(++it);
    CHECK_EQ(*it, 10);
    CHECK_NOTHROW(++it);
    CHECK_EQ(*it, 20);
    CHECK_NOTHROW(++it);
    CHECK_EQ(*it, 60);
    CHECK_THROWS(++it);

}

TEST_CASE("Check SideCrossIterator"){
    MagicalContainer m_c;
    CHECK_NOTHROW(m_c.addElement(20));
    CHECK_NOTHROW(m_c.addElement(10));
    CHECK_NOTHROW(m_c.addElement(60));
    CHECK_NOTHROW(m_c.addElement(1));

    CHECK_NOTHROW(MagicalContainer::SideCrossIterator ascIter(m_c));

    MagicalContainer::SideCrossIterator ascIter(m_c);
    auto it = ascIter.begin();
    CHECK_EQ(*it, 1);
    CHECK_NOTHROW(++it);
    CHECK_EQ(*it, 60);
    CHECK_NOTHROW(++it);
    CHECK_EQ(*it, 10);
    CHECK_NOTHROW(++it);
    CHECK_EQ(*it, 20);
    CHECK_THROWS(++it);

}

TEST_CASE("Check PrimeIterator"){
    MagicalContainer m_c;
    CHECK_NOTHROW(m_c.addElement(20));
    CHECK_NOTHROW(m_c.addElement(10));
    CHECK_NOTHROW(m_c.addElement(60));
    CHECK_NOTHROW(m_c.addElement(1));

    CHECK_NOTHROW(MagicalContainer::PrimeIterator ascIter(m_c));

    MagicalContainer::PrimeIterator ascIter(m_c);
    auto it = ascIter.begin();
    CHECK_EQ(*it, 1);
    CHECK_NOTHROW(++it);
    CHECK_EQ(*it, 10);
    CHECK_NOTHROW(++it);
}
