/**
 * Examples of automatic tests for the exercise on binary trees.
 *
 * @author Erel Segal-Halevi
 * @since 2019-02
 */

#include <iostream>
using std::cout, std::endl;
#include "badkan.hpp"
#include "Tree.hpp"

int main() {
  ariel::Tree emptytree;
  ariel::Tree threetree;
  threetree.insert(5);
  threetree.insert(7);
  threetree.insert(3);

  ariel::Tree mytree;
  mytree.insert(10);
  mytree.insert(5);
  mytree.insert(6);
  mytree.insert(8);
  mytree.insert(12);

  badkan::TestCase tc("Binary tree");
  tc
  .CHECK_EQUAL (emptytree.size(), 0)
  .CHECK_OK    (emptytree.insert(5))
  .CHECK_EQUAL (emptytree.size(), 1)
  .CHECK_EQUAL (emptytree.contains(5), true)
  .CHECK_OK    (emptytree.remove(5))
  .CHECK_EQUAL (emptytree.contains(5), false)
  .CHECK_THROWS(emptytree.remove(5))
  .CHECK_EQUAL (emptytree.size() ,0)

  .CHECK_EQUAL (threetree.size(), 3)
  .CHECK_EQUAL (threetree.root(), 5)
  .CHECK_EQUAL (threetree.parent(3), 5)
  .CHECK_EQUAL (threetree.parent(7), 5)
  .CHECK_EQUAL (threetree.left(5), 3)
  .CHECK_EQUAL (threetree.right(5), 7)
  .CHECK_THROWS(threetree.insert(3))
  .CHECK_THROWS(threetree.left(6))
  .CHECK_OK    (threetree.print())

  .CHECK_EQUAL (mytree.size(), 5)
  .CHECK_THROWS(mytree.insert(5))
  .CHECK_EQUAL (mytree.size, 5)
  .CHECK_EQUAL (mytree.contains(10), true)
  .CHECK_EQUAL (mytree.contains(84), false)
  .CHECK_OK    (emptytree.remove(5))
  .CHECK_EQUAL (mytree.size, 4)
  .CHECK_OK    (emptytree.remove(5)) //checking second time to see for errors
  .CHECK_EQUAL (mytree.size, 4)
  .CHECK_EQUAL (mytree.contains(5), false)
  .CHECK_THROWS(mytree.insert(45))
  .CHECK_EQUAL (mytree.size(), 5)
  .CHECK_EQUAL (mytree.contains(45), true)
  .CHECK_EQUAL (mytree.right(45), NULL)
  .CHECK_EQUAL (mytree.left(45), NULL)
  .CHECK_EQUAL (mytree.parent(45), 12)
  .CHECK_EQUAL (mytree.root(), 10)
  .CHECK_OK    (emptytree.remove(10))
  .CHECK_EQUAL (mytree.root(), 12)



  .print();

  cout << "You have " << tc.right() << " right answers and " << tc.wrong() << " wrong answers so your grade is " << tc.grade() << ". Great!" << endl;
}
