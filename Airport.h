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
};

// Global functions

/**
 * Read data into a vector from the downloaded CSV file.
 * Returns true if everything goes well; false otherwise.
 */
bool loadFromFile(std::string fn, std::vector<Airport> &objs) {
  std::ifstream fin;
  fin.open(fn);

  if (!fin) {
    // Bad file / could not open
    return false;
  }

  // Opened file OK

  // Get rid of the header line: read it and throw it away
  std::string header = "";
  getline(fin, header);

  // Declare variables to be used inside the while loop
  int OBJECTID;
  std::string the_geom, Fac_Type, Field_Office, State_Name, County, City,
      Fac_Name, Fac_Use, Sectional, Fuel_Types;
  double Elevation, Unicom, Ctaf;
  bool Atc_Tower, Landing_Fee, Wind_Indic;
  char comma, quote; // This willfin >> comma; come in handy.

  // Read in data while the file is still good
  // and we haven't yet reached the end of file (EOF).
  int counter = 1;

  // was {while (fin && fin.peek() != EOF)}
  while (fin && fin.peek() != EOF) {
    // We initialize variables to sentinel values --
    // values we *know* will not appear in our data.
    // If any object fields have one of these values, we
    // *know* it was incorrectly set.
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
    comma = ',';
    quote = '"';

    // Your input data file will be different. You will have different
    // fields, different values, etc. What follows below may be helpful
    // but you'll need to modify to suit your data.

    // Using the >> (extraction) operator ...
    fin >> OBJECTID; // Expects an int; reads an int.
    if (OBJECTID != counter) {
      std::cout << OBJECTID << " != " << counter << std::endl;
      return false;
    }
    // These read a string; comma is delimiter and is discarded.
    fin >> comma;
    getline(fin, the_geom, ',');
    getline(fin, Fac_Type, ',');
    getline(fin, Field_Office, ',');
    getline(fin, State_Name, ',');
    if (fin.peek() != '"') {
      getline(fin, County, ',');
    } else {
      fin >> quote;
      getline(fin, County, '"');
      fin >> comma;
    }

    if (fin.peek() != '"') {
      getline(fin, City, ',');
    } else {
      fin >> quote;
      getline(fin, City, '"');
      fin >> comma;
    }

    if (fin.peek() != '"') {
      getline(fin, Fac_Name, ',');
    } else {
      fin >> quote;
      getline(fin, Fac_Name, '"');
      fin >> comma;
    }
    getline(fin, Fac_Use, ',');

    if (fin.peek() != comma) {
      if (fin.peek() == 'E') {
        fin.get();
      } else {
        fin >> Elevation;
      }
    }
    fin >> comma;

    if (fin.peek() != comma) {
      getline(fin, Sectional, ',');
    } else {
      fin >> comma;
    }

    if (fin.peek() != comma) {
      getline(fin, Fuel_Types, ',');
    } else {
      fin >> comma;
    }

    // SS-SR
    if (fin.peek() != comma) {
      if (fin.peek() == 'Y') {
        Atc_Tower = true;
      }
      while (fin.peek() != comma) {
        fin.get();
      }
    }
    fin >> comma;

    if (fin.peek() != comma) {
      if (fin.peek() == 'N') {
        fin.get();
      } else if (fin.peek() == 'Y') {
        fin.get();
      } else {
        fin >> Unicom;
      }
    }
    fin >> comma;

    if (fin.peek() != comma) {
      if (fin.peek() == 'N') {
        fin.get();
      } else if (fin.peek() == 'y') {
        fin.get();
      } else {
        fin >> Ctaf;
      }
    }
    fin >> comma;

    if (fin.peek() != comma) {
      if (fin.get() == 'Y') {
        Landing_Fee = true;
      }
      if (fin.peek() != ',') {
        fin.get();
      }
    }
    fin >> comma;

    if (fin.peek() != '\r' && fin.peek() != '\n') {
      if (fin.get() == 'Y') {
        Wind_Indic = true;
      }
    }

    Airport airport(OBJECTID, the_geom, Fac_Type, Field_Office, State_Name,
                    County, City, Fac_Name, Fac_Use, Sectional, Fuel_Types,
                    Elevation, Unicom, Ctaf, Atc_Tower, Landing_Fee,
                    Wind_Indic);
    objs.push_back(airport);
    counter += 1;
  }
  fin.close();
  return true;
}

/**
 * This verifies that all fields that should be set are set with
 * good values.
 */
void verifyAllFieldsSet(std::vector<Airport> &objs) {
  int i = 0;
  for (Airport &airport : objs) {
    // Row ID should always = i + 1
    if (airport.getObjectid() != i + 1) {
      std::cout << "Bad value for row ID at record " << i << std::endl;
    }
    std::string FacName = airport.getFacName();
    if (FacName.compare("NONE") == 0) {
      std::cout << "Bad value for Airport name at record " << i << std::endl;
    }
    i += 1;
  }
}

