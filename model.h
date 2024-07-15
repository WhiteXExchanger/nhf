// model.h
#pragma once
#include <iostream>
#include "component.h"

/**
 * @class Model
 * @brief Represents a model containing multiple components.
 */
class Model {
public:
    /**
     * @brief Constructs a model and initializes the output stream.
     * @param os The output stream for the model.
     */
    Model(std::ostream& os);

    /**
     * @brief Loads the model from an input stream.
     * @param is The input stream to load from.
     */
    void load(std::istream& is);

    /**
     * @brief Saves the model to an output stream.
     * @param os The output stream to save to.
     */
    void save(std::ostream& os) const;

    /**
     * @brief Tests the model with the given brick.
     * @param brick The brick to test with.
     * @return True if the test is successful, otherwise false.
     */
    bool testModel(Brick brick) const;

    /**
     * @brief Simulates the model with a random set of bricks.
     * @param count The number of bricks to simulate with.
     */
    void simulate(size_t count) const;

    /**
     * @brief Destructor for the Model class.
     */
    ~Model();

protected:
    /**
     * @brief Draws the simulation of the conveyor belt.
     * @param status The result of the current simulation.
     * @param brick The brick which the simulation is drawn for.
     */
    void drawSimulation(bool status, Brick brick) const;

private:
    std::vector<Component*> allComps; ///< All components in the model.
    std::ostream& os; ///< Output stream for the model.
    Component alarm; ///< Alarm component, the root of all other components.
};