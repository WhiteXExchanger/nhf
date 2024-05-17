// model.cpp

#include "model.h"
#include "component.cpp"

bool Model::add(EComponent ec, size_t i) {
    bool isSuccess = alarm.insert(EComponent::AndG, i, alarm.max()+1); //throw runtime_error("Nincs ilyen ID-vel adat!");
    alarm.write(os);
    os << endl;
    return isSuccess;
}

bool Model::remove(size_t i) {
    // megkeressük a törölni kívánt elemet, majd töröljük, ha nincs ilyen elem false-ot ad vissza
    alarm.remove(i, new Component());
    return false;
}

bool Model::modify(EComponent ec, size_t i) {
    // megkeressük a módosítandó elemet, 
    // lemásoljuk a belekötött komponenseket
    // majd töröljük a fából
    // ha sikertelen, vagy nincs ilyen elem false-ot ad
    return false;
}

bool Model::testModel(Brick t) {
    return alarm.test(t);
}
void Model::simulate(size_t n) {
    //Brick t[10];
}
void Model::drawSimulation() {

}
void Model::drawComponentTree() {
    alarm.write(os);
}