/**
 * Airport object tests.
 * To ensure constructors, getters, and setters all work properly.
 */
bool AirportTest() {
  bool passed = true;
  Airport testObject = Airport();
  // Test setters and getters
  testObject.setObjectid(1);
  if (testObject.getObjectid() != 1) {
    std::cout << "FAILED OBJECTID test" << std::endl;
    passed = false;
  }

  testObject.setTheGeom("Fred");
  if (testObject.getTheGeom() != "Fred") {
    std::cout << "FAILED the-geom, test" << std::endl;
    passed = false;
  }
  testObject.setFacType("PU");
  if (testObject.getFacType() != "PU") {
    std::cout << "FAILED FacType test" << std::endl;
    passed = false;
  }
  testObject.setFieldOffice("LAX");
  if (testObject.getFieldOffice() != "LAX") {
    std::cout << "FAILED FieldOffice test" << std::endl;
    passed = false;
  }
  testObject.setStateName("Vermont");
  if (testObject.getStateName() != "Vermont") {
    std::cout << "FAILED StateName test" << std::endl;
    passed = false;
  }
  testObject.setCounty("Chittenden");
  if (testObject.getCounty() != "Chittenden") {
    std::cout << "FAILED StateName test" << std::endl;
    passed = false;
  }
  testObject.setCity("Burlington");
  if (testObject.getCity() != "Burlington") {
    std::cout << "FAILED City test" << std::endl;
    passed = false;
  }
  testObject.setFacName("JFK");
  if (testObject.getFacName() != "JFK") {
    std::cout << "FAILED AirportName test" << std::endl;
    passed = false;
  }
  testObject.setFacUse("PU");
  if (testObject.getFacUse() != "PU") {
    std::cout << "FAILED FacUse test" << std::endl;
    passed = false;
  }
  testObject.setElevation(0.0);
  if (testObject.getElevation() != 0.0) {
    std::cout << "FAILED elevation test" << std::endl;
    passed = false;
  }
  testObject.setSectional("MONTREAL");
  if (testObject.getSectional() != "MONTREAL") {
    std::cout << "FAILED Sectional test" << std::endl;
    passed = false;
  }
  testObject.setFuelTypes("Jet-A");
  if (testObject.getFuelTypes() != "Jet-A") {
    std::cout << "FAILED FuelTypes test" << std::endl;
    passed = false;
  }
  testObject.setAtcTower(true);
  if (!testObject.isAtcTower()) {
    std::cout << "FAILED AtcTower test" << std::endl;
    passed = false;
  }
  testObject.setUnicom(123.45);
  if (testObject.getUnicom() != 123.45) {
    std::cout << "FAILED Unicom test" << std::endl;
    passed = false;
  }
  testObject.setCtaf(123.45);
  if (testObject.getCtaf() != 123.45) {
    std::cout << "FAILED Ctaf test" << std::endl;
    passed = false;
  }
  testObject.setLandingFee(true);
  if (!testObject.isLandingFee()) {
    std::cout << "FAILED LandingFee test" << std::endl;
    passed = false;
  }
  testObject.setWindIndic(true);
  if (!testObject.isWindIndic()) {
    std::cout << "FAILED WindIndic test" << std::endl;
    passed = false;
  }
  // Test initialization (and getters)

  Airport testObject2 = Airport(1, "Fred", "PU", "LAX", "Vermont", "Chittenden",
                                "Burlington", "JFK", "PU", "MONTREAL", "Jet-A",
                                0.0, 123.45, 678.90, true, true, true);
  if (testObject2.getObjectid() != 1 || testObject2.getTheGeom() != "Fred" ||
      testObject2.getFacType() != "PU" ||
      testObject2.getFieldOffice() != "LAX" ||
      testObject2.getStateName() != "Vermont" ||
      testObject2.getCounty() != "Chittenden" ||
      testObject2.getCity() != "Burlington" ||
      testObject2.getFacName() != "JFK" || testObject2.getFacUse() != "PU" ||
      testObject2.getElevation() != 0.0 ||
      testObject2.getSectional() != "MONTREAL" ||
      testObject2.getFuelTypes() != "Jet-A" || !testObject2.isAtcTower() ||
      testObject2.getUnicom() != 123.45 || testObject2.getCtaf() != 678.90 ||
      !testObject2.isLandingFee() || !testObject2.isWindIndic()) {
    std::cout << "FAILED non-default constructor test" << std::endl;
    passed = false;
  }
  return passed;
}

#endif // PROJECT2_AIRPORT_H
