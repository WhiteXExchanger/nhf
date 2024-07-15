// model.cpp
#include <thread>
#include "model.h"

#include "component.h"
#include "temps.h"
#include "colors.h"
#include "contacts.h"
#include "timer.h"
#include "andg.h"
#include "org.h"
#include "notg.h"
#include "animation.h"

Model::Model(ostream& os) : os(os) {
        allComps.push_back(&alarm);
    }

void Model::load(istream& ios) {
    char c;
    // Elemek begyüjtése
    while(ios.peek() != '\n') {
        ios >> c;
        switch (c)
        {
        case 'T':
            double teperature;
            ios >> teperature;
            allComps.push_back(new TempS(teperature));
            break;
        case 'C':
            Color color;
            ios >> color;
            allComps.push_back(new ColorS(color));
            break;
        case 'c':
            int status;
            ios >> status;
            allComps.push_back(new ContactS(status));
            break;
        case 'a':
            allComps.push_back(new AndG());
            break;
        case 'o':
            allComps.push_back(new OrG());
            break;
        case 'n':
            allComps.push_back(new NotG());
            break;
        case 't':
            time_t seconds;
            ios >> seconds;
            allComps.push_back(new Timer(seconds));
            break;
        default:
            throw runtime_error("Hibas bemenet!");
        }
    }
    ios.ignore(1);

    // Elemek összerendelése
    size_t index = 0;
    while(ios.peek() != EOF) {
        ios >> index;
        Component* c = allComps.at(index);
        ios.ignore(2);
        while(ios.peek() != '\n') {
            size_t child_index;
            ios >> child_index;
            c->add(allComps.at(child_index));
            ios.ignore(1);
        }
        ios.ignore(1);
    }
}

void Model::save(ostream& ios) const {
    // Elemek kiíratása
    for (auto c : allComps) {
        c->save(ios);
    }
    ios << endl;

    // Elemekenkénti kapcsolat kiírása
    size_t index = 0;
    std::vector<size_t> childIndexes;
    for (auto c : allComps) {
        ios << index << ": ";
        childIndexes = c->indexesInCollection(allComps);
        for (auto child : childIndexes) {
            ios << child << " ";
        }
        ios << endl;
        ++index;
    }
    
}

bool Model::testModel(Brick b) const {
    return alarm.test(b);
}

void Model::simulate(size_t n) const {
    vector<Brick> bricks;

    for (size_t i = 0; i < n; ++i) {
        bricks.push_back(Brick());
    }

    for (auto b : bricks) {
        clearScreen();
        os << "Waiting for timers if there are any...";
        drawSimulation(testModel(b), b);
    }
}

void Model::drawSimulation(bool result, Brick b) const {
    if(result) {
        for (int i = 0; i < 3; ++i) {
            clearScreen();
            os << goodFrames[i] << std::endl;
            os << b;
            std::this_thread::sleep_for(std::chrono::milliseconds(750));
        }
    } else {
        for (int i = 0; i < 3; ++i) {
            clearScreen();
            os << badFrames[i] << std::endl;
            os << b;
            std::this_thread::sleep_for(std::chrono::milliseconds(750));
        }
    }
}

Model::~Model() {
    for (auto c : allComps) {
        delete c;
    }
}