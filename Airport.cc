#include "Airport.h"

// Constructor
Airport::Airport() {
  // Set default values to the fields
  OBJECTID = -1;
  the_geom = "NONE";
  Fac_Type = "NONE";
  Field_Office = "NONE";
  State_Name = "NONE";
  County = "NONE";
  City = "NONE";
  Fac_Name = "NONE";
  Fac_Use = "NONE";
  Sectional = "NONE";
  Fuel_Types = "NONE";
  Elevation = -1.0;
  Unicom = -1.0;
  Ctaf = -1.0;
  Atc_Tower = false;
  Landing_Fee = false;
  Wind_Indic = false;
}

Airport::Airport(int OBJECTID, std::string the_geom, std::string Fac_Type,
                 std::string Field_Office, std::string State_Name,
                 std::string County, std::string City, std::string Fac_Name,
                 std::string Fac_Use, std::string Sectional,
                 std::string Fuel_Types, double Elevation, double Unicom,
                 double Ctaf, bool Atc_Tower, bool Landing_Fee,
                 bool Wind_Indic) {
  this->OBJECTID = OBJECTID;
  this->the_geom = the_geom;
  this->Fac_Type = Fac_Type;
  this->Field_Office = Field_Office;
  this->State_Name = State_Name;
  this->County = County;
  this->City = City;
  this->Fac_Name = Fac_Name;
  this->Fac_Use = Fac_Use;
  this->Sectional = Sectional;
  this->Fuel_Types = Fuel_Types;
  this->Elevation = Elevation;
  this->Unicom = Unicom;
  this->Ctaf = Ctaf;
  this->Atc_Tower = Atc_Tower;
  this->Landing_Fee = Landing_Fee;
  this->Wind_Indic = Wind_Indic;
}

std::string Airport::getTheGeom()  { return the_geom; }
std::string Airport::getFacType()  { return Fac_Type; }
std::string Airport::getFieldOffice()  { return Field_Office; }
std::string Airport::getStateName()  { return State_Name; }
std::string Airport::getCounty()  { return County; }
std::string Airport::getCity()  { return City; }
std::string Airport::getFacName()  { return Fac_Name; }
std::string Airport::getFacUse()  { return Fac_Use; }
std::string Airport::getSectional()  { return Sectional; }
std::string Airport::getFuelTypes()  { return Fuel_Types; }
int Airport::getObjectid()  { return OBJECTID; }
double Airport::getElevation()  { return Elevation; }
double Airport::getUnicom()  { return Unicom; }
double Airport::getCtaf()  { return Ctaf; }
bool Airport::isAtcTower()  { return Atc_Tower; }
bool Airport::isLandingFee()  { return Landing_Fee; }
bool Airport::isWindIndic()  { return Wind_Indic; }

void Airport::setTheGeom(std::string theGeom) { this->the_geom = theGeom; }
void Airport::setFacType(std::string facType) { this->Fac_Type = facType; }
void Airport::setFieldOffice(std::string fieldOffice) { this->Field_Office = fieldOffice;}
void Airport::setStateName(std::string stateName) { this->State_Name = stateName; }
void Airport::setCounty(std::string county) { this->County = county; }
void Airport::setCity(std::string city) { this->City = city; }
void Airport::setFacName(std::string facName) { this->Fac_Name = facName; }
void Airport::setFacUse(std::string facUse) { this->Fac_Use = facUse; }
void Airport::setSectional(std::string sectional) { this->Sectional = sectional; }
void Airport::setFuelTypes(std::string fuelTypes) { this->Fuel_Types = fuelTypes; }
void Airport::setObjectid(int objectid) { this->OBJECTID = objectid; }
void Airport::setElevation(double elevation) { this->Elevation = elevation; }
void Airport::setUnicom(double unicom) { this->Unicom = unicom; }
void Airport::setCtaf(double ctaf) { this->Ctaf = ctaf; }
void Airport::setAtcTower(bool atcTower) { this->Atc_Tower = atcTower; }
void Airport::setLandingFee(bool LandingFee) { this->Landing_Fee = LandingFee; }
void Airport::setWindIndic(bool windIndic) { this->Wind_Indic = windIndic; }
