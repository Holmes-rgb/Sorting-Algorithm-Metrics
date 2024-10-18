//
// Created by lukeholmes on 2/7/24.
//

#ifndef PROJECT2_AIRPORT_H
#define PROJECT2_AIRPORT_H

#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>

#include <vector>
using std::string;

class Airport {

private:
  int OBJECTID;
  std::string the_geom, Fac_Type, Field_Office, State_Name, County, City,
      Fac_Name, Fac_Use, Sectional, Fuel_Types;
  double Elevation, Unicom, Ctaf;
  bool Atc_Tower, Landing_Fee, Wind_Indic;

public:
  // Constructors
  Airport();
  Airport(int OBJECTID, std::string the_geom, std::string Fac_Type,
          std::string Field_Office, std::string State_Name, std::string County,
          std::string City, std::string Fac_Name, std::string Fac_Use,
          std::string Sectional, std::string Fuel_Types, double Elevation,
          double Unicom, double Ctaf, bool Atc_Tower, bool Landing_Fee,
          bool Wind_Indic);

  // Getters
  std::string getTheGeom();
  std::string getFacType();
  std::string getFieldOffice();
  std::string getStateName();
  std::string getCounty();
  std::string getCity();
  std::string getFacName();
  std::string getFacUse();
  std::string getSectional();
  std::string getFuelTypes();
  int getObjectid();
  double getElevation();
  double getUnicom();
  double getCtaf();
  bool isAtcTower();
  bool isLandingFee();
  bool isWindIndic();

  // Setters
  void setTheGeom(std::string theGeom);
  void setFacType(std::string facType);
  void setFieldOffice(std::string fieldOffice);
  void setStateName(std::string stateName);
  void setCounty(std::string county);
  void setCity(std::string city);
  void setFacName(std::string facName);
  void setFacUse(std::string facUse);
  void setSectional(std::string sectional);
  void setFuelTypes(std::string fuelTypes);
  void setObjectid(int objectid);
  void setElevation(double elevation);
  void setUnicom(double unicom);
  void setCtaf(double ctaf);
  void setAtcTower(bool atcTower);
  void setLandingFee(bool LandingFee);
  void setWindIndic(bool windIndic);
  /**
   * Overload stream insertion operator for pretty printing
   */
  friend std::ostream &operator<<(std::ostream &outs, const Airport &kObj) {
    outs << std::right                         // right align numbers
         << std::fixed                         // fix decimal in place
         << std::setprecision(4)               // four digits after decimal
         << std::setw(8) << kObj.getObjectid() // take up six characters
         << std::left                          // left align strings
         << "  " << std::setw(50) << kObj.getTheGeom() << std::setw(15)
         << kObj.getFacType() << std::setw(16) << kObj.getFieldOffice()
         << std::setw(18) << kObj.getStateName() << std::setw(23)
         << kObj.getCounty() << std::setw(27) << kObj.getCity() << std::setw(46)
         << kObj.getFacName() << std::setw(16) << kObj.getFacUse()
         << std::setw(12) << kObj.getElevation() << std::setw(20)
         << kObj.getSectional() << std::setw(19) << kObj.getFuelTypes()
         << std::setw(11) << kObj.isAtcTower() << std::setw(10)
         << kObj.getUnicom() << std::setw(10) << kObj.getCtaf() << std::setw(14)
         << kObj.isLandingFee() << std::setw(13) << kObj.isWindIndic();

    return outs;
  }

  // We don't need these right away, but we will for future projects
  // Compare objects using the unique identifying field (for Airport, rowId)

  /**
   * Overload < operator for object comparison
   */
  friend bool operator<(const Airport &lhs, const Airport &rhs) {
    return lhs.getObjectid() < rhs.getObjectid();
  }

  /**
   * Overload > operator for object comparison
   */
  friend bool operator>(const Airport &lhs, const Airport &rhs) {
    return lhs.getObjectid() > rhs.getObjectid();
  }

  /**
   * Overload <= operator for object comparison
   */
  friend bool operator<=(const Airport &lhs, const Airport &rhs) {
    return lhs.getObjectid() <= rhs.getObjectid();
  }

  /**
   * Overload >= operator for object comparison
   */
  friend bool operator>=(const Airport &lhs, const Airport &rhs) {
    return lhs.getObjectid() >= rhs.getObjectid();
  }

  /**
   * Overload == operator for object comparison
   */
  friend bool operator==(const Airport &lhs, const Airport &rhs) {
    return lhs.getObjectid() == rhs.getObjectid();
  }

  /**
   * Overload != operator for object comparison
   */
  friend bool operator!=(const Airport &lhs, const Airport &rhs) {
    return lhs.getObjectid() != rhs.getObjectid();
  }
// Global functions

/**
 * Read data into a vector from the downloaded CSV file.
 * Returns true if everything goes well; false otherwise.
 */
bool loadFromFile(std::string fn, std::vector<Airport> &objs);

/**
 * This verifies that all fields that should be set are set with
 * good values.
 */
void verifyAllFieldsSet(std::vector<Airport> &objs);

/**
 * Airport object tests.
 * To ensure constructors, getters, and setters all work properly.
 */
bool AirportTest();

};

#endif // PROJECT2_AIRPORT_H
