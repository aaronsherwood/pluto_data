//
//  main.cpp
//  pluto_data
//
//  Created by Aaron Sherwood on 9/14/13.
//  Copyright (c) 2013 Aaron Sherwood. All rights reserved.
//

#include <iostream>
#include <math.h>
#include <iomanip>


using namespace std;



class Pluto
{
public:
    void formation();
    void sweep_neighborhood_become_planet();
    void orbit();
    void temperature();
    void atmosphere();
    void materials();
    void ocean();
    
    
    bool solar_system;
    
    //size
    float radius(){ //meters
        return 1.15*pow(10,6);
    };
    float diameter(){ //meters
        return 2*3.14*radius();
    };
    float mass(){ //kilograms
        return 1.30900 * pow(10,22);
    };
    float gravity(){ //meters per second squared
        return (6.67384 * pow(10,-11))*mass()/(radius()*radius());
    };
    
    float lmap(float val, float inMin, float inMax, float outMin, float outMax)
    {
        return outMin + (outMax - outMin) * ((val - inMin) / (inMax - inMin));
    };
    
    //global temp and distance
    float current_distance;
    float current_temp;
    
    //min max distance
    float closest=4.44*pow(10,9);
    float farthest=7.38*pow(10,9);
    
    //materials
    float rock=.65;
    float ice=.35;
    enum {methane, nitrogen, carbon_monoxide, water};
    
    //constructor
    Pluto();
    
};


void Pluto::formation(){
    bool waves_of_energy;
    bool clouds_of_dust_and_gas;
    bool gravity;
    bool protoplanetary_disk;
    bool proto_star;
    
    cout<<"FORMATION////////////"<<endl;
    
    
    waves_of_energy=true;
    clouds_of_dust_and_gas=true;
    
    if (clouds_of_dust_and_gas && waves_of_energy){
        cout<<endl<<"waves of energy flowing through the universe press together clouds of dust and gas"<<endl;
        cout<<endl<<"gravity forms"<<endl;
        gravity=true;
        cout<<"(gravity="<<gravity<<")"<<endl;
    }
    
    if (gravity) {
        cout<<endl<<"because of gravity the materials start to spin and flatten out"<<endl;
        protoplanetary_disk=true;
        cout<<"(protoplanetary_disk="<<protoplanetary_disk<<")"<<endl;
    }
    
    if (gravity && protoplanetary_disk) {
        cout<<endl<<"the center collapes in on itself forming a proto star"<<endl;
        proto_star=true;
        cout<<"(proto_star="<<proto_star<<")"<<endl;
    }
    
    if (gravity&&protoplanetary_disk&&proto_star) {
        cout<<endl<<"gravity in outer protoplanetary_disk pulls solar wind blown gas and dust together forming pluto"<<endl;
        solar_system=true;
    }
    
    cout<<endl<<"(boo yah!)"<<endl;
    
    cout<<endl<<"********************"<<endl;
    
    
}

void Pluto::sweep_neighborhood_become_planet(){
    cout<<endl<<endl<<endl<<"ATTEMPTING TO SWEEP NEIGHBORHOOD CLEAN AND BECOME A PLANET///////////////"<<endl;
    if (solar_system) {
        if (gravity()>1.f)
            cout<<endl<<"yes, got mass, got gravity... got PLANET"<<endl;
        else
            cout<<endl<<"oops, not enough gravity, NOT A PLANET"<<endl<<"(pluto's gravitational acceleration is "<<gravity()<<" meters per second squared!)"<<endl;
    }
    
    cout<<endl<<"********************"<<endl;
}

void Pluto::orbit(){
    cout<<endl<<endl<<endl<<"ORBIT////////////////"<<endl;
    if (solar_system) {
        int pluto_year=248;
        cout<<endl<<"1 pluto year is equal to "<<pluto_year<<" earth years"<<endl;
        //seed for psuedo random earth year
        srand(time(NULL));
        int earth_year_divisions=rand() % 249;
        if (earth_year_divisions<125) {
            current_distance=lmap(earth_year_divisions, 0, 124, farthest, closest);
        };
        if (earth_year_divisions>124) {
            current_distance=lmap(earth_year_divisions, 125, 248, closest, farthest);
        };
        cout<<endl<<"during that time it travels in a range from:"<<endl<<closest/pow(10, 9)<<" billon kilometers from the sun at its closest"<<endl<<"to"<<endl<<farthest/pow(10, 9)<<" billion kilometers from the sun at its farthest"<<endl;
        cout<<endl<<"currently it is"<<endl<<current_distance/pow(10,9)<<" billion kilometers from the sun (distance psuedo random generated)"<<endl;
        
        int angle_difference_from_elliptic = 17;
        cout<<endl<<"pluto's orbital plane is at a "<<angle_difference_from_elliptic<<" degree angle compared with the rest of the solar system"<<endl;
    }
    
    cout<<endl<<"********************"<<endl;
    
}

void Pluto::temperature(){
    cout<<endl<<endl<<endl<<"TEMPERATURE//////////"<<endl;
    int low_temp=-400;
    int high_temp=-360;
    cout<<endl<<"it's really cold on pluto. depending on how far it is from the sun, pluto's temperature ranges from a low of:"<<endl<<low_temp<<" Fahrenheit"<<endl<<"to a high of:"<<endl<<high_temp<<" Fahrenheit"<<endl;
    current_temp=lmap(current_distance, farthest, closest, low_temp, high_temp);
    cout<<endl<<"based on pluto's current distance the temperature now is around:"<<endl<<current_temp<<" Fahrenheit"<<endl;
    
    cout<<endl<<"********************"<<endl;
}

void Pluto::atmosphere(){
    cout<<endl<<endl<<endl<<"ATMOSPHERE///////////"<<endl;
    
    
    
    cout<<endl<<"********************"<<endl;
    
}

void Pluto::materials(){
    cout<<endl<<endl<<endl<<"MATERIALS////////////"<<endl;
    
    cout<<endl<<"pluto's mass is "<<mass()<<" kilograms"<<endl;
    cout<<endl<<"pluto's radius is "<<radius()/1000<<" kilometers (about "<<floor((radius()/1000)/1.6)<<" miles)"<<endl;
    
    cout<<endl<<"********************"<<endl;
    
}

void Pluto::ocean(){
    cout<<endl<<endl<<endl<<"OCEAN////////////////"<<endl;
    
    
    
    cout<<endl<<"********************"<<endl;
    
}

Pluto::Pluto(){
}


int main(int argc, const char * argv[])
{
    Pluto pluto=Pluto();
    pluto.formation();
    pluto.sweep_neighborhood_become_planet();
    pluto.orbit();
    pluto.temperature();
    pluto.atmosphere();
    pluto.materials();
    pluto.ocean();
    return 0;
}

