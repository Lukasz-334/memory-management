#include "uniquePtr.hpp"
#include "gtest/gtest.h"
#include "Point.hpp"

Point p(4,6);

TEST(operatorArrowTest, dataAccessTest ) {
    unique_ptr<Point> uptr(new Point(17, 55));

   ASSERT_EQ(uptr->getX(),17);
   ASSERT_EQ(uptr->getY(),55);
   uptr->setX(12);
   ASSERT_EQ(uptr->getX(),12);
}


TEST(operatorGetTest, theFunctionReturnsAPointer  ) {
    unique_ptr<Point> uptr(new Point(44, 55));
    Point* ptr;
    ptr = uptr.get();
   
   ASSERT_EQ(uptr->getX(),44);
   ASSERT_EQ(ptr->getX(),44);
 

}

TEST(operatorReleaseTest,returnsAPointerAndReleasesAProperty ){
unique_ptr<Point> uptr(new Point(88, 55));
    Point* ptr;
    ptr = uptr.release();

    ASSERT_EQ(uptr.get(),nullptr);
    ASSERT_EQ(ptr->getX(),88);
    
    delete ptr;
}

TEST(operatorResetTest,ee){
    
}





