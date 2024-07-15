// component.h
#pragma once
#include <queue>
#include <vector>
#include <iostream>
#include "brick.h"

using namespace std;

/**
 * @class Component
 * @brief Base class for components.
 */
class Component {
public:
    /**
     * @brief Tests the connected components with the given brick and returns the state of those tests with its own behaviour.
     * @param brick The brick to test with.
     * @return True if the test is successful, otherwise false.
     */
    virtual bool test(Brick) const;

    /**
     * @brief Adds a component to the node next components list.
     * @param component Pointer to the component to be added.
     */
    void add(Component*);

    /**
     * @brief Saves the state of the component to an output stream.
     * @param os The output stream to save to.
     */
    virtual void save(ostream&) const;

    /**
     * @brief Gets the indexes of the child components in the collection.
     * @param collection The collection of components.
     * @return A vector of indexes.
     */
    vector<size_t> indexesInCollection(const vector<Component*>&) const;

    /**
     * @brief Destructs component 
     */
    virtual ~Component() {}

protected:
    /**
     * @brief Gets the components connected to this component.
     * @return A reference to the vector of components.
     */
    const std::vector<Component*>& getComps() const;

private:
    vector<Component*> comps;
};