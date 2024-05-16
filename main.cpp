
#include "model.cpp"
#include "ecomponent.h"

#include <iostream>

//#define CPORTA
#define TESZTELES

#ifdef TESZTELES
int main() {
    Model m(cout);
    m.add(EComponent::AndG,1);
    m.add(EComponent::AndG,2);
    m.remove(2);
    m.drawComponentTree();
}
#endif

#ifdef CPORTA

#include "gtest_lite.h"
#include "brick.h"
#include "color.h"
int main() {

    TEST(Brick, DefaultConstructor)
        Brick t;
        EXPECT_LE(0.0,t.getTemperature());
        EXPECT_LE(RED,t.getColor());
    END

    TEST(Brick, Constructor)
        Brick t(3.14,YELLOW);
        EXPECT_EQ(3.14,t.getTemperature());
        EXPECT_EQ(YELLOW,t.getColor());
    END

    TEST(Component, Constructor) // Erre még alszok egyet
    END

    TEST(Model, Constructor)
    END

    TEST(Model, Add)
    END

    TEST(Model, Remove)
    END

    TEST(Model, Modify)
    END

    return 0;
}
#endif