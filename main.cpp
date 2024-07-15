#include <iostream>
#include <fstream>

#ifdef CPORTA
#include "memtrace.h"
#include "gtest_lite.h"
#include "component.h"
#include "andg.h"
#include "org.h"
#include "notg.h"
#include "color.h"
#include "colors.h"
#include "contacts.h"
#include "temps.h"
#include "timer.h"
#endif

// Ez miért hiba? "az öröklés célja nem az adat, hanem a viselkedés újrahasznosítása (-4p)"
#include "model.h"

#ifndef CPORTA
int main() {
    Model m(cout);

    fstream myFile;
    myFile.open("file.txt");
    m.load(myFile);

    m.simulate(5);

    m.save(std::cout);
    return 0;
}
#else
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

    TEST(Component, TestForEmpty)
        Component c;
        Brick b;
        EXPECT_FALSE(c.test(b)); // Mivel nincs további eleme c-nek így nincs olyan szenszor ami igazat adhatna
    END

    TEST(ContactS, Test)
        ContactS cTrue(true);
        ContactS cFalse(false);

        Brick b;
        EXPECT_TRUE(cTrue.test(b));
        EXPECT_FALSE(cFalse.test(b));
    END

    TEST(Timer, Test)
        Timer cTimer(1);
        Brick b;

        time_t t = time(NULL)+1;
        EXPECT_TRUE(cTimer.test(b));
        EXPECT_LE(t, time(NULL));
    END

    TEST(ColorS, Test)
        ColorS cMagenta(MAGENTA);

        Brick bMagenta(10, MAGENTA);
        Brick bRed(10, RED);

        // Csak akkor ad igazat ha a tégla színe egyezik a szenzoréval
        EXPECT_TRUE(cMagenta.test(bMagenta)); 
        EXPECT_FALSE(cMagenta.test(bRed)); 

        // Ha belekötünk egy másik komponenst ebbe, az nem befolyásolja az eredményt
        TempS t0(0);
        cMagenta.add(&t0);

        EXPECT_TRUE(cMagenta.test(bMagenta)); 
        EXPECT_FALSE(cMagenta.test(bRed)); 
    END

    TEST(TempS, Test)
        TempS c5(5);

        Brick b0(0, RED);
        Brick b10(10, RED);

        // Csak akkor ad igazat ha a tégla hőmérséklete magasabb a szenzorénál
        EXPECT_FALSE(c5.test(b0));
        EXPECT_TRUE(c5.test(b10));

        // Ha belekötünk egy másik komponenst ebbe, az nem befolyásolja az eredményt
        ColorS cRed(RED);
        c5.add(&cRed);

        EXPECT_FALSE(c5.test(b0));
        EXPECT_TRUE(c5.test(b10));
    END

    TEST(AndG, Test)
        AndG c;

        TempS t0(0);
        TempS t10(10);
        c.add(&t0);
        c.add(&t10);

        Brick b0(0, RED);
        Brick b20(20, RED);

        // Csak akkor lesz igaz ha az összes komponense igazat ad.
        EXPECT_FALSE(c.test(b0));
        EXPECT_TRUE(c.test(b20));

        TempS t5(5);
        c.add(&t5);
        
        // Ugyanez több komponenssel.
        EXPECT_FALSE(c.test(b0));
        EXPECT_TRUE(c.test(b20));
    END

    TEST(OrG, Test)
        OrG c;

        TempS t0(0);
        TempS t10(10);
        c.add(&t0);
        c.add(&t10);

        Brick b0(0, RED);
        Brick b20(20, RED);

        // Igaz ha bármelyik komponense igazat ad vissza.
        EXPECT_FALSE(c.test(b0));
        EXPECT_TRUE(c.test(b20));
    END

    TEST(NotG, Test)
        NotG c;

        TempS t0(0);
        TempS t10(10);
        c.add(&t0);
        c.add(&t10);

        Brick b0(0, RED);
        Brick b10(10, RED);

        // Ha bármelyik komponense igaz, hamisat ad
        // Ha mindegyik komponense hamis, igazat ad
        EXPECT_TRUE(c.test(b0));    // b hőmérséklete: 0, ez nem nagyobb mint 0 vagy 10, tehát mindkét komponense hamis  
        EXPECT_FALSE(c.test(b10));  // b hőmérséklete: 21, ez nagyobb mint 0 vagy 10, tehát mindkét komponense igaz  
    END
    return 0;
}
#endif