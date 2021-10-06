#include "Point.hpp"
#include "gtest/gtest.h"
#include "uniquePtr.hpp"


TEST(operatorArrowTest, dataAccessTest) {
    unique_ptr<Point> uptr(new Point(17, 55));

    ASSERT_EQ(uptr->getX(), 17);
    ASSERT_EQ(uptr->getY(), 55);
    uptr->setX(12);
    ASSERT_EQ(uptr->getX(), 12);
}

TEST(operatorGetTest, theFunctionReturnsAPointer) {
    unique_ptr<Point> uptr(new Point(44, 55));
    Point* ptr;
    ptr = uptr.get();

    ASSERT_EQ(uptr->getX(), 44);
    ASSERT_EQ(ptr->getX(), 44);
}

TEST(operatorReleaseTest, returnsAPointerAndReleasesAProperty) {
    unique_ptr<Point> uptr(new Point(88, 55));
    Point* ptr;
    ptr = uptr.release();

    ASSERT_EQ(uptr.get(), nullptr);
    ASSERT_EQ(ptr->getX(), 88);

    delete ptr;
    
}

TEST(operatorResetTest, newMemoryAllocation ) {
    unique_ptr<Point> uptr(new Point(88, 55));

    uptr.reset(new Point(22, 88));
    ASSERT_EQ(uptr->getX(), 22);
    ASSERT_EQ(uptr->getY(), 88);

    uptr.reset();
    ASSERT_EQ(uptr.get(), nullptr);
}

TEST(transferConstructorTest,transferOfResources ){
 
    unique_ptr<Point> uptr(new Point(37, 71));
   
    unique_ptr<Point> uptr2(std::move(uptr));
    
    ASSERT_EQ(uptr2->getX(),37);
    ASSERT_EQ(uptr.get(),nullptr);


}

TEST(MoveAssignmentOperatorTest, dataTransfer ){
 
    unique_ptr<Point> uptr(new Point(37, 71));
    unique_ptr<Point> uptr2(new Point(17, 41));
    uptr=std::move(uptr2);
    
    ASSERT_EQ(uptr->getX(),17);
    ASSERT_EQ(uptr2.get(),nullptr);

    uptr2=std::move(uptr);

    ASSERT_EQ(uptr2->getX(),17);
    ASSERT_EQ(uptr.get(),nullptr);


}

TEST(OperatorShellingTest,ReturnsTheObjectOwned){

unique_ptr<Point> uptr(new Point(37, 71));
Point & point = *uptr;

ASSERT_EQ(point.getX(),37);

}