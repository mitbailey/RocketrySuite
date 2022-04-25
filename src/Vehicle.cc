/**
 * @file Vehicle.cc
 * @author Mit Bailey (mitbailey99@gmail.com)
 * @brief
 * @version See Git tags for version information.
 * @date 2022.04.23
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "Vehicle.hcc"
#include "meb_print.h"

Vehicle::Vehicle()
{
    this->massEmpty = 0;
    // this->massLoaded = mass_loaded;
    this->crossSectionalArea = 0;
    this->dragCoefficient = 0;

    engine = new Engine();
    parachute = new Parachute();
}

Vehicle::~Vehicle()
{
    delete engine;
    delete parachute;
}

void Vehicle::UpdateVehicle(double mass_empty, double cross_sectional_area, double drag_coefficient)
{
    this->massEmpty = mass_empty;
    // this->massLoaded = mass_loaded;
    this->crossSectionalArea = cross_sectional_area;
    this->dragCoefficient = drag_coefficient;
}

void Vehicle::Print()
{
    bprintlf("VEHICLE~");
    bprintlf("Cross-sectional area: %.03f m^2", this->crossSectionalArea);
    bprintlf("Drag coefficient:     %.03f", this->dragCoefficient);
    bprintlf("Empty mass:           %.03f kg", this->massEmpty);
    bprintlf("Engine burn time:     %.03f s", this->engine->burnTime);
    bprintlf("Engine impulse:       %.03f", this->engine->impulse);
    bprintlf("Engine mass empty:    %.03f kg", this->engine->massEmpty);
    bprintlf("Engine mass loaded:   %.03f kg", this->engine->massLoaded);
    bprintlf("Deployment time:      %.03f s", this->parachute->deploymentTime);
    bprintlf("Parachute diameter:   %.03f m", this->parachute->diameter);
    bprintlf("Para. drag coeff.:    %.03f", this->parachute->dragCoefficient);
    bprintlf("Para. landing vel.:   %.03f m/s", this->parachute->landingVelocity);
}